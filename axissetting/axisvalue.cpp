#include <axissetting/axisvalue.h>

AxisValue::AxisValue(QChart * chart,QAbstractAxis*axis,const QIcon&icon, QWidget*parent):
    AxisBox(chart,axis,icon,parent)
{
     // 针对QValueAxis使用,tickcount,labelformat,range,
    mAxisRange = new QGroupBox(tr("轴范围"));
    QFormLayout * rlay = new QFormLayout;
    QDoubleSpinBox * minRange = new QDoubleSpinBox;
    QDoubleSpinBox * maxRange = new QDoubleSpinBox;
    rlay->addRow(tr("&上限"),minRange);
    rlay->addRow(tr("&下限"),maxRange);
    mAxisRange->setLayout(rlay);

    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(mAxisRange);
    setLayout(lay); // 布局不影响先初始化完毕

    // 信号槽函数的连接根据是否QValueAxis类型来初始化
    if (axis->type() != QAbstractAxis::AxisTypeValue) return;
    mValueAxis = static_cast<QValueAxis*>(mCurrentAxis);
    initConnections();
}

void AxisValue::initConnections()
{

}


void AxisValue::updateState()
{

}
