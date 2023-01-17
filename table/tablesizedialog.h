#ifndef TABLESIZEDIALOG_H
#define TABLESIZEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <core/enum.h>
#include <messagebox/critical.h>
#include <QDebug>

class TableSizeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TableSizeDialog(QWidget * parent = Q_NULLPTR);
    void setCurrentSize(int,int);//让当前行列的设置和外部保持一致
    int row() const;
    int col() const;
    QStringList header() const;
private:
    QGridLayout * mainLayout;
    QLineEdit * mRowEdit;
    QLineEdit * mColEdit;
    QLineEdit * mHeaderEdit;
    QPushButton * mOkBtn;
    QPushButton * mCancelBtn;
    QListWidget * mSourceFields;
    QListWidget * mLoadFields;
    int mRow;
    int mCol;
    QStringList mHeader;
signals:
    void customTableNotImport();
    void customTableUseImport(QStringList&);
};

#endif // TABLESIZEDIALOG_H
