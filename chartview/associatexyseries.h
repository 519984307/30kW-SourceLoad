#ifndef ASSOCIATEXYSERIES_H
#define ASSOCIATEXYSERIES_H

#include <QGroupBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QColorDialog>
#include <QFormLayout>

class AssociateXYSeries : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateXYSeries(QWidget*parent = Q_NULLPTR);
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

#endif // ASSOCIATEXYSERIES_H
