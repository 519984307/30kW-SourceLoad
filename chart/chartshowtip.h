#ifndef CHARTSHOWTIP_H
#define CHARTSHOWTIP_H

#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QtCharts>
using namespace  QtCharts;

class ChartShowTip : public QObject //要继承否则报错
{
    Q_OBJECT
public:
    explicit ChartShowTip(QObject*parent=Q_NULLPTR);
    void setChart(QChart*);
    void mapping(QLineSeries*);
    void mapping(QScatterSeries*);
    void mapping(QBarSeries*);
private:
    void showXYTip(QPointF point, bool state);
    void showBarTip(bool status, int index, QBarSet *barset);
    QChart* mChart;
    QGraphicsSimpleTextItem * mCoordTip;
    QGraphicsRectItem * mCoordRect;
};

#endif // CHARTSHOWTIP_H
