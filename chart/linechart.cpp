#include <chart/linechart.h>

LineChart::LineChart(QTableView * tableview,QWidget *parent) : QMainWindow(parent),mTableView(tableview)
{
    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/linechart.png"));

    mGenerator = new ChartDataGenerator;
    mChart = new Chart;

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

    connect(mToolBar,&ChartBar::tableChanged,mToolBox,&LineChartTool::tableChanged);
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
    //qDebug()<<mChart->axisX()<<axisX; // 是1个地址
    //qDebug()<<axisX->type()<<axisY->type(); // 1,16=AxisTypeValue,AxisTypeLogValue
    connect(series, &QLineSeries::hovered, this, &LineChart::showToolTip);
}

void LineChart::initMappingChart()
{
    auto model = static_cast<TableViewModel*>(mTableView->model());

    QLineSeries * series1 = new QLineSeries;
    series1->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),2));
    series1->setName("line1");
    QLineSeries * series2 = new QLineSeries;
    series2->setPen(QPen(QBrush(Qt::green,Qt::SolidPattern),2));
    series2->setName("line2");
    QLineSeries * series3 = new QLineSeries;
    series3->setPen(QPen(QBrush(Qt::yellow,Qt::SolidPattern),2));
    series3->setName("line3");

     QVXYModelMapper *mapper = new QVXYModelMapper(this);
    mapper->setXColumn(0);
    mapper->setYColumn(1);
    mapper->setSeries(series1);
    mapper->setModel(model);
    QString seriesColorHex = "#" + QString::number(series1->pen().color().rgb(), 16).right(6).toUpper();
    model->addMapping(seriesColorHex, QRect(0, 0, 2, model->rowCount())); //前2列
    mChart->addSeries(series1);

    mapper = new QVXYModelMapper(this);
    mapper->setXColumn(2);
    mapper->setYColumn(3);
    mapper->setSeries(series2);
    mapper->setModel(model);
    seriesColorHex = "#" + QString::number(series2->pen().color().rgb(), 16).right(6).toUpper();
    model->addMapping(seriesColorHex, QRect(2, 0, 2, model->rowCount())); //中间2列
    mChart->addSeries(series2);

    mapper = new QVXYModelMapper(this);
    mapper->setXColumn(4);
    mapper->setYColumn(5);
    mapper->setSeries(series3);
    mapper->setModel(model);
    seriesColorHex = "#" + QString::number(series3->pen().color().rgb(), 16).right(6).toUpper();
    model->addMapping(seriesColorHex, QRect(4, 0, 2, model->rowCount())); //后2列
    mChart->addSeries(series3);

    mChart->createDefaultAxes();

    connect(series1, &QLineSeries::hovered, this, &LineChart::showToolTip);
    connect(series2, &QLineSeries::hovered, this, &LineChart::showToolTip);
    connect(series3, &QLineSeries::hovered, this, &LineChart::showToolTip);
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
