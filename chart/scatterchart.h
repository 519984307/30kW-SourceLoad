#ifndef SCATTERCHART_H
#define SCATTERCHART_H

#include <QMainWindow>
#include <chart/chart.h>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chart/chartdatagenerator.h>
#include <chartview/chartview.h>
#include <chartview/scatterchartbar.h>
#include <charttool/scattercharttool.h>
#include <tool/tableviewmodel.h>

class ScatterChart : public QMainWindow
{
    Q_OBJECT
public:
    explicit ScatterChart(QTableView*,QWidget *parent = nullptr);
    void closeChildrenWindows();
    void clearChart();
    ~ScatterChart();
private:
    void initChart();
    void addMapping(TableViewModel*,QXYSeries*,int,int);
    void onSeriesColorChanged(QScatterSeries*);
    void onSeriesRemoved(QScatterSeries*);
    QHash<QScatterSeries*,QPair<int,int>> mSeriesXYColumn;
    QSplitter * mSplitter;
    Chart * mChart;
    TableViewModel * mTableModel;
    ChartView * mChartView;
    QTableView * mTableView;
    ScatterChartTool * mToolBox;
    ChartDataGenerator * mGenerator;
    ScatterChartBar * mToolBar;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
signals:
    void tableChanged();
    void associateCompeleted();
    void seriesColorChanged(QColor,int);
};

#endif // SCATTERCHART_H
