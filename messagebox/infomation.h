#ifndef INFOMATION_H
#define INFOMATION_H

#include <messagebox/messagebox.h>

class Infomation : public Messagebox
{
    Q_OBJECT
private:
    typedef void (Infomation::*ButtonSlotClassFunc)();
    void test();
    void setSlotClassFunction(ButtonSlotClassFunc, int); // 内部使用不被继承
public:
    explicit Infomation();
};

#endif // INFOMATION_H
