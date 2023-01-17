#ifndef VALUEAXISRANGE_H
#define VALUEAXISRANGE_H

#include <axissetting/axisrange.h>

class ValueAxisRange : public AxisRange
{
    Q_OBJECT
public:
    explicit ValueAxisRange(QChart *,QAbstractAxis*,const QIcon&, QWidget*parent=Q_NULLPTR);
    void updateState() override;
};

#endif // VALUEAXISRANGE_H
