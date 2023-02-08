#ifndef CHARTSHOWLEGEND_H
#define CHARTSHOWLEGEND_H

#include <QObject>
#include <QtCharts>
#include <QLegendMarker>
using namespace QtCharts;

class ChartShowLegend : public QObject
{
    Q_OBJECT
public:
    explicit ChartShowLegend(QObject*parent = Q_NULLPTR);
    void mapping(QChart*);
private:
    void legendMarkerClicked();
    bool mShowLegend;
};

#endif // CHARTSHOWLEGEND_H
