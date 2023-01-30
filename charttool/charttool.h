#ifndef CHARTTOOL_H
#define CHARTTOOL_H

#include <QToolBox>
#include <charttool/charttoolwidget.h>
#include <chartsetting/chartsetting.h>

class ChartTool : public QToolBox
{
    Q_OBJECT
public:
    explicit ChartTool(QChart* chart,QWidget*parent=Q_NULLPTR);
    void closeChildrenWindows();
    void updateChart();
protected:
    ChartToolWidget * mChartWidget;//3个工具页分别用于图表、曲线和坐标轴的设置
    ChartToolWidget * mSeriesWidget;
    ChartToolWidget * mAxisWidget;
    QChart * mChart;
private:
    ChartSetting * mChartSetting;//图表工具栏所有曲线类型都可使用
signals:
    void tableChanged();
};
#endif // CHARTTOOL_H
