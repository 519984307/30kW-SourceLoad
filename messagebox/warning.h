#ifndef WARINGING_H
#define WARINGING_H

#include <messagebox/messagebox.h>

class Warning : public Messagebox
{
    Q_OBJECT
    typedef void (Warning::*ButtonSlotClassFunc)();
    void setSlotClassFunction(ButtonSlotClassFunc, int); // 内部使用不被继承
public:
    explicit Warning();
};

#endif // WARINGING_H
