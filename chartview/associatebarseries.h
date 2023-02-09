#ifndef ASSOCIATEBARSERIES_H
#define ASSOCIATEBARSERIES_H

#include <QGroupBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QColorDialog>
#include <QFormLayout>

class AssociateBarSeries : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateBarSeries(QWidget*parent = Q_NULLPTR);
    QColor barcolor() const;
    double barwidth() const;
    void setBarColorEnabled(bool);
private:
    QColor mBarColor;
    double mBarWidth;
private:
    QDoubleSpinBox * mBarWidthSpin;
    QPushButton * mBarColorBtn;
    QLineEdit * mBarColorEdit;
};

#endif // ASSOCIATEBARSERIES_H
