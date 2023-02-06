#ifndef SCATTERCHARTBAR_H
#define SCATTERCHARTBAR_H

#include <chartview/chartbar.h>
#include <chartview/scatterassociatetable.h>

class ScatterChartBar : public ChartBar
{
    Q_OBJECT
public:
    explicit ScatterChartBar(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    ScatterAssociateTable * mAssociateTable;
signals:
    void seriesColorChanged(QScatterSeries*);
    void seriesRemoved(QScatterSeries*);
};

#endif // SCATTERCHARTBAR_H
