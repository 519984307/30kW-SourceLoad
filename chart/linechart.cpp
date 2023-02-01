#include <chart/linechart.h>
#include <QPair>
LineChart::LineChart(QTableView * tableview,QWidget *parent) : QMainWindow(parent),mTableView(tableview)
{
    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/linechart.png"));

    mGenerator = new ChartDataGenerator;
    mChart = new Chart;
    mTableModel = static_cast<TableViewModel*>(mTableView->model());

    mCoordTip = new QGraphicsSimpleTextItem(mChart);
    mCoordTip->setPen(QPen(QColor("#8B008B")));
    mCoordTip->setFont(QFont("Times New Roman",14));
    mCoordTip->setZValue(10);
    mCoordRect = new QGraphicsRectItem(mChart);
    mCoordRect->setZValue(9);
    mCoordRect->setBrush(QColor("#FFFFE0"));
    mCoordRect->setPen(QPen(QColor(0,0,0)));

    initChart(); // 注意先初始化,mChart具备标题序列和轴了再被后边所用
    mChartView = new ChartView(mChart,this);
    mToolBar = new ChartBar(mTableView,mChartView,this);
    addToolBar(Qt::TopToolBarArea,mToolBar);
    mToolBox = new LineChartTool(mChart,this);
    mSplitter = new QSplitter(Qt::Horizontal);
    mSplitter->setChildrenCollapsible(false);
    mSplitter->setHandleWidth(10);
    mSplitter->addWidget(mChartView);
    mSplitter->addWidget(mToolBox);
    mSplitter->setStretchFactor(0,4); // 4:1的宽度
    mSplitter->setStretchFactor(1,1);
    setCentralWidget(mSplitter);

    // 工具栏的改变有2个方向可以触发,一个是外部表格导入,触发清空图表,一个是图表工具条的清空动作
    connect(mToolBar,&ChartBar::associateCompeleted,mToolBox,&LineChartTool::associateCompeleted);
    connect(this,&LineChart::associateCompeleted,mToolBox,&LineChartTool::associateCompeleted);
    connect(this,&LineChart::tableChanged,mToolBar,&ChartBar::tableChanged);
    connect(mToolBox,&LineChartTool::seriesColorChanged,mToolBar,&ChartBar::seriesColorChanged);
    connect(mToolBox,&LineChartTool::seriesColorChanged,this,&LineChart::onSeriesColorChanged);
    connect(mToolBox,&LineChartTool::seriesRemoved,mToolBar,&ChartBar::seriesRemoved);
    connect(mToolBox,&LineChartTool::seriesRemoved,this,&LineChart::onSeriesRemoved);
}

LineChart::~LineChart()
{
    if (mChartView != Q_NULLPTR)
    {
        mChart->removeAllSeries();

        delete mChartView;
        mChartView = Q_NULLPTR;
    }
}

void LineChart::closeChildrenWindows()
{
    mToolBox->closeChildrenWindows(); // 工具箱设置有子窗口,需要关闭
}

void LineChart::clearChart()
{
    if (mChart->axisX()) mChart->removeAxis(mChart->axisX());
    if (mChart->axisY()) mChart->removeAxis(mChart->axisY());
    if (mChart->series().count()) mChart->removeAllSeries();
    mSeriesXYColumn.clear(); // 这里存放的指针和对应的内容也要清空
    emit associateCompeleted(); // 文件导入调用clearChart清空图表还要通知曲线工具栏更改combo
}

void LineChart::initChart()
{
    // 任选1种初始化方式
    //initRandomChart();
    initMappingChart();
    mChart->setTitle("Line Chart Example");
    const auto markers = mChart->legend()->markers(); // 初始化曲线后再连接
    for (QLegendMarker *marker : markers) { // 利用返回的图例标记的clicked信号实现点击图例变暗并隐藏曲线的效果
        QObject::disconnect(marker, &QLegendMarker::clicked,this, &LineChart::legendMarkerClicked); // 先断开以防重复连接
        QObject::connect(marker, &QLegendMarker::clicked, this, &LineChart::legendMarkerClicked);
    }
}

void LineChart::initRandomChart()
{
    QLineSeries *series = mGenerator->linechart(5000,100);//幅值5000配合对数坐标轴
    QValueAxis *axisX = mGenerator->axis(series->count()/10); // 默认100个值,间隔10
    QLogValueAxis *axisY = mGenerator->logaxis(4.0,"value"); // 对数底数4

    mChart->addSeries(series); // addSeries要先调用

    mChart->addAxis(axisX, Qt::AlignBottom); // 表添加轴确定好方向
    mChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX); // 将轴和曲线关联
    series->attachAxis(axisY);// 这步操作切记必须在表先addAxis之后再附着到曲线上

    connect(series, &QLineSeries::hovered, this, &LineChart::showToolTip);
}

void LineChart::initMappingChart()
{

    QLineSeries * series1 = mGenerator->lineseries("line1",Qt::red);
    QLineSeries * series2 = mGenerator->lineseries("line2",Qt::green);
    QLineSeries * series3 = mGenerator->lineseries("line3",Qt::yellow);

    addMapping(mTableModel ,series1,0,1);
    mChart->addSeries(series1);

    addMapping(mTableModel ,series2,2,3);
    mChart->addSeries(series2);

    addMapping(mTableModel ,series3,4,5);
    mChart->addSeries(series3);

    // 用于保存曲线和表格映射列的关系,方便曲线更改颜色后能找到映射列同步颜色
    mSeriesXYColumn[series1] = qMakePair<int,int>(0,1);
    mSeriesXYColumn[series2] = qMakePair<int,int>(2,3);
    mSeriesXYColumn[series3] = qMakePair<int,int>(4,5);

    mChart->createDefaultAxes();

    connect(series1, &QLineSeries::hovered, this, &LineChart::showToolTip);
    connect(series2, &QLineSeries::hovered, this, &LineChart::showToolTip);
    connect(series3, &QLineSeries::hovered, this, &LineChart::showToolTip);
}

void  LineChart::addMapping(TableViewModel*model, QXYSeries *series, int col1, int col2)
{
   QVXYModelMapper *mapper = new QVXYModelMapper(this);
   mapper->setXColumn(col1);
   mapper->setYColumn(col2);
   mapper->setSeries(series);
   mapper->setModel(model);

//   for(int y = 0;y < model->rowCount(); ++ y)
//   { // col是水平方向,表示x坐标, y坐标遍历行即可
//       model->addCellMapping(QRect(col1,y,1,1),series->color());
//       model->addCellMapping(QRect(col2,y,1,1),series->color());
//   }
   model->addColMapping(col1,series->color()); // 上方2行代码可用这2行替代
   model->addColMapping(col2,series->color());
}

void LineChart::legendMarkerClicked() // 这个函数不能放在chart.cpp连接因为那个时候还没有曲线,图例尚未创建出来,必须先初始化曲线后再连接
{
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender()); // 发送clicked的图例标记
    switch (marker->type())
    {
        case QLegendMarker::LegendMarkerTypeXY: // QXYLegendMarker=直线+样条曲线+散点系列的效果
        {
                marker->series()->setVisible(!marker->series()->isVisible());
                marker->setVisible(true); // 曲线隐藏会让图例也隐藏,还是要显示的只是变暗
                qreal alpha = 1.0;
                if (!marker->series()->isVisible())
                    alpha = 0.5;

                QColor color;
                QBrush brush = marker->labelBrush(); // 图例的文字
                color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setLabelBrush(brush);

                brush = marker->brush(); //图例标记的背景
                color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setBrush(brush);

                QPen pen = marker->pen(); // 图例标记的方框
                color = pen.color();
                color.setAlphaF(alpha);
                pen.setColor(color);
                marker->setPen(pen);
                break;
        }
    default: break;
    }
}

void LineChart::showToolTip(QPointF point, bool state)
{
    if (state)
    {
        QPointF pos = mChart->mapToPosition(point);
        mCoordTip->setPos(pos); // 把曲线的坐标值映射为改点在全局的位置
        mCoordTip->setText(QString("[%1, %2] ").arg(point.x()).arg(point.y()));
        mCoordRect->setRect(QRectF(pos,QSizeF(213.,38.))); //长213高38的矩形刚好把文字放进去
        mCoordTip->show();
        mCoordRect->show();
    }
    else {
        mCoordTip->hide();
        mCoordRect->hide();
    }

}

void LineChart::onSeriesColorChanged(QLineSeries*series)
{
    if (mSeriesXYColumn.keys().contains(series))
    { // 修改颜色的曲线是这里初始化创建出来的曲线(因为可能是associatetable内创建出来的)
        auto xyCol = mSeriesXYColumn[series]; // 创建该曲线所使用的表格2列
        mTableModel->addColMapping(xyCol.first,series->color()); // 让表格对应的曲线两列数据跟随曲线当前颜色
        mTableModel->addColMapping(xyCol.second,series->color());
    }
}

void LineChart::onSeriesRemoved(QLineSeries *series)
{
    if (mSeriesXYColumn.keys().contains(series))
    {
        auto xyCol = mSeriesXYColumn[series];  // 唯一的区别是移除曲线是修改为白色
        mTableModel->addColMapping(xyCol.first,Qt::white);
        mTableModel->addColMapping(xyCol.second,Qt::white);
        mSeriesXYColumn.remove(series); // 已被移除不要再保留映射关系以免以后出现麻烦
    }
}
