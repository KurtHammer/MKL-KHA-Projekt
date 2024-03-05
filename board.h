#ifndef BOARD_H
#define BOARD_H

#include "figur.h"
#include <vector>


class board
{
public:
    board();
    void addFigur(const figur& f, int x, int y);
    figur getFigurAtPosition(int x, int y) const;
    void setupStartposition();
    void printCurrentPosition() const;
    void resetBoard();
    void movePiece(int startX, int startY, int endX, int endY);

private:
    std::vector<std::vector<figur>> brett;
};

#endif // BOARD_H
