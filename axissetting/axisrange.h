#ifndef AXISRANGE_H
#define AXISRANGE_H

#include <axissetting/axisbox.h>
#include <QVBoxLayout>
class AxisRange : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisRange(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
    void updateState() override {};
protected:
    QVBoxLayout * mainLayout;
};

#endif // AXISRANGE_H
