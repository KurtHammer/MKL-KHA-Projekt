#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>

class ChessboardWidget : public QWidget {
    Q_OBJECT
public:
    explicit ChessboardWidget(QWidget *parent = nullptr);

private slots:
    void restartGame();
    void surrenderGame();


};

#endif // CHESSBOARDWIDGET_H

