#ifndef SPIEL_H
#define SPIEL_H
#include "board.h"


class spiel
{
public:
    spiel();
    void startSpiel();
    void endSpiel();
private:
    board meinBrett;
    bool isGameOver;
    int currentPlayer;

    bool isValidMove(int startX, int startY, int endX, int endY, int currentPlayer, int zugNummer);
    void makeMove(const std::string& move);
    bool isCheckmate();
    bool isDraw();

    bool validPawnMove(int startX, int startY, int endX, int endY, int currentPlayer, int zugNummer);
};

#endif // SPIEL_H
