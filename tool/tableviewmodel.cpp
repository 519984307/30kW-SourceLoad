#include <tool/tableviewmodel.h>
#include <QDebug>

TableViewModel::TableViewModel(QObject *parent):QAbstractTableModel(parent)
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    mColumnCount = 6;
    mRowCount = 100;
    for(int i = 1; i<= mRowCount;++i) mHeader.append(QString::number(i));

    for (int i = 0; i < mRowCount; i++) {
        QVector<QVariant> * dataVec = new QVector<QVariant>(mColumnCount); // 6个值的行向量
        for (int k = 0; k < dataVec->size(); k++) {
            if (k % 2 == 0) dataVec->replace(k, i * 50 + qrand() % 20); // 偶数列
            else dataVec->replace(k, qrand() % 5000);  // 幅值5000
        }
        mData.append(dataVec);
    }
}

int TableViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mData.count();
}

int TableViewModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mColumnCount;
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal && !mHeader.isEmpty())
    {
        if ( section<mHeader.count()) // 可能出现越界
            return mHeader[section];
        else return QVariant();
    }

    return QString("%1").arg(section + 1); // 按1,2,3,4顺序
}

QVariant TableViewModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return mData[index.row()]->at(index.column());
    }
    else if (role == Qt::BackgroundRole)
    {
        for (const QRect &rect : mMapping) {
            if (rect.contains(index.column(), index.row()))
                return QColor(mMapping.key(rect)); // 返回单元格背景颜色
        }
        return QColor(Qt::white); // 默认单元格背景都是白色
    }
    return QVariant();
}

bool TableViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        mData[index.row()]->replace(index.column(), value);
        emit dataChanged(index, index); // 数据变化就会自动调整
        return true;
    }
    return false;
}

void TableViewModel::clear()
{
    mData.clear();
}

void TableViewModel::setHorizontalHeaderLabels(const QStringList &labels)
{
    mColumnCount = labels.count();
    mHeader.clear();
    mHeader = labels;
}

QStringList TableViewModel::horizontalHeaderLabels() const
{
    return mHeader;
}

void TableViewModel::tagYColumn(int col, const QColor &color)
{//QMap((0, QVariant(int, 1520))(2, QVariant(int, 1520))(8, QVariant(QColor, QColor(ARGB 1, 1, 0, 0))))
//    QModelIndex idx;
//    for(int r = 0 ; r < mRowCount; ++r)
//    {
//        idx = index(r,col);
//        QMap<int,QVariant> m = itemData(idx);

//        qDebug()<<"before : "<<m[8];
//        m[8].setValue(color);
//        qDebug()<<"after : "<<m[8];
//        setItemData(idx,m);
//        qDebug()<<"last: "<<itemData(idx)[8];
//    }
    // 虚函数setItemData除非重载才能起作用,data()已经规定了表格显示数据的方式
    // 直接改变mMapping就可以了,就像XY映射那样做,QAbstractTableModel内部已经设定好了映射的机制
    clearMapping();
    QRect rect(col,0,1,mRowCount);// x坐标实际是列
    addMapping(color.name(),rect);
}

void TableViewModel::tagXYColumn(QLineSeries*series,int xCol , int yCol)
{
   QVXYModelMapper *mapper = new QVXYModelMapper;
   mapper->setXColumn(xCol);
   mapper->setYColumn(yCol);
   mapper->setSeries(series);
   mapper->setModel(this);
   QString seriesColorHex = "#" + QString::number(series->color().rgb(), 16).right(6).toUpper();
   clearMapping();
   addMapping(seriesColorHex, QRect(xCol, 0, 1, rowCount())); //指定的2列
   addMapping(seriesColorHex, QRect(yCol, 0, 1, rowCount()));
}

void TableViewModel::appendRow(QVector<QVariant>*data)
{
     mData.append(data);
     mColumnCount = data->count();
     mRowCount = mData.count();
}

void TableViewModel::appendRow(const QStringList &data)
{
    QVector<QVariant> *v = new QVector<QVariant>;
    foreach (const QString & d, data) v->append(d);
    mData.append(v);
    mColumnCount = data.count();
    mRowCount = mData.count();
}

QVector<QVariant> TableViewModel::rowData(int row) const
{
    return *mData[row];
}

QVector<QVariant> TableViewModel::colData(int col) const
{
    QVector<QVariant> d;
    for(int r = 0 ; r < mData.count(); ++r)
    {
        d.append(mData.at(r)->at(col));
    }
    return d;
}

Qt::ItemFlags TableViewModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void TableViewModel::addMapping(QString color, QRect area)
{
    mMapping.insertMulti(color, area);
}

void TableViewModel::removeMapping(QString color)
{
    mMapping.remove(color);
}
