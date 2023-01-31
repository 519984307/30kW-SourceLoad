#ifndef SERIESLINE_H
#define SERIESLINE_H

#include <QGroupBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QtCharts>
#include <QFormLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QSpinBox>
#include <QDebug>

using namespace QtCharts;

class SeriesLine : public QGroupBox
{
    Q_OBJECT
public:
    explicit SeriesLine(QChart *,QWidget* = Q_NULLPTR);
    void setCurrentSeries(QLineSeries*,int);
    QLineSeries* currentSeries() const;
    void setCurrentSeriesId(int);
    int currentSeriesId() const;
    void updateState();
private:
    QChart * mChart;
    QLineSeries * mCurrentSeries;
    int mCurrentSeriesId;
    QIcon mIcon;

    QCheckBox * mPointVisible;
    QCheckBox * mPointLabelsVisible;
    QCheckBox * mPointLabelsClipping;

    QPushButton * mSetSeriesColor;
    QSpinBox * mSetSeriesWidth;

    QPushButton * mPointLabelsColor;
    QPushButton * mPointLabelsFont;
    QRadioButton * mPointFormatX;
    QRadioButton * mPointFormatY;
    QRadioButton * mPointFormatXY;
    QButtonGroup * mFormatGroup;

    QColorDialog* colorDialog(const QColor&);
    QFontDialog* fontDialog(const QFont&);
    QComboBox * brushStyleCombo(); // 曲线用不到

    void updatePointVisible();
    void updatePointLabelsVisible();
    void updatePointLabelsClipping();
    void updateColorState();
    void updateWidthState();
    void updatePointLabelsColor();
    void updatePointLabelsFont();
    void updatePointLabelsFormat();
private slots:
     void changePointVisible(int);
     void changePointLabelsVisible(int);
     void changePointLabelsClipping(int);
     void changeColor();
     void changeLabelColor();
     void changeLabelFont();
     void changeWidth(int);
     void changeFormat(int);
signals:
     void colorChanged(const QColor&);
};

#endif // SERIESLINE_H
