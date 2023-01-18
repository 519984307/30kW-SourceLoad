#include <axissetting/axissetting.h>
#include <QDebug>

AxisSetting::AxisSetting(QChart*chart):mChart(chart)
{
    setObjectName("AxisSettingsLayout");
    mIcon.addFile(":/images/toolbox_axis.png");
    mCurrentAxis = mChart->axisX();// 默认X为操作轴

    mWhichAxis = new QGroupBox;
    mAxisInfo = new AxisInfo(mChart,mCurrentAxis,mIcon);
    mAxisTitle = new AxisTitle(mChart,mCurrentAxis,mIcon);
    mAxisLabel = new AxisLabel(mChart,mCurrentAxis,mIcon);
    mAxisShade = new AxisShade(mChart,mCurrentAxis,mIcon);
    mAxisLine = new AxisLine(mChart,mCurrentAxis,mIcon);
    mAxisGrid = new AxisGrid(mChart,mCurrentAxis,mIcon);

    //mCurrentAxis可能是任何类型,无论是否匹配都至少会把布局初始化完成
    mAxisValue = new AxisValue(mChart,mCurrentAxis,mIcon);
    mAxisLog = new AxisLog(mChart,mCurrentAxis,mIcon);

    initWhichAxis();

    addWidget(mWhichAxis);
    addWidget(mAxisInfo);
    addWidget(mAxisTitle);
    addWidget(mAxisLabel);
    addWidget(mAxisShade);
    addWidget(mAxisLine);
    addWidget(mAxisGrid);
    addWidget(mAxisValue);
    addWidget(mAxisLog);

    //通过removeWidget和addWidget动态切换mAxisValue和mAxisLog有点难
    // 而且由于QScrollArea布局必须事先确定的问题,不可能实现
    // 但是可以通过hide和show来显示这种效果,布局也已经事先确定了
    switch (mCurrentAxis->type()) {
            case QAbstractAxis::AxisTypeValue:
                    mAxisLog->hide();
                    break;
            case QAbstractAxis::AxisTypeLogValue:
                    mAxisValue->hide();
            default:break;
    }

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
            if (id == 1)  mCurrentAxis = mChart->axisX();// 对X轴操作
            else mCurrentAxis = mChart->axisY(); // Y轴操作

            switch (mCurrentAxis->type()) {
                    case QAbstractAxis::AxisTypeValue:
                            //mAxisValue->setCurrentAxis(mCurrentAxis); // 必须符合类型才能设置
                            mAxisValue->show();
                            mAxisLog->hide();
                            break;
                    case QAbstractAxis::AxisTypeLogValue:
                            //mAxisLog->setCurrentAxis(mCurrentAxis);
                            mAxisValue->hide();
                            mAxisLog->show();
                    default:break;
            }

            mAxisInfo->setCurrentAxis(mCurrentAxis);
            mAxisTitle->setCurrentAxis(mCurrentAxis);
            mAxisLabel->setCurrentAxis(mCurrentAxis);
            mAxisShade->setCurrentAxis(mCurrentAxis);
            mAxisLine->setCurrentAxis(mCurrentAxis);
            mAxisGrid->setCurrentAxis(mCurrentAxis);
    });
}
