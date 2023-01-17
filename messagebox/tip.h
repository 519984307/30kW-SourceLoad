#ifndef TIP_H
#define TIP_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
//#include <QPaintEvent>
//#include <QPainter>

class Tip : public QDialog
{
    Q_OBJECT
public:
    explicit Tip();
    explicit Tip(const QString&);
    void setTip(const QString&);
private:
    //void paintEvent(QPaintEvent *) override;
    void init();
    QLabel * mTip;
    QPushButton * mBtn;
    QGroupBox * mBox;
};

#endif // TIP_H
