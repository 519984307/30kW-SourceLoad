#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>
#include <chart/chart.h>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chart/chartdatagenerator.h>
#include <chartview/chartview.h>
#include <tool/tableviewmodel.h>
#include <chartview/barchartbar.h>
#include <charttool/barcharttool.h>

class BarChart: public QMainWindow
{
    Q_OBJECT
public:
    explicit BarChart(QTableView *,QWidget *parent = Q_NULLPTR);
    void clearChart();
    void closeChildrenWindows();
private:
    void initChart();
    QSplitter * mSplitter;
    Chart * mChart;
    TableViewModel * mTableModel;
    ChartView * mChartView;
    QTableView * mTableView;
    ChartDataGenerator * mGenerator;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
    BarChartBar * mToolBar;
    BarChartTool * mToolBox;
signals:
    void tableChanged();
    void associateCompeleted();
};

#endif // BARCHART_H
