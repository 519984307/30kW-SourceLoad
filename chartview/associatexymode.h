#ifndef ASSOCIATEMODE_H
#define ASSOCIATEMODE_H

#include <QGroupBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QTableView>
#include <QChartView>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <tool/tableviewmodel.h>
using namespace QtCharts;

class AssociateMode : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateMode(QTableView*,QChartView*,QWidget*parent =Q_NULLPTR);
    bool isSingle() const;
    void adjustRange();
    int singleCol();
    QPoint doubleCols();
private:
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QChartView *mChartView;
    QGroupBox * mAssociateModeBox;
    QRadioButton * mSingleBtn;
    QRadioButton * mDoubleBtn;
    QGroupBox * mSingleAssociateBox;
    QSpinBox * mSingleSpin;
    QGroupBox * mDoubleAssociateBox;
    QSpinBox * mDoubleSpinX;
    QSpinBox * mDoubleSpinY;
signals:
      void changeMode(bool);
};

#endif // ASSOCIATEMODE_H
