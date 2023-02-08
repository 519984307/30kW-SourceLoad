#include <chartview/barchartbar.h>

BarChartBar::BarChartBar(QTableView*tableview,QChartView* chartview,QWidget*parent):
    ChartBar(tableview,chartview,parent)
{
    mAssociateTable = new BarAssociateTable(tableview,chartview);

    connect(mAssociatetableAct,&QAction::triggered,this,[=]{ mAssociateTable->exec();});// 不同基类不同
    connect(this,&BarChartBar::tableChanged,mAssociateTable,&BarAssociateTable::tableChanged);
//    connect(this,SIGNAL(seriesColorChanged(QLineSeries*)),mAssociateTable,SIGNAL(seriesColorChanged(QLineSeries*)));
//    connect(this,SIGNAL(seriesRemoved(QLineSeries*)),mAssociateTable,SIGNAL(seriesRemoved(QLineSeries*)));
    connect(mAssociateTable,&BarAssociateTable::associateCompeleted,this,&BarChartBar::associateCompeleted);
}
