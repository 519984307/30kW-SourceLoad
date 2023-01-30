#ifndef AXISSETTING_H
#define AXISSETTING_H

#include <axissetting/axisinfo.h>
#include <axissetting/axistitle.h>
#include <axissetting/axislabel.h>
#include <axissetting/axisshade.h>
#include <axissetting/axisline.h>
#include <axissetting/axisgrid.h>
#include <axissetting/axisvalue.h>
#include <axissetting/axislog.h>

//QAbstractAxis具有的所有属性设置,以及Value/Log特有的根据轴类型动态切换
class AxisSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit AxisSetting(QChart*);
    void closeChildrenWindows();
private:
    QChart * mChart;
    QIcon mIcon;
    QAbstractAxis * mCurrentAxis;
    QRadioButton * mAxisX;
    QRadioButton * mAxisY;
    QGroupBox * mWhichAxis;
    void initWhichAxis();
    AxisInfo * mAxisInfo;
    AxisTitle * mAxisTitle;
    AxisLabel * mAxisLabel;
    AxisShade * mAxisShade;
    AxisLine * mAxisLine;
    AxisGrid * mAxisGrid;
    AxisValue * mAxisValue;
    AxisLog * mAxisLog;
signals:
    void tableChanged();
};
#endif // AXISSETTING_H
