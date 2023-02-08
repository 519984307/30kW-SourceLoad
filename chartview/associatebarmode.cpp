#include <chartview/associatebarmode.h>

AssociateBarMode::AssociateBarMode(TableViewModel*model,QWidget*parent):
    QGroupBox(parent),mTableModel(model)
{
    setFont(QFont("Times New Roman",12));
    setTitle(tr("关联"));

    mAssociateModeBox = new QGroupBox(tr("关联模式"));
    mRowMode = new QRadioButton(tr("行关联"));
    mColMode = new QRadioButton(tr("列关联"));
    mRectMode = new QRadioButton(tr("区域关联"));

    QHBoxLayout * lay1 = new QHBoxLayout;
    lay1->addWidget(mRowMode);
    lay1->addWidget(mColMode);
    lay1->addWidget(mRectMode);
    mAssociateModeBox->setLayout(lay1);
    mRowMode->setChecked(true);

    mAssociateSpinBox = new QGroupBox(tr("关联设置"));
    mRowSpin = new QSpinBox;
    mColSpin = new QSpinBox;
    mColSpin->setEnabled(false);
    mRowSpin->setRange(1,mTableModel->rowCount());
    mColSpin->setRange(1,mTableModel->columnCount());

    QHBoxLayout * lay21 = new QHBoxLayout;
    lay21->addWidget(new QLabel(tr("关联列数")));
    lay21->addWidget(mColSpin);
    QHBoxLayout * lay22 = new QHBoxLayout;
    lay22->addWidget(new QLabel(tr("关联行数")));
    lay22->addWidget(mRowSpin);
    QHBoxLayout * lay2 = new QHBoxLayout;
    lay2->addLayout(lay21);
    lay2->addLayout(lay22);

    mRectBox = new QGroupBox;
    mFirstColumnSpin = new QSpinBox;
    mLastColumnSpin = new QSpinBox;
    mFirstRowSpin = new QSpinBox;
    mRowCountSpin = new QSpinBox;
    mFirstColumnSpin->setRange(1,mTableModel->columnCount());
    mLastColumnSpin->setRange(1,mTableModel->columnCount());
    mFirstRowSpin->setRange(1,mTableModel->rowCount());
    mRowCountSpin->setRange(1,mTableModel->rowCount());
    QGridLayout * rectlay = new QGridLayout;
    rectlay->addWidget(new QLabel(tr("起始列")),0,0);
    rectlay->addWidget(mFirstColumnSpin,0,1);
    rectlay->addWidget(new QLabel(tr("终止列")),0,2);
    rectlay->addWidget(mLastColumnSpin,0,3);
    rectlay->addWidget(new QLabel(tr("起始行")),1,0);
    rectlay->addWidget(mFirstRowSpin,1,1);
    rectlay->addWidget(new QLabel(tr("行数")),1,2);
    rectlay->addWidget(mRowCountSpin,1,3);
    mRectBox->setLayout(rectlay);
    mRectBox->setEnabled(false);

    QVBoxLayout * lay3 = new QVBoxLayout;
    lay3->addLayout(lay2);
    lay3->addWidget(mRectBox);
    mAssociateSpinBox->setLayout(lay3);


    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(mAssociateModeBox);
    lay->addWidget(mAssociateSpinBox);
    setLayout(lay);

    connect(mColMode,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mColSpin->setEnabled(checked);
            mRowSpin->setEnabled(!checked);
            mRectBox->setEnabled(!checked);
    });
    connect(mRowMode,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mColSpin->setEnabled(!checked);
            mRowSpin->setEnabled(checked);
            mRectBox->setEnabled(!checked);
    });
    connect(mRectMode,static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::clicked),
            this,[=](bool checked){
            mColSpin->setEnabled(!checked);
            mRowSpin->setEnabled(!checked);
            mRectBox->setEnabled(checked);
    });
}

bool AssociateBarMode::isRectMode() const
{
    return mRectMode->isChecked();
}

bool AssociateBarMode::isRowMode() const
{
    return mRowMode->isChecked();
}

bool AssociateBarMode::isColMode() const
{
    return mColMode->isChecked();
}

int AssociateBarMode::associateRow() const
{
    return mRowSpin->value()-1;
}

int AssociateBarMode::associateCol() const
{
    return mColSpin->value() - 1;
}

AssociateBarMode::AssociateRect  AssociateBarMode::associateRect() const
{
    AssociateRect rect = {
        mFirstColumnSpin->value()-1,
        mLastColumnSpin->value()-1,
        mFirstRowSpin->value()-1,
        mRowCountSpin->value()
    };
    return rect;
}

void AssociateBarMode::adjustRange()
{
    mRowSpin->setRange(1,mTableModel->rowCount());
    mColSpin->setRange(1,mTableModel->columnCount());
    mFirstColumnSpin->setRange(1,mTableModel->columnCount());
    mLastColumnSpin->setRange(1,mTableModel->columnCount());
    mFirstRowSpin->setRange(1,mTableModel->rowCount());
    mRowCountSpin->setRange(1,mTableModel->rowCount()); //至少1行,也就是FirstRow所在的行
}
