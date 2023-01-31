#ifndef LINECHARTTOOL_H
#define LINECHARTTOOL_H

#include <charttool/charttool.h>
#include <seriessetting/seriessetting.h>
#include <axissetting/axissetting.h>

class LineChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit LineChartTool(QChart*,QWidget*parent=Q_NULLPTR);
private:
    AxisSetting * mAxisSetting;
    SeriesSetting * mSeriesSetting;
};
#endif // LINECHARTTOOL_H
