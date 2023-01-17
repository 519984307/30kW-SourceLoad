#include <axissetting/axissetting.h>

AxisSetting::AxisSetting(QChart*chart):mChart(chart)
{
    setObjectName("AxisSettingsLayout");
    QIcon icon(":/images/toolbox_axis.png");

    mWhichAxis = new QGroupBox;
    mAxisInfo = new AxisInfo(mChart,mChart->axisX(),icon); // 默认x为操作轴
    mAxisTitle = new AxisTitle(mChart,mChart->axisX(),icon);
    mAxisLabel = new AxisLabel(mChart,mChart->axisX(),icon);

    initWhichAxis(); // 最后初始化

    addWidget(mWhichAxis );
    addWidget(mAxisInfo);
    addWidget(mAxisTitle);
    addWidget(mAxisLabel);
}

void AxisSetting::closeChildrenWindows()
{

}

void AxisSetting::initWhichAxis()
{ // operate which axis?
    mAxisX = new QRadioButton(tr("X轴"));
    mAxisY = new QRadioButton(tr("Y轴"));
    QButtonGroup * group = new QButtonGroup;
    group->addButton(mAxisX,1);
    group->addButton(mAxisY,2);
    mAxisX->setChecked(true); // 默认操作x轴

    QHBoxLayout * lay = new QHBoxLayout;
    lay->addWidget(mAxisX);
    lay->addWidget(mAxisY);
    mWhichAxis ->setLayout(lay);
    mWhichAxis->setTitle(tr("当前轴"));

    connect(group,static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            this,[=](int id){
            if (id == 1){ // X轴操作
                mAxisInfo->setCurrentAxis(mChart->axisX());
                mAxisTitle->setCurrentAxis(mChart->axisX());
                mAxisLabel->setCurrentAxis(mChart->axisX());
            }
            else { // Y轴操作
                mAxisInfo->setCurrentAxis(mChart->axisY());
                mAxisTitle->setCurrentAxis(mChart->axisY());
                mAxisLabel->setCurrentAxis(mChart->axisY());
            }
            mAxisInfo->updateState(); // 必须调用更新转换当前轴的状态
            mAxisTitle->updateState();
            mAxisLabel->updateState();
    });
}
