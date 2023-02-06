#include <chartview/scatterassociatetable.h>

ScatterAssociateTable::ScatterAssociateTable(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QDialog(parent),mTableView(tableview),mChartView(chartview)
{
    mLegend = new ChartShowLegend;
    mTip = new ChartShowTip;
    mTip->setChart(mChartView->chart());
    mTableModel = static_cast<TableViewModel*>(mTableView->model());
    QVBoxLayout * lay = new QVBoxLayout(this);

    mMode = new AssociateMode(mTableView,mChartView);
    mSeries = new AssociateSeries;
    mSeries->setLineWidthVisible(false); // 散点图设置标记大小即可,宽度没有意义
    mAxis = new AssociateAxis(mTableView,mChartView);
    mAxis->setTimeAxisVisible(false);// 时间坐标轴对于散点图不支持,使用时隐藏

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

void ScatterAssociateTable::initConnections()
{
    connect(mMode,&AssociateMode::changeMode,mAxis,&AssociateAxis::setHorizontalEnabled);
    connect(mOkBtn,&QPushButton::clicked,this,&ScatterAssociateTable::onOkBtn);

    connect(this,&ScatterAssociateTable::tableChanged,this,[=]{
        disconnect(mOkBtn,&QPushButton::clicked,this,&ScatterAssociateTable::onOkBtn);
        mTableModel = static_cast<TableViewModel*>(mTableView->model());
        connect(mOkBtn,&QPushButton::clicked,this,&ScatterAssociateTable::onOkBtn);
        mMode->adjustRange();
    });

    connect(this,static_cast<void (ScatterAssociateTable::*)(QScatterSeries*)>(&ScatterAssociateTable::seriesColorChanged),
            this,[=](QScatterSeries*series){
            if (mSeriesXYColumn.keys().contains(series))
            {
                auto cols = mSeriesXYColumn[series];
                mTableModel->addColMapping(cols.first,series->color());
                if (cols.second < 0) return;
                mTableModel->addColMapping(cols.second,series->color());
            }
    });
    connect(this,static_cast<void (ScatterAssociateTable::*)(QScatterSeries*)>(&ScatterAssociateTable::seriesRemoved),
            this,[=](QScatterSeries*series){
            if (mSeriesXYColumn.keys().contains(series))
            {
                auto cols = mSeriesXYColumn[series];
                mTableModel->addColMapping(cols.first,Qt::white);
                if (cols.second < 0) return;
                mTableModel->addColMapping(cols.second,Qt::white);
                mSeriesXYColumn.remove(series);
            }
    });
}

void ScatterAssociateTable::onOkBtn()
{
    bool isSingle = mMode->isSingle();
    if (isSingle) singleMapping();
    else doubleMapping();
    mLegend->mapping(mChartView->chart());

    emit associateCompeleted();
    accept();
}

void ScatterAssociateTable::singleMapping()
{
    int col = mMode->singleCol();

    QScatterSeries * series = new QScatterSeries;
    series->setPointLabelsFormat("(@xPoint, @yPoint)");
    series->setBorderColor(Qt::white);
    series->setColor(mSeries->linecolor());
    series->setMarkerSize(mSeries->markersize());

    mTableModel->addColMapping(col,mSeries->linecolor());
    mSeriesXYColumn[series] = qMakePair<int,int>(col,-1);

    QString name = mTableModel->horizontalHeaderLabels()[col];
    if (name.toInt()) series->setName("col"+name);
    else series->setName(name);

    QVector<QVariant> data = mTableModel->colData(col);
    QPointF point;
    for(int x = 0; x <data.count(); ++x){
        point.setX((qreal)x);point.setY(data[x].toDouble());
        *series  << point;
    }

    mChartView->chart()->addSeries(series);
    QValueAxis * axisX = new QValueAxis;
    mChartView->chart()->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    setVerticalAxis(series);

    mTip->mapping(series);
}

void ScatterAssociateTable::doubleMapping()
{
    QPoint point = mMode->doubleCols();
    int xCol = point.x();
    int yCol = point.y();

    QScatterSeries * series = new QScatterSeries;
    series->setPointLabelsFormat("(@xPoint, @yPoint)");
    series->setBorderColor(Qt::white);
    series->setColor(mSeries->linecolor());
    series->setMarkerSize(mSeries->markersize());

    mTableModel->addDoubleColMapping(series,xCol,yCol);
    mSeriesXYColumn[series] = qMakePair<int,int>(xCol,yCol);

    QString name1 = mTableModel->horizontalHeaderLabels()[xCol];
    QString name2 = mTableModel->horizontalHeaderLabels()[yCol];
    if (name1.toInt()) name1 = "col"+name1;
    if (name2.toInt()) name2 = "col"+name2;
    series->setName(name1+"-"+name2);

    mChartView->chart()->addSeries(series);
    setHorizontalAxis(series);
    setVerticalAxis(series);
    mTip->mapping(series);
}

void ScatterAssociateTable::setHorizontalAxis(QScatterSeries *series)
{
    QValueAxis * valueAxisX;
    QLogValueAxis * logAxisX;
    QDateTimeAxis * timeAxisX;
    auto datetime = QDateTime::currentDateTime();
    auto axisX = mChartView->chart()->axisX();

    if (axisX) mChartView->chart()->removeAxis(axisX);
    switch (mAxis->axisType().x()) {
        case AssociateAxis::Value:
                valueAxisX = new QValueAxis;
                mChartView->chart()->addAxis(valueAxisX,Qt::AlignBottom);
                series->attachAxis(valueAxisX);
                break;
         case AssociateAxis::Time:
                timeAxisX = new QDateTimeAxis;
                timeAxisX->setRange(datetime,datetime.addDays(365));
                mChartView->chart()->addAxis(timeAxisX,Qt::AlignBottom);
                series->attachAxis(timeAxisX);
                break;
          case AssociateAxis::Log:
                logAxisX = new QLogValueAxis;
                logAxisX->setBase(2.);
                auto base = mAxis->axisBase().x();
                if (base != 1.0) logAxisX->setBase(base);
                mChartView->chart()->addAxis(logAxisX,Qt::AlignBottom);
                series->attachAxis(logAxisX);
                break;
    }
}

void ScatterAssociateTable::setVerticalAxis(QScatterSeries *series)
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
                break;
          case AssociateAxis::Log:
                logAxisY = new QLogValueAxis;
                logAxisY->setBase(2.);
                auto base = mAxis->axisBase().y();
                if (base != 1.0) logAxisY->setBase(base);
                mChartView->chart()->addAxis(logAxisY,Qt::AlignLeft);
                series->attachAxis(logAxisY);
                break;
    }
}
