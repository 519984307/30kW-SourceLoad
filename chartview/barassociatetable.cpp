#include <chartview/barassociatetable.h>

BarAssociateTable::BarAssociateTable(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QDialog(parent),mTableView(tableview),mChartView(chartview)
{
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

    connect(this,&BarAssociateTable::tableChanged,this,[=]{
        disconnect(mOkBtn,&QPushButton::clicked,this,&BarAssociateTable::onOkBtn);
        mTableModel = static_cast<TableViewModel*>(mTableView->model());
        connect(mOkBtn,&QPushButton::clicked,this,&BarAssociateTable::onOkBtn);
        mMode->adjustRange();
    });

//    connect(this,static_cast<void (BarAssociateTable::*)(QScatterSeries*)>(&BarAssociateTable::seriesColorChanged),
//            this,[=](QBarSeries*series){
//            if (mSeriesXYColumn.keys().contains(series))
//            {
//                auto cols = mSeriesXYColumn[series];
//                mTableModel->addColMapping(cols.first,series->color());
//                if (cols.second < 0) return;
//                mTableModel->addColMapping(cols.second,series->color());
//            }
//    });
//    connect(this,static_cast<void (ScatterAssociateTable::*)(QBarSeries*)>(&BarAssociateTable::seriesRemoved),
//            this,[=](QBarSeries*series){
//            if (mSeriesXYColumn.keys().contains(series))
//            {
//                auto cols = mSeriesXYColumn[series];
//                mTableModel->addColMapping(cols.first,Qt::white);
//                if (cols.second < 0) return;
//                mTableModel->addColMapping(cols.second,Qt::white);
//                mSeriesXYColumn.remove(series);
//            }
//    });
}

void BarAssociateTable::onOkBtn()
{
    if (mMode->isRectMode()) rectMapping();
    else nonRegionMapping();
    mLegend->mapping(mChartView->chart());
    emit associateCompeleted();
    accept();
}

void BarAssociateTable::nonRegionMapping()
{
    int row,col;
    QVector<QVariant> data;
    if (mMode->isRowMode()) { // 行模式,水平轴就是列名
        row = mMode->associateRow(); // 表格的第row行用来绘图
        data = mTableModel->rowData(row);
        //qDebug()<<"row data = "<<data;
        mTableModel->addRowMapping(row,mSeries->barcolor());
    }
    else {// 列模式,水平轴就是行名
        col = mMode->associateCol();
        data = mTableModel->colData(col);
        //qDebug()<<"col data = "<<data;
        mTableModel->addColMapping(col,mSeries->barcolor());
    }

    QBarSeries * series = new QBarSeries;
    series->setBarWidth(mSeries->barwidth());
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    series->setName("bar curve");

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

    if (set->count() == 0) { // 可能是空白行和列数据无效直接返回
        accept();
        return;
    }

    series->append(set);
    mChartView->chart()->addSeries(series);

    //mSeriesXYColumn[series] = qMakePair<int,int>(col,-1);

    setAxisX(series,nonRegionCategories());
    setAxisY(series);
    mTip->mapping(series);
}

void BarAssociateTable::rectMapping()
{
    auto mappedParams = mMode->associateRect();
    QBarSeries *series = new QBarSeries;
    series->setBarWidth(mSeries->barwidth());
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    series->setName("bar curve");

    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(mappedParams.firstColumn);
    mapper->setLastBarSetColumn(mappedParams.lastColumn);
    mapper->setFirstRow(mappedParams.firstRow);
    mapper->setRowCount(mappedParams.rowCount);
    mapper->setSeries(series);
    mapper->setModel(mTableModel); // 映射就已经做好了series的basset,无需手动获取model的数据并创建barset
    mChartView->chart()->addSeries(series); // 图表要先添加曲线,否则下方colorlist得到的全是黑色

    auto barsets = series->barSets();

    QStringList categories;
    QList<QColor> colorlist;
    for (int i = 0; i < barsets.count(); ++i) {
        auto label = barsets.at(i)->label();
        if (label.toInt())
        {
            categories.append("col "+label);// 水平轴名称
            //barsets.at(i)->setLabel("col "+label); // 图例名称,这里会导致异常不设置了,应该是底层原因
        }
        else categories.append(label);
        colorlist.append(barsets.at(i)->color());//用填充色不用文字颜色
        // color=brush.color ≠ pen.color=labelcolor=labelbrush.color ≠bordercolor
//        qDebug()<<barsets.at(i)->color()<<barsets.at(i)->brush().color()<<barsets.at(i)->pen().color()<<
//                  barsets.at(i)->labelColor()<<barsets.at(i)->labelBrush().color();
    }
    mTableModel->addRectMapping(mappedParams.firstColumn,mappedParams.lastColumn,
                                mappedParams.firstRow,mappedParams.rowCount,colorlist);
    setAxisX(series,categories);
    setAxisY(series);
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

QStringList BarAssociateTable::nonRegionCategories() const
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
