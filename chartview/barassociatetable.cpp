#include <chartview/barassociatetable.h>

BarAssociateTable::BarAssociateTable(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QDialog(parent),mTableView(tableview),mChartView(chartview)
{
    mCurrentSeries = nullptr;
    mAssociateMode = AssociateMode::RowMode;
    mLegend = new ChartShowLegend;
    mTip = new ChartShowTip;
    mTip->setChart(mChartView->chart());
    mTableModel = static_cast<TableViewModel*>(mTableView->model());

    mMode = new AssociateBarMode(mTableModel);
    mSeries = new AssociateBarSeries;
    mAxis = new AssociateBarAxis;

    mOkBtn = new QPushButton(tr("关联"));
    QHBoxLayout * lay1 = new QHBoxLayout;
    lay1->addStretch();
    lay1->addWidget(mOkBtn);

    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(mMode);
    lay->addWidget(mSeries);
    lay->addWidget(mAxis);
    lay->addLayout(lay1);
    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/associatetable.png"));
    resize(QSize(800,400));
    setLayout(lay);
    initConnections();
}

void BarAssociateTable::initConnections()
{
    connect(mOkBtn,&QPushButton::clicked,this,&BarAssociateTable::onOkBtn);

    connect(mMode,&AssociateBarMode::modeChanged, // 如果选择区域模式,set的颜色自动生成不允许设置
            mSeries,&AssociateBarSeries::setBarColorEnabled);

    connect(this,&BarAssociateTable::tableChanged,this,[=]{
        disconnect(mOkBtn,&QPushButton::clicked,this,&BarAssociateTable::onOkBtn);
        mTableModel = static_cast<TableViewModel*>(mTableView->model());
        connect(mOkBtn,&QPushButton::clicked,this,&BarAssociateTable::onOkBtn);
        mMode->adjustRange();
    });

    connect(this,&BarAssociateTable::seriesColorChanged,this,&BarAssociateTable::onSeriesColorChanged);
}

void BarAssociateTable::onSeriesColorChanged(QBarSeries*series,QColor color, int flag)
{
    if(series == mCurrentSeries) // 可能series来自初始化方向的
    {
        switch (mAssociateMode) {
                case 0: mTableModel->addRowMapping(flag,color);break;
                case 1:mTableModel->addColMapping(flag,color);break;
                case 2:
                        break;
                case 3:
                        break;
        }
    }
}

void BarAssociateTable::onOkBtn()
{
    //和XY折线图散点图不同,这里不允许多重添加曲线,否则颜色的反向映射会出问题
    mChartView->chart()->removeAllSeries();
    if (mMode->isRegionMode()) regionMapping();
    else rcMapping();
    mLegend->mapping(mChartView->chart());
    emit associateCompeleted();
    accept();
}

QBarSeries * BarAssociateTable::createSeries()
{ // 4种模式共用
    QBarSeries * series = new QBarSeries;
    series->setBarWidth(mSeries->barwidth());
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    series->setName("bar curve");
    mCurrentSeries = series;
    return series;
}

QBarSet * BarAssociateTable::createSet()
{ // 只用于行列模式,区域是自动生成的无需手动创建
    int row,col;
    QVector<QVariant> data;
    if (mMode->isRowMode()) { // 行模式,水平轴就是列名
        row = mMode->associateRow(); // 表格的第row行用来绘图
        data = mTableModel->rowData(row);
        //qDebug()<<"row data = "<<data;
        mTableModel->addRowMapping(row,mSeries->barcolor());
        mAssociateMode = AssociateMode::RowMode;
        emit modeChanged(AssociateMode::RowMode,row);
    }
    else {// 列模式,水平轴就是行名
        col = mMode->associateCol();
        data = mTableModel->colData(col);
        //qDebug()<<"col data = "<<data;
        mTableModel->addColMapping(col,mSeries->barcolor());
        mAssociateMode = AssociateMode::ColMode;
        emit modeChanged(AssociateMode::ColMode,col);
    }

    QBarSet * set = new QBarSet("");
    if (mMode->isRowMode())
        set->setLabel(QString("row %1").arg(row+1));
    else set->setLabel(QString("col %1").arg(col+1));
    set->setColor(mSeries->barcolor());
    set->setBorderColor(mSeries->barcolor());
    set->setLabelColor(mSeries->barcolor());
    for(int x = 0; x <data.count(); ++x) {
        if (data[x].isValid()) set->append(data[x].toDouble());
    }
    return set;
}

void BarAssociateTable::rcMapping()
{
    auto series = createSeries();
    auto set = createSet();

    if (set->count() == 0) { // 可能是空白行和列数据无效直接返回
        accept();
        return;
    }

    series->append(set);
    mChartView->chart()->addSeries(series);

    //mSeriesXYColumn[series] = qMakePair<int,int>(col,-1);

    setAxisX(series,rcCategories());
    setAxisY(series);
    mTip->mapping(series);
}

void BarAssociateTable::createColRegionMapping(QBarSeries*series)
{
    auto params = mMode->associateColParams();
    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(params.firstColumn);
    mapper->setLastBarSetColumn(params.lastColumn);
    mapper->setFirstRow(params.startRow);
    mapper->setRowCount(params.rowCount);
    mapper->setSeries(series);
    mapper->setModel(mTableModel); // series自动生成好barset
    mChartView->chart()->addSeries(series); // 图表要先添加曲线,否则下方colorlist得到的全是黑色

    auto categorycolor = getBarSetParams(series);

    mTableModel->addColRegionMapping(params.firstColumn,params.lastColumn,
                                params.startRow,params.rowCount,categorycolor.colors);
    setAxisX(series,categorycolor.categories);
    setAxisY(series);

    // 告知区域的起始列,结合切换序列的索引,就可以得到那条序列所处的列数
    // 例如起始列3,区域有4列,也就是3,4,5,6这4列; 但是切换序列的索引只会有0,1,2,3
    // 那么序列3其实对应的就是第6列,所以切换序列根据index+firstColumn(3)即可得到当前序列的实际列位置
    mAssociateMode = AssociateMode::ColRegionMode;
    emit modeChanged(AssociateMode::ColRegionMode,params.firstColumn);
}

void BarAssociateTable::createRowRegionMapping(QBarSeries*series)
{
    auto params = mMode->associateRowParams();
    QHBarModelMapper *mapper = new QHBarModelMapper(this);
    mapper->setFirstBarSetRow(params.firstRow);
    mapper->setLastBarSetRow(params.lastRow);
    mapper->setFirstColumn(params.startColumn);
    mapper->setColumnCount(params.columnCount);
    mapper->setSeries(series);
    mapper->setModel(mTableModel); // series自动生成好barset
    mChartView->chart()->addSeries(series); // 图表要先添加曲线,否则下方colorlist得到的全是黑色

    auto categorycolor = getBarSetParams(series);

    mTableModel->addRowRegionMapping(params.firstRow,params.lastRow,
                                params.startColumn,params.columnCount,categorycolor.colors);
    setAxisX(series,categorycolor.categories);
    setAxisY(series);

    // 告知区域的起始行,结合切换序列的索引,就可以得到那条序列所处的行数
    // 例如起始行3,区域有4行,也就是3,4,5,6这4行; 但是切换序列的索引只会有0,1,2,3
    // 那么序列3其实对应的就是第6行,所以切换序列根据index+firstRow(3)即可得到当前序列的实际行位置
    mAssociateMode = AssociateMode::RowRegionMode;
    emit modeChanged(AssociateMode::RowRegionMode,params.firstRow);
}

BarAssociateTable::CategoryColor BarAssociateTable::getBarSetParams(QBarSeries*series) const
{
    auto barsets = series->barSets();

    QStringList categories;
    QColorList colorlist;
    for (int i = 0; i < barsets.count(); ++i) {
        barsets.at(i)->setBorderColor(Qt::black);
        barsets.at(i)->setLabelFont(QFont("Times New Roman",12));
        barsets.at(i)->setLabelColor(barsets.at(i)->color());
        //barsets.at(i)->setLabel("col "); // 自动生成的,不能设置会导致异常
        //barsets.at(i)->setColor(Qt::red); // 可以设置,但是不要设置,用自动生成的
        //qDebug()<<barsets.at(i)->sum();
        categories.append(barsets.at(i)->label());
        colorlist.append(barsets.at(i)->color());//用填充色不用文字颜色
        // color=brush.color ≠ pen.color=labelcolor=labelbrush.color ≠bordercolor
//        qDebug()<<barsets.at(i)->color()<<barsets.at(i)->brush().color()<<barsets.at(i)->pen().color()<<
//                  barsets.at(i)->labelColor()<<barsets.at(i)->labelBrush().color();
    }

    return CategoryColor{categories,colorlist};
}

void BarAssociateTable::regionMapping()
{
    auto series = createSeries();

    if (mMode->isRowRegionMode())
        createRowRegionMapping(series);
    else
        createColRegionMapping(series);

    mTip->mapping(series);
}

void BarAssociateTable::setAxisX(QBarSeries *series,const QStringList& categories)
{
    QBarCategoryAxis * axisX = new QBarCategoryAxis;
    axisX->append(categories);
    if (mChartView->chart()->axisX())
        mChartView->chart()->removeAxis(mChartView->chart()->axisX());
    mChartView->chart()->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
}

void BarAssociateTable::setAxisY(QBarSeries *series)
{
    QValueAxis * valueAxis;
    QLogValueAxis * logAxis;
    QAbstractAxis * axis = mChartView->chart()->axisY();
    bool isValueAxis = mAxis->isValueAxis();
    if (axis) mChartView->chart()->removeAxis(axis); // 首次设置还没有坐标轴

    if (isValueAxis)
    {
        valueAxis = new QValueAxis;
        mChartView->chart()->addAxis(valueAxis,Qt::AlignLeft);
        series->attachAxis(valueAxis);
    }
    else {
        logAxis = new QLogValueAxis;
        logAxis->setBase(2.); //默认
        auto base = mAxis->base();
        if (base != 1.0) logAxis->setBase(base);
        mChartView->chart()->addAxis(logAxis,Qt::AlignLeft);
        series->attachAxis(logAxis);
    }
}

QStringList BarAssociateTable::rcCategories() const
{
    QStringList categories; // 用来设置水平轴的label
    if (mMode->isRowMode())
    { // 行模式,轴应该是列名
        foreach(QString label,mTableModel->horizontalHeaderLabels())
        {// 如果列名有自己的标题就用该标题,如果是默认的1,2,3..则加上前缀col
            if (label.toInt()) categories.append("col "+label);
            else categories.append(label);
        }
    }
    else
    {
        foreach(QString label,mTableModel->verticalHeaderLabels())
        {
            if (label.toInt()) categories.append("row "+label);
            else categories.append(label);
        }
    }
    //qDebug()<<"cate = "<<categories;
    return categories;
}
