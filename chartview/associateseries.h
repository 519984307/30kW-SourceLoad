#ifndef ASSOCIATESERIES_H
#define ASSOCIATESERIES_H

#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QColorDialog>
#include <QFormLayout>

class AssociateSeries : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateSeries(QWidget*parent = Q_NULLPTR);
    QColor linecolor() const;
    int linewidth() const;
private:
    QColor mLineColor;
    int mLineWidth;
private:
    QSpinBox * mLineWidthSpin;
    QPushButton * mLineColorBtn;
    QLineEdit * mLineColorEdit;
};

#endif // ASSOCIATESERIES_H
