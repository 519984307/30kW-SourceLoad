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
    QPushButton * mRemoveSeriesBtn;
    void initWhichSeries();
    SeriesInfo * mSeriesInfo;
private slots:
    void onNameChanged(const QString&,int);
signals:
    void associateCompeleted();
    void seriesToggled(int);
    void seriesRemoved(int);
    void seriesRemoved(QAbstractSeries*);
};

#endif // SERIESSETTING_H
