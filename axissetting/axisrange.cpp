#include <axissetting/axisrange.h>

AxisRange::AxisRange(QChart * chart,QAbstractAxis*axis,const QIcon&icon, QWidget*parent):
    AxisBox(chart,axis,icon,parent)
{ // 不同的轴设置范围的方式不同,要重载
        mainLayout = new QVBoxLayout;
        setTitle(tr("轴范围"));
        setLayout(mainLayout);
}
