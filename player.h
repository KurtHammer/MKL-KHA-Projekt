#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QColor>

class Player {
private:
    QString name;
    QColor color;
    bool turnStatus;
    bool hasWon;
    bool hasResigned;

public:
    Player(const QString& playerName, const QColor& playerColor);

    // Getter-Methoden
    QString getName() const;
    QColor getColor() const;
    bool getTurnStatus() const;
    bool hasWonGame() const;
    bool hasResignedGame() const;

    // Setter-Methoden
    void setTurnStatus(bool turn);
    void setWonGame(bool won);
    void setResignedGame(bool resigned);
};

#endif // PLAYER_H
