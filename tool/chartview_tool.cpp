#include <tool/chartview_tool.h>

ChartViewWidget::ChartViewWidget(QWidget *parent) : QWidget(parent)
{
        init();
        initConnections();
}

void ChartViewWidget::closeEvent(QCloseEvent *e)
{
    mLineTab->closeChildrenWindows(); // 窗口关闭时把所有子窗口都关掉
    e->accept();
}

void ChartViewWidget::init()
{
    setMouseTracking(true);
    setWindowIcon(QIcon(":/images/chartview.png"));
    setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    setWindowFlag(Qt::Window);
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags^Qt::WindowContextHelpButtonHint);
    setMinimumSize(QSize(2000,900));
    setFont(QFont("Times New Roman",12));

    /*-----------------------------------------table-----------------------------------------*/
    mImportLogBtn = new QPushButton(tr("导入日志文件"));
    mImportFileBtn = new QPushButton(tr("导入普通文件"));
    QGroupBox * tablebtnbox = new QGroupBox;
    QHBoxLayout * tablebtnlay = new QHBoxLayout;
    tablebtnlay->addWidget(mImportLogBtn);
    tablebtnlay->addWidget(mImportFileBtn);
    tablebtnbox->setLayout(tablebtnlay);

    mTableView = new QTableView;
    mTableView->setMinimumWidth(400);
    QGroupBox * tablebox = new QGroupBox;
    QVBoxLayout * tablelay = new QVBoxLayout;
    tablelay->addWidget(mTableView);
    tablelay->addWidget(tablebtnbox);
    tablebox->setLayout(tablelay);

    /*-----------------------------------------tab-----------------------------------------*/
    mTab = new QTabWidget;
    mTab->setMinimumWidth(1000);
    mLineTab = new LineChart(mTableView,mTab);
    mTab->addTab(mLineTab,QIcon(":/images/linechart.png"),tr("折线图"));
    /*-----------------------------------------layout-----------------------------------------*/
    QSplitter * splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(tablebox);
    splitter->addWidget(mTab);
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,4);
    splitter->setHandleWidth(10);
    splitter->setChildrenCollapsible(false);

    mLayout = new QGridLayout(this);
    mLayout->addWidget(splitter);//改用分割条灵活
//    mLayout->addWidget(tablebox, 1, 0);
//    mLayout->addWidget(mTab, 1, 1);
//    mLayout->setColumnStretch(1, 1);
//    mLayout->setColumnStretch(0, 0);

}

void ChartViewWidget::initConnections()
{

}
