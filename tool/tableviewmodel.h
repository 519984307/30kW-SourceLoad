#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <QVector>
#include <QRect>
#include <QColor>
#include <QTime>
#include <QMap>
#include <QVXYModelMapper>
#include <QLineSeries>
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

    void tagYColumn(int,const QColor&);
    QLineSeries* tagXYColumn(int,int,const QColor&);

    void appendRow(QVector<QVariant> *);
    void appendRow(const QStringList&);
    QVector<QVariant> rowData(int) const;
    QVector<QVariant> colData(int) const;

    void addMapping(QString color, QRect area);
    void clearMapping() { mMapping.clear(); }

private:
    QList<QVector<QVariant> * > mData;
    QHash<QString, QRect> mMapping;
    QStringList mHeader;
    int mColumnCount;
    int mRowCount;
};

#endif // TABLEVIEWMODEL_H
