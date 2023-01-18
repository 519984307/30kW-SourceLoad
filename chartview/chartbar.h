#ifndef CHARTBAR_H
#define CHARTBAR_H

#include <QToolBar>
#include <QtCharts/QChart>
#include <QTableView>
#include <chartview/screenshoot.h>
using namespace QtCharts;

class ChartBar : public QToolBar
{
    Q_OBJECT
public:
    explicit ChartBar(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    QTableView * mTableView;
    QChartView * mChartView;
    QChart * mChart;
    ScreenShoot * mScreenShot;
};

#endif // CHARTBAR_H
