#include <QApplication>
#include "chessboardwidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    ChessboardWidget widget;
    widget.show();

    return app.exec();


}
