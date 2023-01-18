#include <chartview/chartbar.h>
#include <QDebug>

ChartBar::ChartBar(QTableView*tableview,QChartView* chartview,QWidget*parent):
    QToolBar(parent),mTableView(tableview),mChartView(chartview),mChart(chartview->chart())
{
    mScreenShot = new ScreenShoot(chartview);

    QAction * zoombig = new QAction(QIcon(":/images/zoombig.bmp"),tr("放大"));
    QAction * zoomsmall = new QAction(QIcon(":/images/zoomsmall.bmp"),tr("缩小"));
    QAction * zoom = new QAction(QIcon(":/images/zoom.bmp"),tr("还原"));
    QAction * associatetable = new QAction(QIcon(":/images/associatetable.png"),tr("关联表格"));
    QAction * screenshot = new QAction(QIcon(":/images/screenshot.png"),tr("截图"));

    addAction(zoombig);
    addAction(zoomsmall);
    addAction(zoom);
    addAction(associatetable);
    addAction(screenshot);
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(zoombig,&QAction::triggered,this,[=]{mChart->zoom(1.2);});
    connect(zoomsmall,&QAction::triggered,this,[=]{mChart->zoom(0.8);});
    connect(zoom,&QAction::triggered,this,[=]{mChart->zoomReset();});
    connect(associatetable,&QAction::triggered,this,[=]{

    });
    connect(screenshot,&QAction::triggered,this,[=]{
            mScreenShot->exec();
    });
}
