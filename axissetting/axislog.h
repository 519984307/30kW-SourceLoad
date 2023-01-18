#ifndef AXISLOG_H
#define AXISLOG_H

#include <axissetting/axisbox.h>
#include <QFormLayout>
#include <QValueAxis>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLogValueAxis>

class AxisLog : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisLog(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
private:
    void updateState() override;
    void initConnections();
    QGroupBox * mAxisBase;
    QGroupBox * mAxisRange;
    QGroupBox * mAxisTickCount;
    QGroupBox * mAxisLabelFormat;
    QLogValueAxis * mLogAxis;
};

#endif // AXISLOG_H
