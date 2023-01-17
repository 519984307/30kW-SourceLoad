#ifndef CHARTCOORDTIP_H
#define CHARTCOORDTIP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QtCharts/QChart>
using namespace QtCharts;

class ChartCoordTip : public QObject,public QGraphicsItem // 必须继承QObject且放在第1个
{//no member named 'staticMetaObject
    Q_OBJECT
public:
    explicit ChartCoordTip(QChart *chart);
    enum {Type = UserType +1};
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    int type() const;
    void setAnchor(QPointF);
    void setText(const QString &text);
    void updateGeometry();
private:
    QChart * mChart;
    QPointF mAnchor;
    QRectF mRect;
    QString mText;
    QRectF mTextRect;
    QFont mTextFont;
};

#endif // CHARTCOORDTIP_H
