#ifndef SIMPLECLIENT_H
#define SIMPLECLIENT_H

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>

class Client: public QObject
{
    Q_OBJECT
public:
    Client(QObject* parent = 0);
    ~Client();
    void start( QString address, quint16 port );
public slots:
    void startTransfer();
    void startRead();
private:
    QTcpSocket *client;
};

#endif // SIMPLECLIENT_H

