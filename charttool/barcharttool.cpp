#include <charttool/barcharttool.h>

BarChartTool::BarChartTool(QChart* chart,QWidget*parent)
    :ChartTool(chart,parent)
{
    mChartWidget->updateScrollArea();
//    mSeriesSetting = new BarSeriesSetting(mChart);
//    mSeriesWidget->addLayout(mSeriesSetting);
    mSeriesWidget->updateScrollArea();
    mAxisSetting = new AxisSetting(mChart);
    mAxisWidget->addLayout(mAxisSetting);
    mAxisWidget->updateScrollArea();

    connect(this,&BarChartTool::associateCompeleted,mAxisSetting,&AxisSetting::associateCompeleted);
//    connect(this,&BarChartTool::associateCompeleted,mSeriesSetting,&BarSeriesSetting::associateCompeleted);
//    connect(mSeriesSetting,&BarSeriesSetting::seriesColorChanged,this,&BarChartTool::seriesColorChanged);
//    connect(mSeriesSetting,&BarSeriesSetting::seriesRemoved,this,&BarChartTool::seriesRemoved);
}
