#include "board.h"
#include "utilities.h"
#include "figur.h"
#include <iostream>

board::board() {
    brett.resize(8, std::vector<figur>(8, figur(figur::LEER, true))); // Initialisiere den Vektor mit der richtigen Größe

    // Initialisiere jedes figur-Objekt im Vektor brett
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            brett[y][x] = figur(figur::LEER, true); // Verwende den Standardkonstruktor von figur
        }
    }
}

void board::addFigur(const figur& f, int x, int y) {
    figur copy = f; // Kopie der Figur erstellen
    copy.setPosition(x, y); // Position setzen
    brett[y][x] = copy; // Figur hinzufügen
}

figur board::getFigurAtPosition(int x, int y) const {
    return brett[y][x];
}

void board::resetBoard(){
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            brett[y][x].setPosition(-1, -1); // Setze die Position auf ungültige Werte
        }
    }
}

void board::setupStartposition() {
    std::cout << "Setup der Startposition..." << std::endl; // Debugging-Ausgabe hinzugefügt
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            brett[y][x].setPosition(-1, -1); // Setze die Position auf ungültige Werte
        }
    }
    for (int x = 0; x < 8;  x++){
        addFigur(figur(figur::BAUER, true), x, 1);  // Bauern Schwarz
        std::cout << "Figurtyp auf Position (" << x << ", 1): " << brett[1][x].getFigurName() << std::endl;
    }
    addFigur(figur(figur::TURM, true), 0, 0);      // Turm Schwarz 1
    addFigur(figur(figur::TURM, true), 7, 0);      // Turm Schwarz 2
    addFigur(figur(figur::SPRINGER, true), 1, 0);  // Springer Schwarz 1
    addFigur(figur(figur::SPRINGER, true), 6, 0);  // Springer Schwarz 2
    addFigur(figur(figur::LÄUFER, true), 2, 0);    // Läufer Schwarz 1
    addFigur(figur(figur::LÄUFER, true), 5, 0);    // Läufer Schwarz 2
    addFigur(figur(figur::DAME, true), 3, 0);      // Dame Schwarz
    addFigur(figur(figur::KÖNIG, true), 4, 0);     // König Schwarz

    for (int x = 0; x < 8;  x++){
        addFigur(figur(figur::BAUER, false), x, 6);  // Bauern Weiß
    }
    addFigur(figur(figur::TURM, false), 0, 7);      // Turm Weiß 1
    addFigur(figur(figur::SPRINGER, false), 1, 7);  // Springer Weiß 1
    addFigur(figur(figur::LÄUFER, false), 2, 7);    // Läufer Weiß 1
    addFigur(figur(figur::DAME, false), 3, 7);      // Dame Weiß
    addFigur(figur(figur::KÖNIG, false), 4, 7);     // König Weiß
    addFigur(figur(figur::LÄUFER, false), 5, 7);    // Läufer Weiß 2

    addFigur(figur(figur::SPRINGER, false), 6, 7);  // Springer Weiß 2
    addFigur(figur(figur::TURM, false), 7, 7);      // Turm Weiß 2

}

void board::printCurrentPosition() const {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            figur currentFigur = brett[y][x];
            if (currentFigur.figurTyp != figur::LEER) {
                std::string position = convertToChessNotation(x, y);
                std::cout << currentFigur.getFigurName() << ", Position: " << position << std::endl;
            }
        }
    }
}

void board::movePiece(int startX, int startY, int endX, int endY) {

    // Figur von der Startposition holen
    figur& startPiece = brett[startY][startX];
    std::cout << "Startfigur: " << startPiece.getFigurName() << std::endl;

    // Figur von der Endposition holen
    figur& endPiece = brett[endY][endX];
    std::cout << "Endfigur: " << endPiece.getFigurName() << std::endl;

    // Bewege die Figur zur Zielposition
    endPiece = startPiece;
    endPiece.setPosition(endX, endY);

    // Setze die Startposition auf LEER
    startPiece = figur(figur::LEER, true);
}
