#ifndef CRITICAL_H
#define CRITICAL_H

#include <messagebox/messagebox.h>

class Critical : public Messagebox
{
    Q_OBJECT
    typedef void (Critical::*ButtonSlotClassFunc)();
    void setSlotClassFunction(ButtonSlotClassFunc, int); // 内部使用不被继承
public:
    explicit Critical();
};

#endif // CRITICAL_H
