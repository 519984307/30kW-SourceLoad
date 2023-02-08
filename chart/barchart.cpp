#include <chart/barchart.h>

BarChart::BarChart(QTableView * tableview,QWidget *parent)
    :QMainWindow(parent),mTableView(tableview)
{
    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/barchart.png"));
    mGenerator = new ChartDataGenerator;
    mChart = new Chart;
    mTableModel = static_cast<TableViewModel*>(mTableView->model());
    mLegend = new ChartShowLegend;
    mTip = new ChartShowTip;

    initChart();
    mChartView = new ChartView(mChart,this);
    mToolBar = new BarChartBar(tableview,mChartView,this);
    addToolBar(Qt::TopToolBarArea,mToolBar);
    mToolBox = new BarChartTool(mChart,this);
    mSplitter = new QSplitter(Qt::Horizontal);
    mSplitter->setChildrenCollapsible(false);
    mSplitter->setHandleWidth(10);
    mSplitter->addWidget(mChartView);
    mSplitter->addWidget(mToolBox);
    setCentralWidget(mSplitter);

    //connect(mToolBar,&BarChartBar::associateCompeleted,mToolBox,&BarChartTool::associateCompeleted);
    connect(this,&BarChart::associateCompeleted,mToolBox,&BarChartTool::associateCompeleted);
    connect(this,&BarChart::tableChanged,mToolBar,&BarChartBar::tableChanged);
//    connect(mToolBox,&BarChartTool::seriesColorChanged,mToolBar,&BarChartBar::seriesColorChanged);
//    connect(mToolBox,&BarChartTool::seriesColorChanged,this,&BarChart::onSeriesColorChanged);
//    connect(mToolBox,&BarChartTool::seriesRemoved,mToolBar,&BarChartBar::seriesRemoved);
//    connect(mToolBox,&BarChartTool::seriesRemoved,this,&BarChart::onSeriesRemoved);
}

void BarChart::initChart()
{
    QList <QBarSet*> * barsets = new QList<QBarSet*>;
    barsets->append(new QBarSet("col "+mTableModel->horizontalHeaderLabel(1)));
    barsets->append(new QBarSet("col "+mTableModel->horizontalHeaderLabel(3)));
    barsets->append(new QBarSet("col "+mTableModel->horizontalHeaderLabel(5)));
    barsets->at(0)->setColor(mTableModel->cellColor(0,1));
    barsets->at(1)->setColor(mTableModel->cellColor(0,3));
    barsets->at(2)->setColor(mTableModel->cellColor(0,5));
    barsets->at(0)->setBorderColor(mTableModel->cellColor(0,1));
    barsets->at(1)->setBorderColor(mTableModel->cellColor(0,3));
    barsets->at(2)->setBorderColor(mTableModel->cellColor(0,5));
    barsets->at(0)->setLabelColor(mTableModel->cellColor(0,1));
    barsets->at(1)->setLabelColor(mTableModel->cellColor(0,3));
    barsets->at(2)->setLabelColor(mTableModel->cellColor(0,5));
    QList<QVector<QVariant>> colDatas;
    colDatas.append(mTableModel->colData(1));
    colDatas.append(mTableModel->colData(3));
    colDatas.append(mTableModel->colData(5));
    for (int c = 0 ; c < barsets->count(); ++c)
    {
        for (int r = 0; r < colDatas.at(0).count(); ++r)
            barsets->at(c)->append(colDatas.at(c).at(r).toDouble());
    }
    QBarSeries * series = new QBarSeries;
    series->setBarWidth(2.);
    series->setLabelsVisible(true); // 要显示,否则barset的label不显示
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
    series->append(*barsets);

    mTip->mapping(series);
    mChart->addSeries(series);
    mChart->createDefaultAxes();//默认1,2,3..作为横轴
    mChart->setTitle("Bar Chart Example");
    mLegend->mapping(mChart);
}

void BarChart::closeChildrenWindows()
{
    mToolBox->closeChildrenWindows();
}

void BarChart::clearChart()
{
    if (mChart->axisX()) mChart->removeAxis(mChart->axisX());
    if (mChart->axisY()) mChart->removeAxis(mChart->axisY());
    if (mChart->series().count()) mChart->removeAllSeries();
    //mSeriesXYColumn.clear(); // 这里存放的指针和对应的内容也要清空
    emit associateCompeleted(); // 文件导入调用clearChart清空图表还要通知曲线工具栏更改combo
}
