#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <QVector>
#include <QRect>
#include <QColor>
#include <QTime>

#include <QVXYModelMapper>
#include <QLineSeries>
#include <QPair>
using namespace QtCharts;

class TableViewModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableViewModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void clear();

    void setHorizontalHeaderLabels(const QStringList &labels);
    QStringList horizontalHeaderLabels() const;

    void appendRow(QVector<QVariant> *);
    void appendRow(const QStringList&);
    QVector<QVariant> rowData(int) const;
    QVector<QVariant> colData(int) const;

    void addCellMapping(QRect,QColor);
    void addColMapping(int,QColor);
    void addDoubleColMapping(QLineSeries*,int,int);
    void clearMapping();
private:
    QList<QVector<QVariant> * > mData;
    QHash<int,QColor> mCellMapping;
    QStringList mHeader;
    int mColumnCount;
    int mRowCount;
};

#endif // TABLEVIEWMODEL_H
