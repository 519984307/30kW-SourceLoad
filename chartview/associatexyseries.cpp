#include <chartview/associateseries.h>

AssociateSeries::AssociateSeries(QWidget*parent):QGroupBox(parent)
{
        mLineColor = Qt::white;
        mLineWidth = 2;
        mMarkerSize = 15.;
        setFont(QFont("Times New Roman",12));
        setTitle(tr("曲线"));

        mLineWidthSpin = new QSpinBox;
        mLineWidthSpin->setMinimum(1);
        mMarkerSizeSpin = new QDoubleSpinBox;
        mMarkerSizeSpin->setMinimum(1.);
        mMarkerSizeSpin->setSingleStep(0.1);
        mMarkerSizeSpin->setDecimals(1);
        mMarkerSizeSpin->setValue(mMarkerSize);

        mLineColorBtn = new QPushButton(tr("设置曲线颜色"));
        mLineColorEdit = new QLineEdit(mLineColor.name());
        mLineColorEdit->setReadOnly(true);
        QFormLayout * linelay = new QFormLayout;
        linelay->addRow(tr("&线宽"),mLineWidthSpin);
        linelay->addRow(tr("&尺寸"),mMarkerSizeSpin);
        linelay->addRow(tr("&颜色"),mLineColorBtn);
        linelay->addRow(tr("&当前颜色"),mLineColorEdit);
        setLayout(linelay);

        connect(mLineColorBtn,&QPushButton::clicked,this,[=]{
            QColorDialog * dlg = new QColorDialog(mLineColor);
            dlg->setFixedSize(800,400);
            dlg->setWindowIcon(QIcon(":/images/associatetable.png"));
            dlg->setOptions(QColorDialog::ShowAlphaChannel|QColorDialog::DontUseNativeDialog);
            dlg->setWindowTitle(tr("设置颜色"));
            connect(dlg,static_cast<void (QColorDialog::*) (const QColor&)>(&QColorDialog::colorSelected)
                   ,this,[=](const QColor& color){
                mLineColorEdit->setText(color.name()); //把选择的颜色显示在文本框/手动输入也可
                mLineColor = color;
            });
            dlg->exec(); delete dlg;
        });
        connect(mLineWidthSpin,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                this,[=](int width){mLineWidth = width;});
        connect(mMarkerSizeSpin,static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
                this,[=](double size){mMarkerSize = size;});
}

QColor AssociateSeries::linecolor() const
{
    return mLineColor;
}

int AssociateSeries::linewidth() const
{
    return  mLineWidth;
}

double AssociateSeries::markersize() const
{
    return mMarkerSize;
}

void AssociateSeries::setLineWidthVisible(bool show)
{
    mLineWidthSpin->setEnabled(show);
}

void AssociateSeries::setMarkerSizeVisible(bool show)
{
    mMarkerSizeSpin->setEnabled(show);
}
