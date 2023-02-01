#ifndef CHARTBAR_H
#define CHARTBAR_H

#include <QToolBar>
#include <chartview/screenshoot.h>
#include <chartview/associatetable.h>

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
    AssociateTable * mAssociateTable;
signals:
    void associateCompeleted();
    void tableChanged();
    void seriesColorChanged(QLineSeries*);
    void seriesRemoved(QLineSeries*);
};

#endif // CHARTBAR_H
