#ifndef AXISSETTING_H
#define AXISSETTING_H

#include <axissetting/axisinfo.h>
#include <axissetting/axistitle.h>
#include <axissetting/axislabel.h>

//QAbstractAxis具有的所有属性设置,所有子类均可继承
class AxisSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit AxisSetting(QChart*);
    void closeChildrenWindows();
private:
    QChart * mChart;
    QRadioButton * mAxisX;
    QRadioButton * mAxisY;
    QGroupBox * mWhichAxis;
    void initWhichAxis();
    AxisInfo * mAxisInfo;
    AxisTitle * mAxisTitle;
    AxisLabel * mAxisLabel;
};
#endif // AXISSETTING_H
