#ifndef LOGAXISRANGE_H
#define LOGAXISRANGE_H
#include <axissetting/axisrange.h>

class LogAxisRange : public AxisRange
{
    Q_OBJECT
public:
    explicit LogAxisRange(QChart *,QAbstractAxis*,const QIcon&, QWidget*parent=Q_NULLPTR);
    void updateState() override;
};

#endif // LOGAXISRANGE_H
