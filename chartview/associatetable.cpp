#include <chartview/associatetable.h>

AssociateTable::AssociateTable(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QDialog(parent),mTableView(tableview),mChartView(chartview)
{
    mLegend = new ChartShowLegend;
    mTip = new ChartShowTip;
    mTip->setChart(mChartView->chart());
    mTableModel = static_cast<TableViewModel*>(mTableView->model());
    QVBoxLayout * lay = new QVBoxLayout(this);

    mMode = new AssociateMode(mTableView,mChartView);
    mSeries = new AssociateSeries;
    mAxis = new AssociateAxis(mTableView,mChartView);

    mOkBtn = new QPushButton(tr("关联"));
    QHBoxLayout * lay1 = new QHBoxLayout;
    lay1->addStretch();
    lay1->addWidget(mOkBtn);

    lay->addWidget(mMode);
    lay->addWidget(mSeries);
    lay->addWidget(mAxis);
    lay->addLayout(lay1);

    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/associatetable.png"));
    resize(QSize(800,300));

    initConnections();
}

void AssociateTable::initConnections()
{
    connect(mMode,&AssociateMode::changeMode,mAxis,&AssociateAxis::setHorizontalEnabled);
    connect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);

    connect(this,&AssociateTable::tableChanged,this,[=]{ // 导入文件后表格model发生了更新
        disconnect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);
        mTableModel = static_cast<TableViewModel*>(mTableView->model()); //更新model再连
        connect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);

        mMode->adjustRange(); //调整spinbox和表格列数一致
    });

    connect(this,static_cast<void (AssociateTable::*)(QLineSeries*)>(&AssociateTable::seriesColorChanged),
            this,[=](QLineSeries*series){
            if (mSeriesXYColumn.keys().contains(series))
            { // 说明修改的是这里创建出来的series,有可能是linechart.cpp初始化创建的那3个
                auto cols = mSeriesXYColumn[series];
                mTableModel->addColMapping(cols.first,series->color());
                if (cols.second < 0) return; // 说明是单列映射
                mTableModel->addColMapping(cols.second,series->color());
            }
    });
    connect(this,static_cast<void (AssociateTable::*)(QLineSeries*)>(&AssociateTable::seriesRemoved),
            this,[=](QLineSeries*series){
            if (mSeriesXYColumn.keys().contains(series))
            {
                auto cols = mSeriesXYColumn[series];
                mTableModel->addColMapping(cols.first,Qt::white);
                if (cols.second < 0) return; // 说明是单列映射
                mTableModel->addColMapping(cols.second,Qt::white);
                mSeriesXYColumn.remove(series);
            }
    });
}

void AssociateTable::onOkBtn()
{
    bool isSingle = mMode->isSingle();
    if (isSingle) singleMapping();
    else doubleMapping();
    mLegend->mapping(mChartView->chart());

    emit associateCompeleted(); // 通知曲线工具栏进行界面更新
    accept();
}

void AssociateTable::singleMapping()
{
    int col = mMode->singleCol();

    QLineSeries * series = new QLineSeries;
    series->setPointLabelsFormat("(@xPoint, @yPoint)"); //加个()
    QPen pen = series->pen();
    pen.setWidth(mSeries->linewidth()); // 提供给用户选择
    pen.setColor(mSeries->linecolor());
    series->setPen(pen);

    mTableModel->addColMapping(col,mSeries->linecolor());
    mSeriesXYColumn[series] = qMakePair<int,int>(col,-1);

    QString name = mTableModel->horizontalHeaderLabels()[col];
    if (name.toInt()) series->setName("col"+name); // 如果是数字1,2,3..就加上前缀
    else series->setName(name); //否则列名称作为序列名字

    QVector<QVariant> data = mTableModel->colData(col); // 这列的数据
    QPointF point;
    for(int x = 0; x <data.count(); ++x){
        point.setX((qreal)x);point.setY(data[x].toDouble());
        *series  << point;
    }

    //qDebug()<<mAxis->axisType()<<mAxis->axisBase();
    mChartView->chart()->addSeries(series);
    //setHorizontalAxis(series); // 单映射是自动生成线性坐标轴的
    QValueAxis * axisX = new QValueAxis; // 对数/时间坐标轴没有意义,此时选择水平轴使能禁止
    mChartView->chart()->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    setVerticalAxis(series);

    mTip->mapping(series);
}

void AssociateTable::doubleMapping()
{
    QPoint point = mMode->doubleCols();
    int xCol = point.x();
    int yCol = point.y();

    QLineSeries * series = new QLineSeries;
    series->setPointLabelsFormat("(@xPoint, @yPoint)"); //加个()
    QPen pen = series->pen();
    pen.setWidth(mSeries->linewidth()); // 提供给用户选择
    pen.setColor(mSeries->linecolor());
    series->setPen(pen);

    mTableModel->addDoubleColMapping(series,xCol,yCol); // 曲线先设置颜色再关联表格否则不体现
    mSeriesXYColumn[series] = qMakePair<int,int>(xCol,yCol);

    QString name1 = mTableModel->horizontalHeaderLabels()[xCol];
    QString name2 = mTableModel->horizontalHeaderLabels()[yCol];
    if (name1.toInt()) name1 = "col"+name1;
    if (name2.toInt()) name2 = "col"+name2;
    series->setName(name1+"-"+name2);

    //chart->removeAllSeries();
    mChartView->chart()->addSeries(series);
    setHorizontalAxis(series);
    setVerticalAxis(series);
    mTip->mapping(series);
}

void AssociateTable::setHorizontalAxis(QLineSeries *series)
{
    QValueAxis * valueAxisX;
    QDateTimeAxis * timeAxisX;
    QLogValueAxis * logAxisX;
    auto axisX = mChartView->chart()->axisX();
    if (axisX) mChartView->chart()->removeAxis(axisX); // 首次设置还没有坐标轴
    switch (mAxis->axisType().x()) {
        case AssociateAxis::Value:
                valueAxisX = new QValueAxis;
                mChartView->chart()->addAxis(valueAxisX,Qt::AlignBottom);
                series->attachAxis(valueAxisX);
                //qDebug()<<"hor value";
                break;
         case AssociateAxis::Time:
                timeAxisX = new QDateTimeAxis;
                mChartView->chart()->addAxis(timeAxisX,Qt::AlignBottom);
                series->attachAxis(timeAxisX);
                //qDebug()<<"hor time";
                break;
          case AssociateAxis::Log:
                logAxisX = new QLogValueAxis;
                logAxisX->setBase(2.); //默认
                auto base = mAxis->axisBase().x();
                if (base != 1.0) logAxisX->setBase(base);
                mChartView->chart()->addAxis(logAxisX,Qt::AlignBottom);
                series->attachAxis(logAxisX);
                //qDebug()<<"hor log base = "<<logAxisX->base();
                break;
    }
}

void AssociateTable::setVerticalAxis(QLineSeries *series)
{
    QValueAxis * valueAxisY;
    QLogValueAxis * logAxisY;
    auto axisY = mChartView->chart()->axisY();
    if (axisY) mChartView->chart()->removeAxis(axisY);
    switch (mAxis->axisType().y()) {
        case AssociateAxis::Value:
                valueAxisY = new QValueAxis;
                mChartView->chart()->addAxis(valueAxisY,Qt::AlignLeft);
                series->attachAxis(valueAxisY);
                //qDebug()<<"ver value";
                break;
          case AssociateAxis::Log:
                logAxisY = new QLogValueAxis;
                logAxisY->setBase(2.);
                auto base = mAxis->axisBase().y();
                if (base != 1.0) logAxisY->setBase(base);
                mChartView->chart()->addAxis(logAxisY,Qt::AlignLeft);
                series->attachAxis(logAxisY);
                //qDebug()<<"ver log base = "<<logAxisY->base();
                break;
    }
}
