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
#include <chart/linechart.h>

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
    QTableView * mTable;
    QPushButton * mImportLogBtn;
    QPushButton * mImportFileBtn;
    QTabWidget * mTab;
    LineChart * mLineTab;
};

#endif // CHARTVIEWWIDGET_H
