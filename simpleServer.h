#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <QObject>

// Darauf achten, dass in der .pro-Datei folgender Eintrag steht
// QT += network
// Falls nachträglich hinzugefügt, dann qmake nocheinmal starten
// sonst werden die beiden folgenden Zeilen nicht erkannt
#include <QTcpServer>
#include <QTcpSocket>


#define MAXCLIENT 2

class Server: public QObject
{
    Q_OBJECT
public:
    Server(QObject * parent = 0);
    ~Server();

public slots:
    void acceptConnection();
    void startRead();
private:
    QTcpServer *server;
    QTcpSocket* client;
};
#endif // SIMPLESERVER_H

