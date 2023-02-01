#include <seriessetting/seriesline.h>

SeriesLine::SeriesLine(QChart * chart,QWidget* parent):
    QGroupBox(parent),mChart(chart),mCurrentSeries(nullptr),mCurrentSeriesId(0)
{// 必须是QLineSeries,所以不继承SeriesBox,也无需构造函数,而是动态设定
        mIcon.addFile(":/images/toolbox_series.png");
        mCurrentSeries = static_cast<QLineSeries*>(mChart->series().at(0));

        mPointVisible = new QCheckBox;
        updatePointVisible();

        mPointLabelsVisible = new QCheckBox;
        updatePointLabelsVisible();

        mPointLabelsClipping = new QCheckBox;
        updatePointLabelsClipping();

        mSetSeriesColor = new QPushButton(tr("设置曲线颜色"));
        updateColorState();

        mSetSeriesWidth = new QSpinBox;
        updateWidthState();

        mPointLabelsColor = new QPushButton(tr("设置标签颜色"));
        updatePointLabelsColor();

        mPointLabelsFont = new QPushButton(tr("设置标签格式"));
        updatePointLabelsFont();

        mPointFormatX = new QRadioButton("@x");
        mPointFormatY = new QRadioButton("@y");
        mPointFormatXY = new QRadioButton("(@x,@y)");
        mFormatGroup = new QButtonGroup;
        mFormatGroup->addButton(mPointFormatX,1);
        mFormatGroup->addButton(mPointFormatY,2);
        mFormatGroup->addButton(mPointFormatXY,0);
        updatePointLabelsFormat();

        QFormLayout * flay = new QFormLayout;
        flay->addRow(tr("&数据可见"),mPointVisible);
        flay->addRow(tr("&标签可见"),mPointLabelsVisible);
        flay->addRow(tr("&标签剪裁"),mPointLabelsClipping);
        flay->addRow(tr("&曲线颜色"),mSetSeriesColor);
        flay->addRow(tr("&曲线宽度"),mSetSeriesWidth);
        flay->addRow(tr("&标签颜色"),mPointLabelsColor);
        flay->addRow(tr("&标签格式"),mPointLabelsFont);

        QHBoxLayout * rlay = new QHBoxLayout;
        rlay->addWidget(new QLabel(tr("数据格式")));
        rlay->addWidget(mPointFormatX);
        rlay->addWidget(mPointFormatY);
        rlay->addWidget(mPointFormatXY);

        QVBoxLayout * lay = new QVBoxLayout;
        lay->addLayout(flay);
        lay->addLayout(rlay);
        setTitle(tr("数据点"));
        setLayout(lay);
}

void SeriesLine::setCurrentSeries(QLineSeries *series,int id)
{
    mCurrentSeries = series;
    mCurrentSeriesId = id;
    updateState();
}

QLineSeries * SeriesLine::currentSeries() const
{
    return mCurrentSeries;
}

void SeriesLine::setCurrentSeriesId(int id)
{
    mCurrentSeriesId = id;
}

int SeriesLine::currentSeriesId() const
{
    return mCurrentSeriesId;
}

void SeriesLine::updateState()
{
    updateColorState();
    updateWidthState();
    updatePointVisible();
    updatePointLabelsVisible();
    updatePointLabelsColor();
    updatePointLabelsClipping();
    updatePointLabelsFont();
    updatePointLabelsFormat();
}

void SeriesLine::updatePointVisible()
{
    Qt::CheckState state = mCurrentSeries->pointsVisible()?Qt::Checked:Qt::Unchecked;
    mPointVisible->setCheckState(state); // 当前曲线会切换,都要连接,又要避免重复连接
    disconnect(mPointVisible,&QCheckBox::stateChanged,this,&SeriesLine::changePointVisible);
    connect(mPointVisible,&QCheckBox::stateChanged,this,&SeriesLine::changePointVisible);
}

void SeriesLine::changePointVisible(int state)
{
    bool s = state == Qt::Checked;
    mCurrentSeries->setPointsVisible(s);
}

void SeriesLine::updatePointLabelsVisible()
{
    Qt::CheckState state = mCurrentSeries->pointLabelsVisible()?Qt::Checked:Qt::Unchecked;
    mPointLabelsVisible->setCheckState(state); // 当前曲线会切换,都要连接,又要避免重复连接
    disconnect(mPointLabelsVisible,&QCheckBox::stateChanged,this,&SeriesLine::changePointLabelsVisible);
    connect(mPointLabelsVisible,&QCheckBox::stateChanged,this,&SeriesLine::changePointLabelsVisible);
}

void SeriesLine::changePointLabelsVisible(int state)
{
    bool s = state == Qt::Checked;
    mCurrentSeries->setPointLabelsVisible(s);
}

void SeriesLine::updatePointLabelsClipping()
{
    Qt::CheckState state = mCurrentSeries->pointLabelsClipping()?Qt::Checked:Qt::Unchecked;
    mPointLabelsClipping->setCheckState(state); // 当前曲线会切换,都要连接,又要避免重复连接
    disconnect(mPointLabelsClipping,&QCheckBox::stateChanged,this,&SeriesLine::changePointLabelsClipping);
    connect(mPointLabelsClipping,&QCheckBox::stateChanged,this,&SeriesLine::changePointLabelsClipping);
}

void SeriesLine::changePointLabelsClipping(int state)
{
    bool s = state == Qt::Checked;
    mCurrentSeries->setPointLabelsClipping(s);
}

void SeriesLine::updateColorState()
{
    disconnect(mSetSeriesColor,&QPushButton::clicked,this,&SeriesLine::changeColor);
    connect(mSetSeriesColor,&QPushButton::clicked,this,&SeriesLine::changeColor);
}

void SeriesLine::changeColor()
{
    QColor oldcolor = mCurrentSeries->color();
    QColorDialog * dlg = colorDialog(oldcolor);
    connect(dlg,static_cast<void (QColorDialog::*) (const QColor&)>(&QColorDialog::colorSelected)
           ,this,[=](const QColor& color){ mCurrentSeries->setColor(color); //对曲线来说brush没有意义,color=pen's color
            emit seriesColorChanged(mCurrentSeries); // 曲线颜色改变以后要让做表格对应的列也变成相应颜色,列可以在linechart/associatetable通过曲线指针找到
    });
    dlg->exec(); delete dlg;
}

void SeriesLine::updateWidthState()
{
    mSetSeriesWidth->setValue(mCurrentSeries->pen().width());
    disconnect(mSetSeriesWidth,SIGNAL(valueChanged(int)),this,SLOT(changeWidth(int)));
    connect(mSetSeriesWidth,SIGNAL(valueChanged(int)),this,SLOT(changeWidth(int)));
}

void SeriesLine::changeWidth(int width)
{
    QPen pen = mCurrentSeries->pen();
    pen.setWidth(width);
    mCurrentSeries->setPen(pen);
}

void SeriesLine::updatePointLabelsColor()
{
    disconnect(mPointLabelsColor ,&QPushButton::clicked,this,&SeriesLine::changeLabelColor);
    connect(mPointLabelsColor ,&QPushButton::clicked,this,&SeriesLine::changeLabelColor);
}

void SeriesLine::changeLabelColor()
{
    QColor oldcolor = mCurrentSeries->pointLabelsColor();
    QColorDialog * dlg = colorDialog(oldcolor);
    connect(dlg,static_cast<void (QColorDialog::*) (const QColor&)>(&QColorDialog::colorSelected)
           ,this,[=](const QColor& color){ mCurrentSeries->setPointLabelsColor(color); //对文字标签来说brush也没有意义,color=pen's color
    });
    dlg->exec(); delete dlg;
}

void SeriesLine::updatePointLabelsFont()
{
    disconnect(mPointLabelsFont,&QPushButton::clicked,this,&SeriesLine::changeLabelFont);
    connect(mPointLabelsFont,&QPushButton::clicked,this,&SeriesLine::changeLabelFont);
}

void SeriesLine::changeLabelFont()
{
    QFont oldfont = mCurrentSeries->pointLabelsFont();
    QFontDialog * dlg = fontDialog(oldfont);
    connect(dlg,static_cast<void (QFontDialog::*) (const QFont&)>(&QFontDialog::fontSelected)
           ,this,[=](const QFont& font){mCurrentSeries->setPointLabelsFont(font);});
    dlg->exec(); delete dlg;
}

void SeriesLine::updatePointLabelsFormat()
{
    QString format = mCurrentSeries->pointLabelsFormat();
    if (format.contains('x'))
    {
         if (format.contains('y'))
                mPointFormatXY->setChecked(true);
         else mPointFormatX->setChecked(true);
    }
    else mPointFormatY->setChecked(true);

    disconnect(mFormatGroup,SIGNAL(buttonClicked(int)),this,SLOT(changeFormat(int)));
    connect(mFormatGroup,SIGNAL(buttonClicked(int)),this,SLOT(changeFormat(int)));
}

void SeriesLine::changeFormat(int id)
{
    switch (id) {
            case 0: mCurrentSeries->setPointLabelsFormat("(@xPoint,@yPoint)");break;
            case 1: mCurrentSeries->setPointLabelsFormat("x = @xPoint");break;
            case 2: mCurrentSeries->setPointLabelsFormat("y = @yPoint");break;
            default:break;
    }
}

QColorDialog* SeriesLine::colorDialog(const QColor&initColor)
{
    QColorDialog * dlg = new QColorDialog(initColor);
    dlg->setFixedSize(800,400);
    dlg->setWindowIcon(mIcon);
    dlg->setOptions(QColorDialog::ShowAlphaChannel|QColorDialog::DontUseNativeDialog);//QColorDialog::NoButtons|
    dlg->setWindowTitle(tr("设置颜色"));
    return dlg;
}

QFontDialog* SeriesLine::fontDialog(const QFont &initFont)
{
    QFontDialog * dlg = new QFontDialog(initFont);
    dlg->setFixedSize(800,400);
    dlg->setWindowIcon(mIcon);
    dlg->setWindowTitle(tr("设置格式"));
    dlg->setOptions(QFontDialog::DontUseNativeDialog);
    return dlg;
}

QComboBox* SeriesLine::brushStyleCombo()
{
    QComboBox * brushstyle = new QComboBox;

    QListWidget * listwidget = new QListWidget;
    brushstyle->setModel(listwidget->model());
    brushstyle->setView(listwidget);
    brushstyle->resize(100,30);
    QStringList iconnames;
    iconnames <<"NoBrush"<<"SolidPattern"<<"Dense1Pattern"<<"Dense2Pattern"<<"Dense3Pattern"
             <<"Dense4Pattern"<<"Dense5Pattern"<<"Dense6Pattern"<<"Dense7Pattern"<<"HorPattern"
            <<"VerPattern"<<"CrossPattern"<<"BDiagPattern"<<"FDiagPattern"<<"DiagCrossPattern";
    QString filename;
    foreach(const QString &style, iconnames)
    {
        filename = QStringLiteral(":/images/")+style+QStringLiteral(".jpg");
        QPixmap pix(filename);
        QPixmap p = pix.scaled(brushstyle->size(),Qt::IgnoreAspectRatio); // p.size()全部是(100,30)
        if (style == "NoBrush") p.fill(Qt::white); // NoBrush改用白色填充
        brushstyle->addItem(QIcon(p),style); // 添加图标-文字
    }
    brushstyle->setIconSize(brushstyle->size()); // 要设置,图标默认方形,这里设置为矩形长度
    brushstyle->setSizeAdjustPolicy(QComboBox::AdjustToContents);//设置这个最好,其它的略短,符合内容大小的调整策略

    return  brushstyle; // currentIndex以及currentIndexChanged外部要自行设置和连接,这是只是提供1个创建好的指针
}

