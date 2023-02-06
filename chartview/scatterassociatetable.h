#ifndef SCATTERASSOCIATETABLE_H
#define SCATTERASSOCIATETABLE_H

#include <QDialog>
#include <QVXYModelMapper>
#include <QLegendMarker>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chartview/associateaxis.h>
#include <chartview/associateseries.h>
#include <chartview/associatemode.h>

class ScatterAssociateTable : public QDialog
{
    Q_OBJECT
public:
    explicit ScatterAssociateTable(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QChartView *mChartView;
    QHash<QScatterSeries*,QPair<int,int>> mSeriesXYColumn;
    void initConnections();
    void onOkBtn();
    void singleMapping();
    void doubleMapping();
    void setHorizontalAxis(QScatterSeries*);
    void setVerticalAxis(QScatterSeries*);
private:
    QPushButton * mOkBtn;
    ChartShowLegend * mLegend;
    ChartShowTip * mTip;
    AssociateMode * mMode;
    AssociateSeries * mSeries;
    AssociateAxis * mAxis;
signals:
    void associateCompeleted();
    void tableChanged();
    void seriesColorChanged(QScatterSeries*);
    void seriesRemoved(QScatterSeries*);
};

#endif // SCATTERASSOCIATETABLE_H
