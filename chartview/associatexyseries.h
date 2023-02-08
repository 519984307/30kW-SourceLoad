#ifndef ASSOCIATESERIES_H
#define ASSOCIATESERIES_H

#include <QGroupBox>
#include <QDoubleSpinBox>
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
    double markersize() const;
    void setLineWidthVisible(bool);
    void setMarkerSizeVisible(bool);
private:
    QColor mLineColor;
    int mLineWidth;
    double mMarkerSize;
private:
    QSpinBox * mLineWidthSpin;
    QDoubleSpinBox * mMarkerSizeSpin;
    QPushButton * mLineColorBtn;
    QLineEdit * mLineColorEdit;
};

#endif // ASSOCIATESERIES_H
