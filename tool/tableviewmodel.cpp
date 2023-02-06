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
            if (k % 2 == 0) dataVec->replace(k, i * 50 + qrand() % 20 + 1); // 偶数列
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
        for (int id : mCellMapping.keys())
        {
              int rectId = index.column()+1 + (index.row() + 1) * 10;
              if (rectId == id) // 根据索引也就是单元格左上角得到这个单元格的标记
                  return mCellMapping.value(id); // 返回单元格对应的颜色
        }
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

void TableViewModel::addCellMapping(QRect rect,QColor color)
{
    Q_ASSERT(rect.width() == rect.height() == 1); // 限制区域必须是单个单元格
    int rows = rect.y()+1, cols = rect.x()+1;// x()是列数-1,y()是行数-1
    int rectId = rows * 10 + cols;// 第1行第1列其标记11,第3行第4列其标记 34
    // 水平区域标记是11,12,...,1n 以及垂直21,31,...n1,这样每个单元格有唯一键值

    mCellMapping.insert(rectId,color);// 单元格和颜色一一对应,覆盖插入
}

void TableViewModel::addColMapping(int col ,QColor color)
{ // 对整列单元格进行映射
    for(int y = 0;y <mRowCount; ++ y)
    { // col是水平方向,表示x坐标, y坐标遍历行即可
        addCellMapping(QRect(col,y,1,1),color);
    }
}

void TableViewModel::addDoubleColMapping(QXYSeries* series,int xCol, int yCol)
{
   QVXYModelMapper *mapper = new QVXYModelMapper;
   mapper->setXColumn(xCol);
   mapper->setYColumn(yCol);
   mapper->setSeries(series);
   mapper->setModel(this);
   addColMapping(xCol,series->color());
   addColMapping(yCol,series->color());
}

void TableViewModel::clearMapping()
{
    mCellMapping.clear();
}
