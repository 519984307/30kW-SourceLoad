#ifndef CHARTDATAGENERATOR_H
#define CHARTDATAGENERATOR_H

#include <QTime>
#include <QPainter>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QtMath>
#include <QDebug>
const float Pi = 3.1415926535f;
using namespace QtCharts;

class ChartDataGenerator : public QObject
{
    Q_OBJECT
public:
    explicit ChartDataGenerator(QObject *parent = Q_NULLPTR);
    QLineSeries * linechart(int=1,int=100);
    QLineSeries * sinechart(int=1,int=100);
    QValueAxis * axis(int,const QString& ="data point",const QString& ="%i");
    QLogValueAxis * logaxis(qreal,const QString& ="data point");
    QImage startPattern();
private:
    QPen mPen;
};

#endif // CHARTDATAGENERATOR_H
