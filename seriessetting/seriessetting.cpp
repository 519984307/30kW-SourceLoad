#include <seriessetting/seriessetting.h>

SeriesSetting::SeriesSetting(QChart*chart): mChart(chart)
{
    setObjectName("SeriesSettingsLayout");
    mIcon.addFile(":/images/toolbox_series.png");
}

void SeriesSetting::closeChildrenWindows()
{

}
