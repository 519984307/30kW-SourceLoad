#ifndef ASSOCIATEXYAXIS_H
#define ASSOCIATEXYAXIS_H

#include <QGroupBox>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>

class AssociateXYAxis : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateXYAxis(QWidget*parent = Q_NULLPTR);
    enum AxisType {Value,Log};
    QPoint axisType() const;
    QPointF axisBase() const;
    void setHorizontalEnabled(bool);
private:
    QVBoxLayout * mLayout;
    QPoint mAxisType;
    QPointF mAxisBase;
private:
    void initHorizonLayout();
    void initVerticalLayout();
    QGroupBox * mHorizontalBox;
    QGroupBox * mVerticalBox;
    QRadioButton * mHorizontalValueAxis;
    QRadioButton * mHorizontalLogAxis;
    QRadioButton * mHorizontalTimeAxis;
    QDoubleSpinBox * mHorizontalLogBase;
    QRadioButton * mVerticalValueAxis;
    QRadioButton * mVerticalLogAxis;
    QDoubleSpinBox * mVerticalLogBase;
};

#endif // ASSOCIATEXYAXIS_H
