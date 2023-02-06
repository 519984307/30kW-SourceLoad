#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include <chart/chart.h>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chart/chartdatagenerator.h>
#include <chartview/chartview.h>
#include <chartview/linechartbar.h>
#include <charttool/linecharttool.h>
#include <tool/tableviewmodel.h>

class LineChart : public QMainWindow
{
    Q_OBJECT
public:
    explicit LineChart(QTableView *,QWidget *parent = Q_NULLPTR);
    void closeChildrenWindows();
    void clearChart();
    ~LineChart();
private:
    void initChart();
    void initRandomChart();
    void initMappingChart();
    void addMapping(TableViewModel*,QXYSeries*,int,int);
    void onSeriesColorChanged(QLineSeries*);
    void onSeriesRemoved(QLineSeries*);
    QHash<QLineSeries*,QPair<int,int>> mSeriesXYColumn;

    QSplitter * mSplitter;
    Chart * mChart;
    TableViewModel * mTableModel;
    ChartView * mChartView;
    QTableView * mTableView;
    LineChartTool * mToolBox;
    ChartDataGenerator * mGenerator;
    LineChartBar * mToolBar;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
signals:
    void tableChanged();
    void associateCompeleted();
    void seriesColorChanged(QColor,int);
};

#endif // LINECHART_H
