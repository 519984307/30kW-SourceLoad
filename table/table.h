#ifndef TABLE_H
#define TABLE_H
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTextStream>
#include <QFileDialog>
#include <QRegExp>
#include <QDir>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QTime>
#include <QPersistentModelIndex>
#include <QThreadPool>
#include <QApplication>
#include <csv/csvexport.h>
#include <messagebox/critical.h>
#include <messagebox/infomation.h>
#include <messagebox/warning.h>
//Infomation * info = new Infomation;
//info->setText(tr("取消导入Txt文件!"));
//info->setTextWrapIndent(2,24);
//info->exec();
//delete info;
using namespace QtConcurrent;
class Table : public QObject
{
    Q_OBJECT
public:
    enum class AlignType {Left,Center,Right};
    enum class DelegateType {LineEdit,IntSpin,DoubleSpin,Combo};
    struct TableSize { int row; int col;};

    explicit Table(QTableView*,int ,int ,QObject * parent = Q_NULLPTR);
    explicit Table(QTableView* ,TableSize,QObject * parent = Q_NULLPTR);

    // 无论txt还是csv import 1万行轻微影响,10万行很卡; export 10万行不卡
    void importTxt(); // 先拿到文本再导入表格
    void exportTxt(); // 先拿到表格文本再导出

    void importCsv();   // 文本循环的同时导入表格
    void exportCsv();  // 表格循环的同时导出文本

    void importTable(QStringList& content); // 完成importTxt/importCsv的实际工作

    // 调用csv/csvexport完成的
    void importCsvExternel();// 1万行轻微影响,10万行很卡,内部是先拿到导入的文本再导入表格的
    void exportCsvExternel(); // 1万行时就会很卡4.5s ,内部是文本循环一遍,然后再使用流导出

    // 文本循环的同时导入表格,十万行比importTxt()和importCsv()稍快但提升不大
    void importTxtOptim();
    void importCsvOptim();

    // 使用并行技术
    void importTableConcurrent(QStringList& content);

    void importTxtConcurrent();
    void exportTxtConcurrent();

    void importCsvConcurrent();
    void exportCsvConcurrent();

    int row() const;
    int col() const;

    void appendRow();
    void appendCol();

    void insertRow();
    void insertCol();

    void appendRow(const QStringList&);
    void insertRow(const QStringList&);

    void removeRow();
    void removeCol();

    void setBold(bool);
    void setItalic(bool);
    void setAlign(AlignType);
    void setColor(QColor,QColor);
    void setDelegate(DelegateType);

    void clear();
    void clearConcurrent(bool = false);

    void reset(int, int);
    void reset(const TableSize&);

    void setHeader(const QStringList&);
    QStringList header() const;

    QStandardItem * takeItem(const QModelIndex&) const;

private:
    void initModels(int,int);
    void initConnections();
    void setTips();
    void showTips();
    bool mShowTips;
    void showTips(const QString&,const QSize& =QSize(800,280),const QPoint& =QPoint(2,18));
    Infomation * mTableTips;
    QTableView * mTableView;
    QItemSelectionModel * mSelectionModel;
    QStandardItemModel * mStandardModel;
    TableSize mTableSize;
    CSVExport  mCsvOpera;
    QColor mForeColor;
    QColor mBackColor;
signals:
    void cellCurrentIndex(const QModelIndex&);
    void cellCurrentContent(const QString&);
};

#endif // TABLE_H
