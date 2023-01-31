#ifndef SERIESBOX_H
#define SERIESBOX_H

#include <QGroupBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QIcon>
#include <QLabel>
#include <QComboBox>
#include <QListWidget>
#include <QtCharts>
using namespace QtCharts;

class SeriesBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit SeriesBox(QChart * chart,QAbstractSeries*, const QIcon&icon, QWidget*parent = Q_NULLPTR);
    void setChart(QChart*);
    QChart* chart() const;
    void setCurrentSeries(QAbstractSeries*);
    QAbstractSeries * currentSeries() const;
    QColorDialog* colorDialog(const QColor&);
    QFontDialog* fontDialog(const QFont&);
    QComboBox * brushStyleCombo();
protected:
    QChart * mChart;
    QAbstractSeries * mCurrentSeries;
    QIcon mIcon;
    virtual void updateState(){};
};

#endif // SERIESBOX_H
