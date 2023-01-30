#ifndef CHARTVIEWWIDGET_H
#define CHARTVIEWWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QTableView>
#include <QTabWidget>
#include <QItemSelectionModel>
#include <chart/linechart.h>
#include <tool/tableviewmodel.h>
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
};

#endif // CHARTVIEWWIDGET_H
