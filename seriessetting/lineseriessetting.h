#ifndef LINESERIESSETTING_H
#define LINESERIESSETTING_H

#include <seriessetting/seriessetting.h>
#include <seriessetting/seriesline.h>

class LineSeriesSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit LineSeriesSetting(QChart*);
private:
    QChart * mChart;
    QLineSeries * mCurrentSeries;
    SeriesSetting * mGenericSetting; // 使用组合
    SeriesLine * mLineSetting;
signals:
    void tableChanged();
};

#endif // LINESERIESSETTING_H
