#include <chartview/associatetable.h>

AssociateTable::AssociateTable(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QDialog(parent),mTableView(tableview),mChartView(chartview)
{
    mCoordTip = new QGraphicsSimpleTextItem(chartview->chart());
    mCoordTip->setPen(QPen(QColor("#8B008B")));
    mCoordTip->setFont(QFont("Times New Roman",14));
    mCoordTip->setZValue(10);
    mCoordRect = new QGraphicsRectItem(chartview->chart());
    mCoordRect->setZValue(9);
    mCoordRect->setBrush(QColor("#FFFFE0"));
    mCoordRect->setPen(QPen(QColor(0,0,0)));

    mTableModel = static_cast<TableViewModel*>(mTableView->model());
    QVBoxLayout * lay = new QVBoxLayout(this);

    mAssociateModeBox = new QGroupBox(tr("关联模式"));
    mSingleBtn = new QRadioButton(tr("单列关联"));
    mDoubleBtn = new QRadioButton(tr("双列关联"));
    QHBoxLayout * lay1 = new QHBoxLayout;
    lay1->addWidget(mSingleBtn);
    lay1->addWidget(mDoubleBtn);
    mAssociateModeBox->setLayout(lay1);
    mSingleBtn->setChecked(true);

    mSingleAssociateBox = new QGroupBox(tr("单列关联"));
    mSingleSpin = new QSpinBox;
    mSingleSpin->setRange(1,mTableModel->columnCount());
    QFormLayout * lay2 = new QFormLayout;
    lay2->addRow(tr("X轴"),new QLabel(tr("自动生成")));
    lay2->addRow(tr("Y轴"),mSingleSpin);
    mSingleAssociateBox->setLayout(lay2);

    mDoubleAssociateBox = new QGroupBox(tr("双列关联"));
    mDoubleSpinX = new QSpinBox;
    mDoubleSpinX->setRange(1,mTableModel->columnCount());
    mDoubleSpinY = new QSpinBox;
    mDoubleSpinY->setRange(1,mTableModel->columnCount());
    QFormLayout * lay3 = new QFormLayout;
    lay3->addRow(tr("X轴"),mDoubleSpinX);
    lay3->addRow(tr("Y轴"),mDoubleSpinY);
    mDoubleAssociateBox->setLayout(lay3);
    mDoubleAssociateBox->setEnabled(false);

    mOkBtn = new QPushButton(tr("关联"));
    QHBoxLayout * lay4 = new QHBoxLayout;
    lay4->addStretch();
    lay4->addWidget(mOkBtn);

    lay->addWidget(mAssociateModeBox);
    lay->addWidget(mSingleAssociateBox);
    lay->addWidget(mDoubleAssociateBox);
    lay->addLayout(lay4);

    setFont(QFont("Times New Roman",12));
    setWindowIcon(QIcon(":/images/associatetable.png"));
    resize(QSize(600,300));

    initConnections();
}

void AssociateTable::initConnections()
{
    connect(mSingleBtn,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mSingleAssociateBox->setEnabled(checked);
            mDoubleAssociateBox->setEnabled(!checked);
    });
    connect(mDoubleBtn,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mSingleAssociateBox->setEnabled(!checked);
            mDoubleAssociateBox->setEnabled(checked);
    });

    connect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);
    // 文件随时可能重新导入更新tableview'smodel
    connect(this,&AssociateTable::tableChanged,this,[=]{
        disconnect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);
        mTableModel = static_cast<TableViewModel*>(mTableView->model()); //更新model再连
        connect(mOkBtn,&QPushButton::clicked,this,&AssociateTable::onOkBtn);
        mSingleSpin->setRange(1,mTableModel->columnCount());
        mDoubleSpinX->setRange(1,mTableModel->columnCount());
        mDoubleSpinY->setRange(1,mTableModel->columnCount());
    });
}

void AssociateTable::onOkBtn()
{
    bool isSingle = mSingleBtn->isChecked();
    if (isSingle) singleMapping();
    else doubleMapping();
    emit tableChanged(); // 不要导入表格时就发送,而是关联表格才发送,然后通知给工具栏的曲线和轴工具界面进行更新

    const auto markers = mChartView->chart()->legend()->markers(); // 初始化曲线后再连接
    for (QLegendMarker *marker : markers) { // 利用返回的图例标记的clicked信号实现点击图例变暗并隐藏曲线的效果
        QObject::disconnect(marker, &QLegendMarker::clicked,this, &AssociateTable::legendMarkerClicked); // 先断开以防重复连接
        QObject::connect(marker, &QLegendMarker::clicked, this, &AssociateTable::legendMarkerClicked);
    }
    accept();
}

void AssociateTable::singleMapping()
{
    int col = mSingleSpin->value() -1; // model从0开始计算

    mTableModel->tagYColumn(col,QColor(0,255,0,255));

    QVector<QVariant> data = mTableModel->colData(col); // 这列的数据
    QLineSeries * series = new QLineSeries;
    series->setName(mTableModel->horizontalHeaderLabels()[col]); //该列的名称作为序列名字
    QPointF point;
    for(int x = 0; x <data.count(); ++x){
        point.setX((qreal)x);point.setY(data[x].toDouble());
        *series  << point;
    }
    connect(series, &QLineSeries::hovered, this, &AssociateTable::showToolTip);
    QChart * chart = mChartView->chart();
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes();
    mChartView->setChart(chart);
}

void AssociateTable::doubleMapping()
{
    int xCol = mDoubleSpinX->value() - 1;
    int yCol = mDoubleSpinY->value() - 1;
    QLineSeries * series = mTableModel->tagXYColumn(xCol,yCol,Qt::green);
    series->setName(mTableModel->horizontalHeaderLabels()[xCol]+"-"
                    +mTableModel->horizontalHeaderLabels()[yCol]);
    connect(series, &QLineSeries::hovered, this, &AssociateTable::showToolTip);
    QChart * chart = mChartView->chart();
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes();
    mChartView->setChart(chart);
}

void AssociateTable::showToolTip(QPointF point, bool state)
{
    if (state)
    {
        QPointF pos = mChartView->chart()->mapToPosition(point);
        mCoordTip->setPos(pos); // 把曲线的坐标值映射为改点在全局的位置
        mCoordTip->setText(QString("[%1, %2] ").arg(point.x()).arg(point.y()));
        mCoordRect->setRect(QRectF(pos,QSizeF(213.,38.))); //长213高38的矩形刚好把文字放进去
        mCoordTip->show();
        mCoordRect->show();
    }
    else {
        mCoordTip->hide();
        mCoordRect->hide();
    }
}

void AssociateTable::legendMarkerClicked() // 这个函数不能放在chart.cpp连接因为那个时候还没有曲线,图例尚未创建出来,必须先初始化曲线后再连接
{
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender()); // 发送clicked的图例标记
    switch (marker->type())
    {
        case QLegendMarker::LegendMarkerTypeXY: // QXYLegendMarker=直线+样条曲线+散点系列的效果
        {
                marker->series()->setVisible(!marker->series()->isVisible());
                marker->setVisible(true); // 曲线隐藏会让图例也隐藏,还是要显示的只是变暗
                qreal alpha = 1.0;
                if (!marker->series()->isVisible())
                    alpha = 0.5;

                QColor color;
                QBrush brush = marker->labelBrush(); // 图例的文字
                color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setLabelBrush(brush);

                brush = marker->brush(); //图例标记的背景
                color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setBrush(brush);

                QPen pen = marker->pen(); // 图例标记的方框
                color = pen.color();
                color.setAlphaF(alpha);
                pen.setColor(color);
                marker->setPen(pen);
                break;
        }
    default: break;
    }
}
