#ifndef SCATTERCHART_H
#define SCATTERCHART_H

#include <QMainWindow>
#include "chart.h"
#include "chartshowtip.h"
#include "chartshowlegend.h"
#include "chartdatagenerator.h"
#include "../chartview/chartview.h"
#include "../tool/tableviewmodel.h"
#include "../chartview/scatterchartbar.h"
#include "../charttool/scattercharttool.h"

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
