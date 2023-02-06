#ifndef SERIESSCATTER_H
#define SERIESSCATTER_H

#include <QGroupBox>
#include <QColorDialog>
#include <QIcon>
#include <QComboBox>
#include <QtCharts>
#include <QFormLayout>
#include <QPushButton>
#include <QDoubleSpinBox>

using namespace QtCharts;

class SeriesScatter : public QGroupBox
{
    Q_OBJECT
public:
    explicit SeriesScatter(QChart *,QWidget* = Q_NULLPTR);
    void setCurrentSeries(QScatterSeries*,int);
    QScatterSeries* currentSeries() const;
    void setCurrentSeriesId(int);
    int currentSeriesId() const;
    void updateState();
private:
    QChart * mChart;
    QScatterSeries * mCurrentSeries;
    int mCurrentSeriesId;
    QIcon mIcon;

    QComboBox * mMarkerShape;
    QDoubleSpinBox * mMarkerSize;
    QPushButton * mBorderColor;
    QPushButton * mFillColor;

    void updateMarkerShape();
    void updateMarkerSize();
    void updateBorderColor();
    void updateFillColor();

    QColorDialog* colorDialog(const QColor&);
private slots:
     void changeShape(int);
     void changeSize(double);
     void changeBorderColor();
     void changeFillColor();
signals:
     void seriesColorChanged(QScatterSeries*);
};

#endif // SERIESSCATTER_H
