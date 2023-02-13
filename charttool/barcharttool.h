#ifndef BARCHARTTOOL_H
#define BARCHARTTOOL_H

#include "charttool.h"
#include "../axissetting/axissetting.h"
#include "../seriessetting/barseriessetting.h"

class BarChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit BarChartTool(QChart*,QWidget*parent=Q_NULLPTR);
private:
    AxisSetting * mAxisSetting;
    BarSeriesSetting * mSeriesSetting;
signals:
    void modeChanged(int,int);
    void seriesColorChanged(QBarSeries*,QColor,int);
};

#endif // BARCHARTTOOL_H
