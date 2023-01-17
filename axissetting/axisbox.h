#ifndef AXISBOX_H
#define AXISBOX_H

#include <QGroupBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QIcon>
#include <QLabel>
#include <QComboBox>
#include <QListWidget>
#include <QtCharts/QChart>
using namespace QtCharts;

// 和chartbox完全一样,只是为了对称性保持风格一致
class AxisBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit AxisBox(QChart * chart,QAbstractAxis*, const QIcon&icon, QWidget*parent = Q_NULLPTR);
    void setChart(QChart*);
    QChart* chart() const;
    void setCurrentAxis(QAbstractAxis*);
    QAbstractAxis * currentAxis() const;
    QColorDialog* colorDialog(const QColor&);
    QFontDialog* fontDialog(const QFont&);
    QComboBox * brushStyleCombo();
    virtual void updateState(){};
protected:
    QChart * mChart;
    QAbstractAxis * mCurrentAxis;
    QIcon mIcon;

};

#endif // AXISBOX_H
