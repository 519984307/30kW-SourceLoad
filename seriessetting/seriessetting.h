#ifndef SERIESSETTING_H
#define SERIESSETTING_H

#include <QVBoxLayout>
#include <QtCharts>
using namespace QtCharts;

class SeriesSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit SeriesSetting(QChart*);
    void closeChildrenWindows();
private:
    QChart * mChart;
    QIcon mIcon;
signals:
    void tableChanged();
};

#endif // SERIESSETTING_H
