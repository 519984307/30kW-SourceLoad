#include <seriessetting/lineseriessetting.h>

LineSeriesSetting::LineSeriesSetting(QChart*chart):mChart(chart)
{
    mGenericSetting = new SeriesSetting(chart);
    mLineSetting = new SeriesLine(chart);

    addLayout(mGenericSetting);
    addWidget(mLineSetting);

    connect(this,&LineSeriesSetting::tableChanged,
            mGenericSetting,&SeriesSetting::tableChanged);
    connect(mGenericSetting,static_cast<void (SeriesSetting::*)(int)>(&SeriesSetting::seriesChanged),
            this,[=](int index){ // 折线图只存在QLineSeries一种类型
            mCurrentSeries = static_cast<QLineSeries*>(mChart->series().at(index)); // 更新当前曲线
            mLineSetting->setCurrentSeries(mCurrentSeries,index);//切换曲线进行更新
    });
}
