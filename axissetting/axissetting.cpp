#include <axissetting/axissetting.h>

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

    mAxisValue = new AxisValue(mChart); //初始化布局,根据当前轴类型动态的显示和隐藏
    mAxisLog = new AxisLog(mChart);
    mAxisBar = new AxisBarCategory(mChart);
    mAxisTime = new AxisTime(mChart);


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
    addWidget(mAxisBar);
    addWidget(mAxisTime);
    addWidget(new QGroupBox);//为了防止挤压尾部留些空间

    //通过removeWidget和addWidget动态切换轴有点难
    // 而且由于QScrollArea布局必须事先确定的问题,不可能实现
    // 但是可以通过hide和show来显示这种效果,布局也已经事先确定了
    switch (mCurrentAxis->type()) {
            case QAbstractAxis::AxisTypeValue:
                    mAxisValue->setCurrentAxis(static_cast<QValueAxis*>(mCurrentAxis)); // 确实是value类型才会初始化内部的信号连接
                    mAxisLog->hide();
                    mAxisBar->hide();
                    mAxisTime->hide();
                    break;
            case QAbstractAxis::AxisTypeLogValue:
                    mAxisValue->hide();
                    mAxisLog->setCurrentAxis(static_cast<QLogValueAxis*>(mCurrentAxis));
                    mAxisBar->hide();
                    mAxisTime->hide();
                    break;
            case QAbstractAxis::AxisTypeBarCategory:
                    mAxisValue->hide();
                    mAxisLog->hide();
                    mAxisBar->setCurrentAxis(static_cast<QBarCategoryAxis*>(mCurrentAxis));
                    mAxisTime->hide();
                    break;
            case QAbstractAxis::AxisTypeDateTime:
                    mAxisValue->hide();
                    mAxisLog->hide();
                    mAxisBar->hide();
                    mAxisTime->setCurrentAxis(static_cast<QDateTimeAxis*>(mCurrentAxis));
                    break;
            default:break;
    }

    connect(this,&AxisSetting::associateCompeleted,this,[=]{mAxisX->click();});// 表格关联完成当前曲线变化导致其携带的当前轴可能变化故要更新

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
    mWhichAxis->setMinimumWidth(450);

    connect(group,static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            this,[=](int id){
            if (id == 1)  mCurrentAxis = mChart->axisX();// 对X轴操作
            else mCurrentAxis = mChart->axisY(); // Y轴操作

            // 清除所有曲线时会导致返回的轴是空指针,提前返回,因为下边的groupbox不允许空指针
            if (mCurrentAxis == nullptr) return;

            mAxisInfo->setCurrentAxis(mCurrentAxis);
            mAxisTitle->setCurrentAxis(mCurrentAxis);
            mAxisLabel->setCurrentAxis(mCurrentAxis);
            mAxisShade->setCurrentAxis(mCurrentAxis);
            mAxisLine->setCurrentAxis(mCurrentAxis);
            mAxisGrid->setCurrentAxis(mCurrentAxis);

            // 和共有的工具不同,这2个要有条件的setCurrentAxis
            switch (mCurrentAxis->type()) { // 无论切换的X还是Y,类型都可能是Value或Log,都要去判断,只要是value类型就让value布局显示
                    case QAbstractAxis::AxisTypeValue:
                            mAxisValue->setCurrentAxis(static_cast<QValueAxis*>(mCurrentAxis));
                            mAxisValue->show();
                            mAxisLog->hide();
                            mAxisBar->hide();
                            mAxisTime->hide();
                            break;
                    case QAbstractAxis::AxisTypeLogValue:
                            mAxisLog->setCurrentAxis(static_cast<QLogValueAxis*>(mCurrentAxis));
                            mAxisValue->hide();
                            mAxisLog->show();
                            mAxisBar->hide();
                            mAxisTime->hide();
                            break;
                    case QAbstractAxis::AxisTypeBarCategory:
                            mAxisBar->setCurrentAxis(static_cast<QBarCategoryAxis*>(mCurrentAxis));
                            mAxisValue->hide();
                            mAxisLog->hide();
                            mAxisBar->show();
                            mAxisTime->hide();
                            break;
                    case QAbstractAxis::AxisTypeDateTime:
                            mAxisTime->setCurrentAxis(static_cast<QDateTimeAxis*>(mCurrentAxis));
                            mAxisValue->hide();
                            mAxisLog->hide();
                            mAxisBar->hide();
                            mAxisTime->show();
                            break;
                    default:break;
            }
    });
}
