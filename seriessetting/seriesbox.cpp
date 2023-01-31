#include <seriessetting/seriesbox.h>

SeriesBox::SeriesBox(QChart *chart,QAbstractSeries*series, const QIcon&icon,QWidget*parent):
    QGroupBox(parent),mChart(chart),mCurrentSeries(series),mCurrentSeriesId(0),mIcon(icon)
{
    setFont(QFont("Times New Roman",12));
    setMinimumWidth(450); // 和charttool.cpp保持一致稍小一些
}

void SeriesBox::setChart(QChart *c)
{
    mChart = c;
}

QChart* SeriesBox::chart() const
{
    return  mChart;
}

void SeriesBox::setCurrentSeries(QAbstractSeries *series,int id)
{
    mCurrentSeries = series;
    mCurrentSeriesId = id;
    updateState(); // 切换曲线后更新状态
}

QAbstractSeries* SeriesBox::currentSeries() const
{
    return  mCurrentSeries;
}

int SeriesBox::currentSeriesId() const
{
    return mCurrentSeriesId;
}

void SeriesBox::setCurrentSeriesId(int id)
{
    mCurrentSeriesId = id;
}
