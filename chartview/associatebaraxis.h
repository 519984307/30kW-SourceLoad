#ifndef ASSOCIATEBARAXIS_H
#define ASSOCIATEBARAXIS_H

#include <QGroupBox>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>

class AssociateBarAxis: public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateBarAxis(QWidget*parent=Q_NULLPTR);
    double base() const;
    bool isValueAxis() const;
    bool isLogAxis() const;
private:
    QRadioButton * mValue;
    QRadioButton * mLog;
    QDoubleSpinBox * mBase;
    double mBaseVal;
};

#endif // ASSOCIATEBARAXIS_H
