#ifndef CHARTSETTING_H
#define CHARTSETTING_H

#include <chartsetting/charttitle.h>
#include <chartsetting/chartmargin.h>
#include <chartsetting/chartanimation.h>
#include <chartsetting/chartlegend.h>
#include <chartsetting/chartbackground.h>
#include <chartsetting/chartforeground.h>

// chartsetting没有子类,所有曲线类型均可用
class ChartSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit ChartSetting(QChart* chart);
    void closeChildrenWindows();
private:
    QChart * mChart;
    ChartTitle * mTitle;
    ChartMargin * mMargin;
    ChartAnimation * mAnimation;
    ChartLegend * mLegend;
    ChartBackground * mBackground;
    ChartForeground * mForeground;
};
#endif // CHARTSETTING_H
