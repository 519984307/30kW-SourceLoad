#ifndef BARSERIESSETTING_H
#define BARSERIESSETTING_H

#include <seriessetting/seriessetting.h>
#include <seriessetting/seriesinfo.h>
#include <seriessetting/seriesbar.h>
#include <seriessetting/seriesbarset.h>

class BarSeriesSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit BarSeriesSetting(QChart*);
private:
    QChart * mChart;
    QBarSeries * mCurrentSeries;
    //SeriesSetting * mGenericSetting; // 不要通用设置,因为直方图无需切换曲线
    SeriesInfo * mInfo;
    SeriesBar * mBar;
    SeriesBarSet * mBarSet;
signals:
    void associateCompeleted();
    void modeChanged(int,int);
    void seriesColorChanged(QBarSeries*,QColor,int);
};

#endif // BARSERIESSETTING_H
