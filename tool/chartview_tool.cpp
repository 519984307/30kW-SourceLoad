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
    mImportFileBtn = new QPushButton(tr("导入文件"));
    mImportHeaderBtn = new QCheckBox(tr("文件带表头?"));
    mImportHeaderBtn->setCheckState(Qt::Checked);
    QGroupBox * tablebtnbox = new QGroupBox;
    QHBoxLayout * tablebtnlay = new QHBoxLayout;
    tablebtnlay->addWidget(mImportFileBtn);
    tablebtnlay->addWidget(mImportHeaderBtn);
    tablebtnbox->setLayout(tablebtnlay);

    mTableView = new QTableView;
    mTableView->setMinimumWidth(400);
    mTableModel = new TableViewModel;
    mTableView->setModel(mTableModel);
    QItemSelectionModel * selection = new QItemSelectionModel(mTableModel);
    mTableView->setSelectionModel(selection);
    mTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    mTableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    mTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    connect(mImportFileBtn,&QPushButton::clicked,this,[=]{
        QDir debugDir= QDir::current();
        debugDir.cdUp();
        QString fileName = QFileDialog::getOpenFileName(Q_NULLPTR, tr("Txt/Csv文件"), debugDir.path(),tr("*.txt *.csv"));
        if (fileName.isEmpty()) return; // 弹窗类型语句不可以放在run函数内执行

        bool withHeader = mImportHeaderBtn->isChecked();
        bool isCsv = fileName.contains(".csv");

        QFuture<void> future =QtConcurrent::run([=]{
            mTableModel->clear();
            mTableModel->clearMapping();

            QFile outFile(fileName);
            outFile.open( QIODevice::ReadOnly );
            QTextStream ts(&outFile);
            ts.setAutoDetectUnicode(true);
            ts.setCodec(QTextCodec::codecForName("UTF-8"));
            if (isCsv) ts.setCodec(QTextCodec::codecForName("gbk"));

            if (withHeader) { // 如果导入文件带有表头
                QString header = ts.readLine(); // 事先读取1行
                if (header.isEmpty()) return; // 至少应该有1行表头

                QStringList headerList;
                headerList = isCsv? header.split(',',QString::SkipEmptyParts):
                                    header.split(QRegExp("\\s+"),QString::SkipEmptyParts);
                mTableModel->setHorizontalHeaderLabels(headerList);//设置表头
            }

            while (!ts.atEnd()) {
                QString line= ts.readLine();
                QStringList lineList =isCsv?line.split(',',QString::SkipEmptyParts):
                                            line.split(QRegExp("\\s+"),QString::SkipEmptyParts);
                mTableModel->appendRow(lineList);
            }
            outFile.close();
        });
        while (!future.isFinished()) QApplication::processEvents(QEventLoop::AllEvents, 5);
    });
}
