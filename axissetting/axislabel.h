#ifndef AXISLABEL_H
#define AXISLABEL_H

#include <axissetting/axisbox.h>
#include <chartsetting/gradientparamspinbox.h>
#include <QFormLayout>
#include <QPushButton>
#include <QCheckBox>

class AxisLabel : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisLabel(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
private:
    void updateState() override;
    QCheckBox * mAxisLabelVisibility;
    GradientParamSpinBox * mAxisLabelAngle;// 借助内部重载的wheelEvent
    QPushButton * mAxisLabelColor;
    QComboBox * mAxisLabelBrush;
    QPushButton * mAxisLabelFont;
    void updateVisibilityState();
    void updateAngleState();
    void updateColorState();
    void updateBrushState();
    void updateFontState();
private slots:
    void changeVisibility(int);
    void changeAngle(double);
    void changeColor();
    void changeBrush(int);
    void changeFont();
};

#endif // AXISLABEL_H
