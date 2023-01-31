#ifndef SERIESSETTING_H
#define SERIESSETTING_H

#include <seriessetting/seriesinfo.h>

class SeriesSetting : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit SeriesSetting(QChart*);
    void closeChildrenWindows();
private:
    QIcon mIcon;
    QChart * mChart;
    QAbstractSeries * mCurrentSeries;
    QGroupBox * mWhichSeries;
    QComboBox * mCurrentSeriesCombo;
    void initWhichSeries();
    SeriesInfo * mSeriesInfo;
private slots:
    void onNameChanged(const QString&,int);
signals:
    void tableChanged();
    void seriesChanged(int);
};

#endif // SERIESSETTING_H
