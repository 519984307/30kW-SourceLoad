#ifndef CHARTBAR_H
#define CHARTBAR_H

#include <QToolBar>
#include <QTableView>
#include <tool/tableviewmodel.h>
#include <chartview/screenshoot.h>

class ChartBar : public QToolBar
{
    Q_OBJECT
public:
    explicit ChartBar(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
protected:
    QAction * mAssociatetableAct;
    QTableView * mTableView;
    QChartView * mChartView;
    QChart * mChart;
    ScreenShoot * mScreenShot;
signals:
    void associateCompeleted();
    void tableChanged();
//        void seriesColorChanged(QScatterSeries*);
//    void seriesRemoved(QScatterSeries*);
};

#endif // CHARTBAR_H
