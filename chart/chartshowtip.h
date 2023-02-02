#ifndef CHARTSHOWTIP_H
#define CHARTSHOWTIP_H

#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QChart>
#include <QLineSeries>
#include <QScatterSeries>
using namespace  QtCharts;

class ChartShowTip : public QObject //要继承否则报错
{
    Q_OBJECT
public:
    explicit ChartShowTip(QObject*parent=Q_NULLPTR);
    void setChart(QChart*);
    void mapping(QLineSeries*);
    void mapping(QScatterSeries*);
private:
    void showToolTip(QPointF point, bool state);
    QChart* mChart;
    QGraphicsSimpleTextItem * mCoordTip;
    QGraphicsRectItem * mCoordRect;
};

#endif // CHARTSHOWTIP_H
