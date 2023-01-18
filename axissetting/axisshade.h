#ifndef AXISSHADE_H
#define AXISSHADE_H

#include <axissetting/axisbox.h>
#include <QFormLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>

class AxisShade : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisShade(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
    void updateState() override;
private:
    QCheckBox * mAxisShadeVisibility;
    QPushButton * mAxisShadeBorderColor;
    QPushButton * mAxisShadeBrushColor;
    QSpinBox * mAxisShadePenWidth;
    QComboBox * mAxisShadeBrushStyle;
    void updateVisibilityState();
    void updateBorderColorState();
    void updateBrushColorState();
    void updateBrushStyleState();
    void updatePenWidthState();
private slots:
    void changeVisibility(int);
    void changeBorderColor();
    void changeBrushColor();
    void changeBrushStyle(int);
    void changePenWidth(int);
};

#endif // AXISSHADE_H
