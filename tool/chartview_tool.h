#ifndef CHARTVIEWWIDGET_H
#define CHARTVIEWWIDGET_H

#include <chart/linechart.h>
#include <chart/scatterchart.h>
#include <chart/barchart.h>
#include <QtConcurrent/QtConcurrent>
using namespace  QtConcurrent;

class ChartViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChartViewWidget(QWidget *parent = Q_NULLPTR);
    void closeEvent(QCloseEvent *) override;
private:
    void init();
    void initConnections();
    QGridLayout * mLayout;
    QTableView * mTableView;
    TableViewModel * mTableModel;
    QPushButton * mImportFileBtn;
    QCheckBox * mImportHeaderBtn;
    QTabWidget * mTab;
    LineChart * mLineTab;
    ScatterChart * mScatterTab;
    BarChart * mBarTab;
signals:
    void tableChanged();
};

#endif // CHARTVIEWWIDGET_H
