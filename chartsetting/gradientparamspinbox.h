#ifndef GRADIENTPARAMSPINBOX_H
#define GRADIENTPARAMSPINBOX_H

#include <QDoubleSpinBox>
#include <QWheelEvent>

class GradientParamSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit GradientParamSpinBox(QWidget*parent=Q_NULLPTR);
    void wheelEvent(QWheelEvent*) override;
};
#endif // GRADIENTPARAMSPINBOX_H
