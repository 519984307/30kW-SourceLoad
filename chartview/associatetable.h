#ifndef ASSOCIATETABLE_H
#define ASSOCIATETABLE_H

#include <QDialog>
#include <QTableView>
#include <QChartView>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVXYModelMapper>
#include <QLineSeries>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QLegendMarker>
#include <QDebug>
#include <tool/tableviewmodel.h>
using namespace QtCharts;

class AssociateTable : public QDialog
{
    Q_OBJECT
public:
    explicit AssociateTable(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QChartView *mChartView;
    QGraphicsSimpleTextItem * mCoordTip;
    QGraphicsRectItem * mCoordRect;
    void initConnections();
    void onOkBtn();
    void singleMapping();
    void doubleMapping();
    void showToolTip(QPointF point, bool state);
    void legendMarkerClicked();
private:
    QGroupBox * mAssociateModeBox;
    QRadioButton * mSingleBtn;
    QRadioButton * mDoubleBtn;
    QGroupBox * mSingleAssociateBox;
    QSpinBox * mSingleSpin;
    QGroupBox * mDoubleAssociateBox;
    QSpinBox * mDoubleSpinX;
    QSpinBox * mDoubleSpinY;
    QPushButton * mOkBtn;
signals:
    void tableChanged();
};

#endif // ASSOCIATETABLE_H
