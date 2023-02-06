#ifndef SCATTERCHARTTOOL_H
#define SCATTERCHARTTOOL_H

#include <charttool/charttool.h>
#include <seriessetting/scatterseriessetting.h>
#include <axissetting/axissetting.h>

class ScatterChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit ScatterChartTool(QChart*,QWidget*parent=Q_NULLPTR);
private:
    AxisSetting * mAxisSetting;
    ScatterSeriesSetting * mSeriesSetting;
signals:
    void seriesColorChanged(QScatterSeries*);
    void seriesRemoved(QScatterSeries*);
};

#endif // SCATTERCHARTTOOL_H
