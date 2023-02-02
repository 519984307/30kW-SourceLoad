#ifndef ASSOCIATEAXIS_H
#define ASSOCIATEAXIS_H

#include <QGroupBox>
#include <QTableView>
#include <QtCharts>
#include <QButtonGroup>
#include <tool/tableviewmodel.h>
using namespace QtCharts;

class AssociateAxis : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateAxis(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
    enum AxisType {Value,Time,Log};
    QPoint axisType() const;
    QPointF axisBase() const;
    void setHorizontalEnabled(bool checked);
private:
    QTableView * mTableView;
    QChartView * mChartView;
    TableViewModel * mTableModel;
    QVBoxLayout * mLayout;
    QPoint mAxisType;
    QPointF mAxisBase;
private:
    void initHorizonLayout();
    void initVerticalLayout();
    QGroupBox * mHorizontalBox;
    QGroupBox * mVerticalBox;
    QRadioButton * mHorizontalValueAxis;
    QRadioButton * mHorizontalLogAxis;
    QRadioButton * mHorizontalTimeAxis;
    QDoubleSpinBox * mHorizontalLogBase;
    QRadioButton * mVerticalValueAxis;
    QRadioButton * mVerticalLogAxis;
    QDoubleSpinBox * mVerticalLogBase;
};

#endif // ASSOCIATEAXIS_H
