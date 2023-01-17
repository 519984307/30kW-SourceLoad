#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QIntValidator>
#include <QPaintEvent>
#include <QPainter>
#include <QGroupBox>
#include <QThread>
#include <QDebug>
#include <communication/usbconfig.h>
#include <communication/usbquery.h>
#include <communication/tcpquery.h>
#include <monitor/monitor.h>
#include <log/log.h>
#include <messagebox/warning.h>
#include <messagebox/infomation.h>
#include <messagebox/critical.h>

class Communication : public QDialog
{
    Q_OBJECT
public:
    explicit Communication(QWidget * parent = Q_NULLPTR);
    enum Type {None,Serial, Tcp};

    WORKMODE workmode() const;
    void setWorkMode(WORKMODE);

    UsbConfig::Settings usbSettings() const;
    void setUsbSettings(UsbConfig::Settings);

    QIODevice * device(Type) const;
    Monitor * monitor() const;

private:
    void initConnections();
    bool needUpdateWorkMode();
    void showInfo(const QString&);
    void initLogPathInfo();
    void showLogPathInfo(const QString&);
    void closeEvent(QCloseEvent *) override;
    void paintEvent(QPaintEvent *) override;

    static const quint32 mFixedQueryTime = 300;
    WORKMODE mWorkMode;
    Communication::Type mCommunicationType;

    UsbConfig mUsbSettings;
    Monitor * mMonitor;
    Log * mLog;

    QSerialPort * mUsbPort;
    QThread * mUsbQueryThread;
    UsbQuery * mUsbQueryWorker;
    QTimer * mUsbQueryTimer;

    QString mTcpIP;
    quint16 mTcpPort;
    QTcpSocket * mTcpSocket;
    QThread * mTcpQueryThread;
    TcpQuery * mTcpQueryWorker;
    QTimer * mTcpQueryTimer;

    Infomation * mInfo;
    Infomation * mLogPathInfo;
    bool mLogPathInfoIsShow;

    QPushButton * mUsbConnectBtn;
    QPushButton * mUsbDisconnectBtn;
    QPushButton * mUsbConfigureBtn;
    QPushButton * mTcpConnectBtn;
    QPushButton * mTcpDisconnectBtn;
    QPushButton * mTcpConfigureBtn;
private slots:
    void record(const QList<QByteArray>&);
    void record(MONITORROLE,const QByteArray&,const QByteArray&);
    void record(const QByteArray&,const QByteArray&);
    void monitorQuery(MONITORROLE,const QByteArray&);
    void terminalQuery(const QByteArray&);
    void usbError(USBERROR);
    void usbCycle();
    void usbConfigure();
    void usbConnect();
    void usbDisconnect();
    void tcpError(TCPERROR);
    void tcpCycle();
    void tcpConnect();
    void tcpDisconnect();
    void tcpConfigure();
signals:
    void getMonitorRole(MONITORROLE,const QByteArray&);
    void setMonitorRole(MONITORROLE,const QByteArray&);
    void fixedQueryData(const QList<QByteArray> &);
    void monitorQueryData(MONITORROLE,bool);
    void errorCode(TIMEOUTCODE);
    void errorCode(USBERROR);
    void errorCode(TCPERROR);
    void selectedPeriod(quint32, quint32 = 0,quint32 = 0, quint32 = 0);
    void logEnabled(bool);
    void logFileFormat(FILEFORMAT);
    void currentDevice(QIODevice*);
    void getTerminalCommand(const QByteArray&);
    void terminalQueryData(const QByteArray&);
};

#endif // COMMUNICATION_H
