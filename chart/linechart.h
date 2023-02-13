#ifndef LINECHART_H
#define LINECHART_H

#include <QMainWindow>
#include "chart.h"
#include "chartshowtip.h"
#include "chartshowlegend.h"
#include "chartdatagenerator.h"
#include "../chartview/chartview.h"
#include "../tool/tableviewmodel.h"
#include "../chartview/linechartbar.h"
#include "../charttool/linecharttool.h"

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
    ChartDataGenerator * mGenerator;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
    LineChartBar * mToolBar;
    LineChartTool * mToolBox;
signals:
    void tableChanged();
    void associateCompeleted();
    void seriesColorChanged(QColor,int);
};

#endif // LINECHART_H
