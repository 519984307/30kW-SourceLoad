#ifndef AXISGRID_H
#define AXISGRID_H
#include <axissetting/axisbox.h>
#include <QFormLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>

class AxisGrid : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisGrid(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
private:
    void updateState() override;
    QCheckBox * mAxisGridVisibility;
    QPushButton * mAxisGridColor;
    QSpinBox * mAxisGridWidth;
    QCheckBox * mAxisMinorGridVisibility;
    QPushButton * mAxisMinorGridColor;
    QSpinBox * mAxisMinorGridWidth;
    void updateVisibilityState();
    void updateColorState();
    void updatePenWidthState();
private slots:
    void changeMasterVisibility(int);
    void changeMinorVisibility(int);
    void changeMasterColor();
    void changeMinorColor();
    void changeMasterPenWidth(int);
    void changeMinorPenWidth(int);
};
#endif // AXISGRID_H
