#ifndef USBQUERY_H
#define USBQUERY_H

#include <QSerialPort>
#include <communication/query.h>

class UsbQuery : public Query
{
    Q_OBJECT
public:
    explicit UsbQuery(Query * parent = Q_NULLPTR);
    void fixedQuery() override;
    void monitorQuery(MONITORROLE,const QByteArray&) override;
    void terminalQuery(const QByteArray &) override;
    void setDevice(QIODevice *) override;
    bool isOpen() override;
private:
    QSerialPort * mPort;
signals:
      void errorCode(USBERROR);
};

#endif // USBQUERY_H
