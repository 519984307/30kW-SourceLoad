#include <axissetting/axislog.h>

AxisLog::AxisLog(QChart * chart,QAbstractAxis*axis,const QIcon&icon, QWidget*parent):
    AxisBox(chart,axis,icon,parent)
{
    mAxisBase = new QGroupBox(tr("底数"));
    QSpinBox * base = new QSpinBox;
    base->setRange(2,10);
    QFormLayout * blay = new QFormLayout;
    blay->addWidget(base);
    mAxisBase->setLayout(blay);

    mAxisRange = new QGroupBox(tr("轴范围"));
    QFormLayout * rlay = new QFormLayout;
    QDoubleSpinBox * minRange = new QDoubleSpinBox;
    QDoubleSpinBox * maxRange = new QDoubleSpinBox;
    rlay->addRow(tr("&上限"),minRange);
    rlay->addRow(tr("&下限"),maxRange);
    mAxisRange->setLayout(rlay);


    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(mAxisBase);
    lay->addWidget(mAxisRange);
    setLayout(lay);

    // 信号槽函数的连接根据是否QValueAxis类型来初始化
    if (axis->type() != QAbstractAxis::AxisTypeLogValue) return;
    mLogAxis = static_cast<QLogValueAxis*>(mCurrentAxis);
    initConnections();
}

void AxisLog::updateState()
{

}

void AxisLog::initConnections()
{

}
