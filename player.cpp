#include "player.h"

// Konstruktor
Player::Player(const QString& playerName, const QColor& playerColor)
    : name(playerName), color(playerColor), turnStatus(false), hasWon(false), hasResigned(false) {}

// Getter-Methoden
QString Player::getName() const { return name; }
QColor Player::getColor() const { return color; }
bool Player::getTurnStatus() const { return turnStatus; }
bool Player::hasWonGame() const { return hasWon; }
bool Player::hasResignedGame() const { return hasResigned; }

// Setter-Methoden
void Player::setTurnStatus(bool turn) { turnStatus = turn; }
void Player::setWonGame(bool won) { hasWon = won; }
void Player::setResignedGame(bool resigned) { hasResigned = resigned; }
