#include <chartsetting/chartforeground.h>

ChartForeground::ChartForeground(QChart *chart,const QIcon& icon,QWidget*parent)
    :ChartBox(chart,icon,parent)
{
    // 0. 绘制区域可见性的布局
    QCheckBox * v = new QCheckBox;
    v->setCheckState(Qt::Checked); // chart.cpp默认可见
    connect(v,static_cast<void (QCheckBox::*)(int)>(&QCheckBox::stateChanged),this,[=](int state){
            bool r = state == Qt::Unchecked;
            mChart->setPlotAreaBackgroundVisible(!r);
    });
    mForegroundArea = new ForegroundArea(chart,icon);

    mForegroundBorder = new ForegroundBorder(chart,icon);
    QPushButton * b = new QPushButton(tr("设置"));
    connect(b,&QPushButton::clicked,this,[=]{mForegroundBorder->show();});

    QFormLayout * lay = new QFormLayout;
    lay->addRow(tr("&前景可见"),v);
    //lay->addRow(area);//不直接使用area,不太好看,所以补救提供2个公共函数返回指针直接添加
    lay->addRow(tr("&前景颜色"),mForegroundArea->colorSetButton());
    lay->addRow(tr("&前景样式"),mForegroundArea->brushStyleComboBox());
    lay->addRow(tr("&前景边框"),b);
    setTitle(tr("前景"));
    setLayout(lay);
}

void ChartForeground::closeChindrenWindows()
{
    mForegroundBorder->close();// 关闭弹出的设置绘画区域边框的窗口
}


