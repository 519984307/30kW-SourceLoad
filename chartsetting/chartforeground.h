#ifndef CHARTFOREGROUND_H
#define CHARTFOREGROUND_H

#include <chartsetting/chartbox.h>
#include <chartsetting/foregroundarea.h>
#include <chartsetting/foregroundborder.h>
#include <QCheckBox>

class ChartForeground : public ChartBox
{
    Q_OBJECT
public:
    explicit ChartForeground(QChart * chart, const QIcon&icon, QWidget*parent = Q_NULLPTR);
    void closeChindrenWindows();
private:
    ForegroundArea * mForegroundArea;
    ForegroundBorder * mForegroundBorder;
};

#endif // CHARTFOREGROUND_H
