#ifndef AXISVALUE_H
#define AXISVALUE_H

#include <axissetting/axisbox.h>
#include <QFormLayout>
#include <QValueAxis>
#include <QDoubleSpinBox>
#include <QComboBox>

// 作为widget被axissettingvalue(layout)使用
class AxisValue: public AxisBox
{
    Q_OBJECT
public:
    explicit AxisValue(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
private:
    void updateState() override;
    void initConnections();
    QGroupBox * mAxisRange;
    QGroupBox * mAxisTickCount;
    QGroupBox * mAxisLabelFormat;
    QValueAxis * mValueAxis;
};

#endif // AXISVALUE_H
