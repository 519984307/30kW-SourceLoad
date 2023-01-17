#ifndef CHARTTOOLWIDGET_H
#define CHARTTOOLWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QGroupBox>

class ChartToolWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChartToolWidget(QWidget *parent = Q_NULLPTR);
    void addGroupBox(QGroupBox*);
    void addLayout(QLayout*);
    void updateScrollArea();
private:
    QVBoxLayout * mainLayout;
    QScrollArea * mScrollArea;
    QWidget * mWidget;
    QVBoxLayout * mWidgetLayout;
};

#endif // CHARTTOOLWIDGET_H
