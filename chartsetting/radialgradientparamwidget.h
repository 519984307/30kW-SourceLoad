#ifndef RADIALGRADIENTPARAMWIDGET_H
#define RADIALGRADIENTPARAMWIDGET_H

#include <chartsetting/gradientparamwidget.h>
#include <chartsetting/gradientparamspinbox.h>
#include <QFormLayout>
#include <QHash>
#include <QCheckBox>

class RadialGradientParamWidget : public GradientParamWidget
{
    Q_OBJECT
public:
    typedef QHash<QString,qreal> RadialParam;
    explicit RadialGradientParamWidget(QWidget*parent = Q_NULLPTR);
private:
    RadialParam mRadialParam;
    bool mIsRealTime;
signals:
    void radialGradientParams(RadialParam,bool isRealTime=true,bool isBtn=true);
};

#endif // RADIALGRADIENTPARAMWIDGET_H
