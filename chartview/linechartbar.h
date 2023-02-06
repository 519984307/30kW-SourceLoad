#ifndef LINECHARTBAR_H
#define LINECHARTBAR_H

#include <chartview/chartbar.h>
#include <chartview/lineassociatetable.h>
class LineChartBar : public ChartBar
{
    Q_OBJECT
public:
    explicit LineChartBar(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    LineAssociateTable * mAssociateTable;
signals:
    void seriesColorChanged(QLineSeries*);
    void seriesRemoved(QLineSeries*);
};

#endif // LINECHARTBAR_H
