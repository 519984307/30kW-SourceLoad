#ifndef BARCHARTTOOL_H
#define BARCHARTTOOL_H

#include <charttool/charttool.h>
#include <axissetting/axissetting.h>

class BarChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit BarChartTool(QChart*,QWidget*parent=Q_NULLPTR);
private:
    AxisSetting * mAxisSetting;
};

#endif // BARCHARTTOOL_H
