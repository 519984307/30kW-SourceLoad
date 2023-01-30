#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QToolBox>
#include <QToolBar>
#include <QSplitter>
#include <QTime>
#include <QDebug>
#include <chart/chart.h>
#include <chart/chartdatagenerator.h>
#include <chartview/chartview.h>
#include <chartview/chartbar.h>
#include <charttool/linecharttool.h>
#include <tool/tableviewmodel.h>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>

class LineChart : public QMainWindow
{
    Q_OBJECT
public:
    explicit LineChart(QTableView *,QWidget *parent = Q_NULLPTR);
    void closeChildrenWindows();
    ~LineChart();
private:
    void initChart();
    void initRandomChart();
    void initMappingChart();
    void legendMarkerClicked();
    void showToolTip(QPointF point, bool state);
    QSplitter * mSplitter;
    Chart * mChart;
    ChartView * mChartView;
    QTableView * mTableView;
    LineChartTool * mToolBox;
    ChartDataGenerator * mGenerator;
    ChartBar * mToolBar;
    QGraphicsSimpleTextItem * mCoordTip;
    QGraphicsRectItem * mCoordRect;
};

#endif // LINECHART_H
