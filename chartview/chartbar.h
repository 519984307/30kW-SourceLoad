#ifndef CHARTBAR_H
#define CHARTBAR_H

#include <QToolBar>
#include <QtCharts/QChart>
#include <chartview/screenshoot.h>
using namespace QtCharts;

class ChartBar : public QToolBar
{
    Q_OBJECT
public:
    explicit ChartBar(QChartView*,QWidget*parent = Q_NULLPTR);
private:
    QChartView * mChartView;
    QChart * mChart;
    ScreenShoot * mScreenShot;
};

#endif // CHARTBAR_H
