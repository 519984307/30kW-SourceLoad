#ifndef LINECHARTTOOL_H
#define LINECHARTTOOL_H

#include "charttool.h"
#include "../seriessetting/lineseriessetting.h"
#include "../axissetting/axissetting.h"

class LineChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit LineChartTool(QChart*,QWidget*parent=Q_NULLPTR);
private:
    AxisSetting * mAxisSetting;
    LineSeriesSetting * mSeriesSetting;
signals:
    void seriesColorChanged(QLineSeries*);
    void seriesRemoved(QLineSeries*);
};
#endif // LINECHARTTOOL_H
