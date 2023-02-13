#include <seriessetting/pieseriessetting.h>

PieSeriesSetting::PieSeriesSetting(QChart*chart):mChart(chart)
{
    mCurrentSeries = static_cast<QPieSeries*>(mChart->series().at(0));
    mInfo = new SeriesInfo(chart);
    mPie = new SeriesPie(chart);
    //mPieSlice = new SeriesPieSlice(chart);
    addWidget(mInfo);
    addWidget(mPie);
    //addWidget(mPieSlice);

    // 更新柱状图曲线的界面设置
    connect(this,&PieSeriesSetting::associateCompeleted,mInfo,&SeriesInfo::updateInfo);
    connect(this,&PieSeriesSetting::associateCompeleted,mPie,&SeriesPie::updatePie);
    //connect(this,&PieSeriesSetting::associateCompeleted,mPieSlice,&SeriesPieSlice::updateBarSet);
    //connect(this,&PieSeriesSetting::modeChanged,mPieSlice,&SeriesPieSlice::updateAssociateMode);//告知当前曲线是什么模式生成的
    // 饼图系列的颜色改变后去改变对应的表格颜色
    //connect(mPieSlice,&SeriesPieSlice::seriesColorChanged,this,&PieSeriesSetting::seriesColorChanged);
}
