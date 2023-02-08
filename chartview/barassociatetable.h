#ifndef BARASSOCIATETABLE_H
#define BARASSOCIATETABLE_H

#include <QDialog>
#include <QLegendMarker>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chartview/associatebarmode.h>
#include <chartview/associatebarseries.h>
#include <chartview/associatebaraxis.h>

class BarAssociateTable : public QDialog
{
    Q_OBJECT
public:
    explicit BarAssociateTable(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    void initConnections();
    void onOkBtn();
    void nonRegionMapping();
    void rectMapping();
    void setAxisX(QBarSeries*,const QStringList&);
    void setAxisY(QBarSeries*);
    QStringList nonRegionCategories() const;
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QChartView *mChartView;
    QPushButton * mOkBtn;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
    AssociateBarMode * mMode;
    AssociateBarSeries * mSeries;
    AssociateBarAxis * mAxis;
signals:
    void associateCompeleted();
    void tableChanged();
};

#endif // BARASSOCIATETABLE_H
