#include <QCoreApplication>
#include "simpleServer.h"
#include "simpleClient.h"
#include "spiel.h"
#include "board.h"
#include <iostream>


int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   Server server;
   Client client;
   client.start("127.0.0.1",8888);

    spiel meinSpiel;
    meinSpiel.startSpiel();


    //meinBrett.printStartposition();

    meinSpiel.endSpiel();

 //   return a.exec();
}
