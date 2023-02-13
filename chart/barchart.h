#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>
#include "chart.h"
#include "chartshowtip.h"
#include "chartshowlegend.h"
#include "chartdatagenerator.h"
#include "../chartview/chartview.h"
#include "../tool/tableviewmodel.h"
#include "../chartview/barchartbar.h"
#include "../charttool/barcharttool.h"

class BarChart: public QMainWindow
{
    Q_OBJECT
public:
    explicit BarChart(QTableView *,QWidget *parent = Q_NULLPTR);
    enum AssociateMode {RowMode,ColMode,RowRegionMode,ColRegionMode};
    void clearChart();
    void closeChildrenWindows();
private:
    void initChart();
    void onSeriesColorChanged(QBarSeries*,QColor,int);
    QSplitter * mSplitter;
    Chart * mChart;
    QBarSeries * mCurrentSeries;
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
    void modeChanged(int,int);
    void associateCompeleted();
};

#endif // BARCHART_H
