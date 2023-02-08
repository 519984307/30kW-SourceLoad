#include <chartview/associatemode.h>
#include <QDebug>
AssociateMode::AssociateMode(QTableView*tableview,QChartView*chartview,QWidget*parent):
    QGroupBox(parent),mTableView(tableview),mChartView(chartview)
{
    mTableModel = static_cast<TableViewModel*>(mTableView->model());
    setFont(QFont("Times New Roman",12));
    setTitle(tr("关联"));

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
    lay2->addRow(tr("X轴"),new QLabel(tr("自动")));
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

    QGroupBox * relatebox = new QGroupBox(tr("关联设置"));
    QHBoxLayout * relatelay  = new QHBoxLayout;
    relatelay->addWidget(mSingleAssociateBox);
    relatelay->addWidget(mDoubleAssociateBox);
    relatebox->setLayout(relatelay);

    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(mAssociateModeBox);
    lay->addWidget(relatebox);

    setLayout(lay);

    connect(mSingleBtn,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mSingleAssociateBox->setEnabled(checked);
            mDoubleAssociateBox->setEnabled(!checked);
            emit changeMode(false);
    });
    connect(mDoubleBtn,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mSingleAssociateBox->setEnabled(!checked);
            mDoubleAssociateBox->setEnabled(checked);
            emit changeMode(true);
    });
}

bool AssociateMode::isSingle() const
{
    return mSingleBtn->isChecked();
}

void AssociateMode::adjustRange()
{
    mSingleSpin->setRange(1,mTableModel->columnCount());
    mDoubleSpinX->setRange(1,mTableModel->columnCount());
    mDoubleSpinY->setRange(1,mTableModel->columnCount());
}

int AssociateMode::singleCol()
{
    return mSingleSpin->value() -1; // 最小值是1,要从0计算
}

QPoint AssociateMode::doubleCols()
{
    int xCol = mDoubleSpinX->value() - 1;
    int yCol = mDoubleSpinY->value() - 1;
    return  QPoint(xCol,yCol);
}
