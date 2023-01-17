#include <charttool/linecharttool.h>

LineChartTool::LineChartTool(QChart* chart,QWidget*parent):ChartTool(chart,parent)
{
    //mChartWidget->updateScrollArea(); // 图表设置都相同,只需调用一次更新滑动区域，ChartTool内部已调用过
    //mSeriesWidget->updateScrollArea(); // 曲线和坐标轴设置不同,在这里调用

    mLineAxisSetting = new LineAxisSetting(chart);
    mAxisWidget->addLayout(mLineAxisSetting); // 坐标轴工具页的发挥由mAxisSetting决定
    mAxisWidget->updateScrollArea();

}
