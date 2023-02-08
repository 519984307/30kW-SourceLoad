#ifndef ASSOCIATEBARMODE_H
#define ASSOCIATEBARMODE_H

#include <QGroupBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <tool/tableviewmodel.h>
using namespace QtCharts;

class AssociateBarMode : public QGroupBox
{
    Q_OBJECT
public:
    explicit AssociateBarMode(TableViewModel*,QWidget*parent =Q_NULLPTR);
    struct AssociateRect
    {
        int firstColumn;
        int lastColumn;
        int firstRow;
        int rowCount;
    };
    bool isRectMode() const;
    bool isRowMode() const;
    bool isColMode() const;
    int associateRow() const;
    int associateCol() const;
    AssociateRect associateRect() const;
    void adjustRange();
private:
    TableViewModel * mTableModel;

    QGroupBox * mAssociateModeBox;
    QRadioButton * mRowMode;
    QRadioButton * mColMode;
    QRadioButton * mRectMode;

    QGroupBox * mAssociateSpinBox;
    QGroupBox * mRectBox;
    QSpinBox * mFirstColumnSpin;
    QSpinBox * mLastColumnSpin;
    QSpinBox * mFirstRowSpin;
    QSpinBox * mRowCountSpin;
    QSpinBox * mRowSpin;
    QSpinBox * mColSpin;
};

#endif // ASSOCIATEBARMODE_H
