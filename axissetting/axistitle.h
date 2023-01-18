#ifndef AXISTITLE_H
#define AXISTITLE_H
#include <axissetting/axisbox.h>
#include <QLineEdit>
#include <QFormLayout>
#include <QCheckBox>
#include <QPushButton>

class AxisTitle : public AxisBox
{
    Q_OBJECT
public:
    explicit AxisTitle(QChart*, QAbstractAxis*,const QIcon&, QWidget*parent = Q_NULLPTR);
private:
    void updateState() override;
    QCheckBox * mAxisTitleVisible;
    QLineEdit * mAxisTitleText;
    QPushButton * mAxisTitleSetText;
    QPushButton * mAxisTitleColor;
    QComboBox * mAxisTitleBrush;
    QPushButton * mAxisTitleFont;
    void updateTitleVisibilityState();
    void updateTitleTextState();
    void updateTitleColorState();
    void updateTitleBrushState();
    void updateTitleFontState();
private slots:
    void changeVisibility(int);
    void changeText();
    void changeColor();
    void changeBrush(int);
    void changeFont();
};

#endif // AXISTITLE_H
