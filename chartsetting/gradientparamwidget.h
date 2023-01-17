#ifndef GRADIENTPARAMWIDGET_H
#define GRADIENTPARAMWIDGET_H

#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QRadioButton>
#include <messagebox/critical.h>
#include <chartsetting/gradientparamselectorwidget.h>

class GradientParamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GradientParamWidget(QGradient::Type,QWidget *parent = Q_NULLPTR);
    QVector<QPair<qreal,QColor>> defaultColors() const;
    void setGradientDescription(const QString&);
    void addGradientDescription(const QString&);
    void addGradientLayout(QLayout*);
    void addGradientWidget(QWidget*);
    void insertGradientLayout(int,QLayout*);
    void insertGradientWidget(int,QWidget*);
protected:
    QVBoxLayout * mGradientLayout;
    QPushButton * mOkBtn;
private:
    Critical * mCriticalDlg;
    bool mCriticalDlgIsCalled;
    QGradient::Type mGradientType;
    GradientParamSelectorWidget * mParamSelector;
    QTextEdit* mGradientDescription;
    QRadioButton * mSelectColorBtn;
    QRadioButton * mSelectTextBtn;
    QVector<QPair<qreal,QColor>> inputedColors(const QString&);//子类需要这个函数
    QPair<qreal,QColor> takeStepColor(const QString&);
    bool checkStepColor(const QString&);
    bool checkStep(const QString&);
    bool checkColor(const QString&);
    QList<int> takeRgb(const QString&,int = 3);
    bool checkRgb(const QString&);
signals:
    void gradientParams(QVector<QPair<qreal,QColor>>,QGradient::Type); // 3类共用
};
#endif // GRADIENTPARAMWIDGET_H
