#include <chart/chartshowtip.h>

ChartShowTip::ChartShowTip(QObject*parent):QObject(parent)
{
    mCoordRect = Q_NULLPTR;
    mCoordTip = Q_NULLPTR;
}

void ChartShowTip::setChart(QChart *chart)
{
    mCoordTip = new QGraphicsSimpleTextItem(chart);
    mCoordTip->setPen(QPen(QColor("#8B008B")));
    mCoordTip->setFont(QFont("Times New Roman",14));
    mCoordTip->setZValue(10);
    mCoordRect = new QGraphicsRectItem(chart);
    mCoordRect->setZValue(9);
    mCoordRect->setBrush(QColor("#FFFFE0"));
    mCoordRect->setPen(QPen(QColor(0,0,0)));
    mChart = chart;
}

void ChartShowTip::mapping(QLineSeries * series)
{
    connect(series, &QLineSeries::hovered, this, &ChartShowTip::showToolTip);
}

void ChartShowTip::mapping(QScatterSeries*series)
{
    connect(series, &QScatterSeries::hovered, this, &ChartShowTip::showToolTip);
}

void ChartShowTip::showToolTip(QPointF point, bool state)
{
    if (state)
    {
        QPointF pos = mChart->mapToPosition(point);
        mCoordTip->setPos(pos); // 把曲线的坐标值映射为改点在全局的位置
        mCoordTip->setText(QString("[%1, %2] ").arg(point.x()).arg(point.y()));
        mCoordRect->setRect(QRectF(pos,QSizeF(213.,38.))); //长213高38的矩形刚好把文字放进去
        mCoordTip->show();
        mCoordRect->show();
    }
    else {
        mCoordTip->hide();
        mCoordRect->hide();
    }
}
