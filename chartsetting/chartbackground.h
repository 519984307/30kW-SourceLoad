#ifndef CHARTBACKGROUND_H
#define CHARTBACKGROUND_H

#include <chartsetting/chartbox.h>
#include <chartsetting/backgroundborder.h>
#include <chartsetting/backgroundarea.h>

class ChartBackground : public ChartBox
{
    Q_OBJECT
public:
    explicit ChartBackground(QChart * chart, const QIcon&icon, QWidget*parent = Q_NULLPTR);
    void closeChindrenWindows();
private:
    BackgroundArea * mBackgroundArea;
    BackgroundBorder * mBackgroundBorder;
};

#endif // CHARTBACKGROUND_H
