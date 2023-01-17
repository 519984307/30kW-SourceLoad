#ifndef LINECHARTTOOL_H
#define LINECHARTTOOL_H

#include <charttool/charttool.h>
#include <axissetting/lineaxissetting.h>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

class LineChartTool : public ChartTool
{
    Q_OBJECT
public:
    explicit LineChartTool(QChart* chart,QWidget*parent=Q_NULLPTR);
private:
    LineAxisSetting * mLineAxisSetting;
};
#endif // LINECHARTTOOL_H
