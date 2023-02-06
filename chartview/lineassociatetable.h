#ifndef LINEASSOCIATETABLE_H
#define LINEASSOCIATETABLE_H

#include <QDialog>
#include <QVXYModelMapper>
#include <QLegendMarker>
#include <chart/chartshowtip.h>
#include <chart/chartshowlegend.h>
#include <chartview/associateaxis.h>
#include <chartview/associateseries.h>
#include <chartview/associatemode.h>

class LineAssociateTable : public QDialog
{
    Q_OBJECT
public:
    explicit LineAssociateTable(QTableView*,QChartView*,QWidget*parent = Q_NULLPTR);
private:
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QChartView *mChartView;
    QHash<QLineSeries*,QPair<int,int>> mSeriesXYColumn;
    void initConnections();
    void onOkBtn();
    void singleMapping();
    void doubleMapping();
    void setHorizontalAxis(QLineSeries*);
    void setVerticalAxis(QLineSeries*);
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
    void seriesColorChanged(QLineSeries*);
    void seriesRemoved(QLineSeries*);
};

#endif // LINEASSOCIATETABLE_H
