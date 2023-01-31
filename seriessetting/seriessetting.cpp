#include <seriessetting/seriessetting.h>

SeriesSetting::SeriesSetting(QChart*chart): mChart(chart),mCurrentSeries(nullptr)
{
    setObjectName("SeriesSettingsLayout");
    mIcon.addFile(":/images/toolbox_series.png");

    mCurrentSeries = mChart->series().at(0);

    mWhichSeries = new QGroupBox(tr("当前曲线"));
    initWhichSeries();
    mSeriesInfo = new SeriesInfo(mChart,mCurrentSeries,mIcon);

    addWidget(mWhichSeries);
    addWidget(mSeriesInfo);

    connect(this,&SeriesSetting::tableChanged,this,[=]{
        mCurrentSeries=mChart->series().at(0);
        mCurrentSeriesCombo->clear(); // clear会发出currentIndexChanged信号
        foreach(QAbstractSeries* series, mChart->series())
            mCurrentSeriesCombo->addItem(series->name()); // addItem也会发出currentIndexChanged信号
    });

    connect(mSeriesInfo,SIGNAL(nameChanged(const QString&,int)), //曲线改名要让选择曲线的combo同步更改
            this,SLOT(onNameChanged(const QString&,int)));
}

void SeriesSetting::initWhichSeries()
{
    QHBoxLayout * lay = new QHBoxLayout;
    mCurrentSeriesCombo = new QComboBox;
    foreach(QAbstractSeries* series, mChart->series()) mCurrentSeriesCombo->addItem(series->name());
    lay->addWidget(new QLabel(tr("切换曲线")));
    lay->addWidget(mCurrentSeriesCombo);
    mWhichSeries->setLayout(lay);
    mWhichSeries->setMinimumWidth(450);

    connect(mCurrentSeriesCombo,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,[=](int index){
            //qDebug()<<index<<"  "<<mChart->series().count(); // clear = -1    1
            if (index < 0) return; // clear会导致index=-1从而越界错误; addItem时再更新
            mCurrentSeries = mChart->series().at(index);
            mSeriesInfo->setCurrentSeries(mCurrentSeries,index);
            emit seriesChanged(index); // 通用设置切换当前曲线后告知LineSeriesSetting的特定设置进行更新
    });
}

void SeriesSetting::onNameChanged(const QString& name,int index)
{
    mCurrentSeriesCombo->setItemText(index,name);
}

void SeriesSetting::closeChildrenWindows()
{

}
