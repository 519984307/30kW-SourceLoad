#ifndef LINEAXISSETTING_H
#define LINEAXISSETTING_H

#include <axissetting/axissetting.h>

class LineAxisSetting : public AxisSetting
{
    Q_OBJECT
public:
    explicit LineAxisSetting(QChart*);
};

#endif // LINEAXISSETTING_H
