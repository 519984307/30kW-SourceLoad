#include <chartview/scatterchartbar.h>

ScatterChartBar::ScatterChartBar(QTableView*tableview,QChartView* chartview,QWidget*parent):
    ChartBar(tableview,chartview,parent)
{
    mAssociateTable = new ScatterAssociateTable(tableview,chartview);

    connect(mAssociatetableAct,&QAction::triggered,this,[=]{ mAssociateTable->exec();});// 不同基类不同
    connect(this,&ScatterChartBar::tableChanged,mAssociateTable,&ScatterAssociateTable::tableChanged);
    connect(this,SIGNAL(seriesColorChanged(QScatterSeries*)),mAssociateTable,SIGNAL(seriesColorChanged(QScatterSeries*)));
    connect(this,SIGNAL(seriesRemoved(QScatterSeries*)),mAssociateTable,SIGNAL(seriesRemoved(QScatterSeries*)));
    connect(mAssociateTable,&ScatterAssociateTable::associateCompeleted,this,&ScatterChartBar::associateCompeleted);
}
