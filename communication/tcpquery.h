#ifndef TCPQUERY_H
#define TCPQUERY_H

#include <QTcpSocket>
#include <communication/query.h>

class TcpQuery : public Query
{
      Q_OBJECT
public:
      explicit TcpQuery(Query *parent = Q_NULLPTR);
      void fixedQuery() override;
      void monitorQuery(MONITORROLE,const QByteArray&) override;
      void terminalQuery(const QByteArray &) override;
      void setDevice(QIODevice *) override;
      bool isOpen() override;
private:
      QTcpSocket * mTcpSocket;
signals:
      void errorCode(TCPERROR);
};

#endif // TCPQUERY_H
