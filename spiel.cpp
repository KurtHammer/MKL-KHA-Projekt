#include "spiel.h"
#include "board.h"
#include "figur.h"
#include "utilities.h"
#include <iostream>
#include <fstream>

using namespace std;

spiel::spiel()
{

}

void spiel::startSpiel(){
    this->brett.setupStartposition();
    isGameOver = false;
    int currentPlayer = 1;
    int zugNummer = 0;
    int startX = 0, startY = 0, endX = 0, endY = 0;

    std::cout << "Spiel Start" << std::endl; // Debugging-Ausgabe hinzugefügt


    // Öffne die CSV-Datei zum Schreiben
    ofstream file("/home/schueler/Projekte/chess2/spielverlauf.csv");
    if (!file.is_open()) {
        cerr << "Fehler beim Öffnen der Datei!" << endl;
            return;
    }

    // Schreibe die Kopfzeile in die CSV-Datei
    file << "Zugnummer, Spieler, Startposition, Endposition" << endl;

    while (!isGameOver) {
        // Spielerwechsel
        if (currentPlayer == 1) {
            std::cout << "Spieler 1 ist am Zug." << std::endl;
        } else {
            std::cout << "Spieler 2 ist am Zug." << std::endl;
        }

        // Eingabe des Spielers abfragen
        std::cout << "Geben Sie die Startposition (x y) und die Endposition (x y) ein: ";
        std::cin >> startX >> startY >> endX >> endY;

        std::cout << "Typ der Startfigur 111: " << brett.getFigurAtPosition(startX, startY).getFigurName() << std::endl;

        // Zug überprüfen und durchführen
        if (isValidMove(startX, startY, endX, endY, currentPlayer, zugNummer)) {
            std::cout << "Typ der Startfigur: " << brett.getFigurAtPosition(startX, startY).getFigurName() << std::endl;
            brett.movePiece(startX, startY, endX, endY);

            if ((currentPlayer == 1 && zugNummer % 2 == 0) || (currentPlayer == 2 && zugNummer % 2 == 1)) {
                // Inkrementiere die Zugnummer nur nach jedem zweiten Zug
                zugNummer++;
            }

            // Konvertiere Koordinaten in Schachnotation
            std::string startCoord = convertToChessNotation(startX, startY);
            std::string endCoord = convertToChessNotation(endX, endY);

            // Schreibe den Zug in die CSV-Datei
            file << zugNummer << ", " << currentPlayer << ", " << startCoord << ", " << endCoord << endl;

            //std::cout << "Aktuelle Positionen der Figuren:" << std::endl;
            //brett.printCurrentPosition();

            if (isCheckmate()) {
                std::cout << "Spieler " << currentPlayer << " gewinnt!" << std::endl;
                isGameOver = true;
            } else {
                // Spieler wechseln
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else {
            std::cout << "Ungültiger Zug. Bitte versuchen Sie es erneut." << std::endl;
        }
    }
}



bool spiel::isValidMove(int startX, int startY, int endX, int endY, int currentPlayer, int zugNummer) {
    // Start und Endposition im Spielfeld
    if (startX >= 0 && startX <= 7 && startY >= 0 && startY <= 7 && endX >= 0 && endX <= 7 && endY >= 0 && endY <= 7) {
        figur startFigur = brett.getFigurAtPosition(startX, startY);
        figur endFigur = brett.getFigurAtPosition(endX, endY);

        // Debugging-Ausgabe: Startposition und Figurtyp
        std::cout << "Startposition: (" << startX << ", " << startY << ")" << std::endl;
        std::cout << "Typ der Startfigur 111: " << brett.getFigurAtPosition(startX, startY).getFigurName() << std::endl;

        // Überprüfen, ob die Startposition leer ist
        if (startFigur.figurTyp == figur::LEER) {
            std::cout << "Feld leer" << std::endl;
            return false;
        }

        // Überprüfen, ob der Spieler seine eigene Figur bewegt
        if ((startFigur.istSchwarz && currentPlayer == 1) || (!startFigur.istSchwarz && currentPlayer == 2)) {
            std::cout << "Sie können nur Ihre eigenen Figuren bewegen." << std::endl;
                return false;
        }

        // Bauern Move prüfen
        if (startFigur.figurTyp == figur::BAUER) {
            // Aufruf der validPawnMove-Funktion für den Bauern
            return validPawnMove(startX, startY, endX, endY, currentPlayer, zugNummer);
        }
        return true;
    } else {
        std::cout << "Koordinate nicht im Feld" << std::endl;
        return false;
    }
}

bool spiel::validPawnMove(int startX, int startY, int endX, int endY, int currentPlayer, int zugNummer){
    figur startFigur = brett.getFigurAtPosition(startX, startY);

    // Überprüfen, ob der Spieler seine eigene Figur bewegt
    if ((startFigur.istSchwarz && currentPlayer == 1) || (!startFigur.istSchwarz && currentPlayer == 2)) {
    std::cout << "Sie können nur Ihre eigenen Figuren bewegen." << std::endl;
    return false;
    }

    // Überprüfen, ob der Bauer in die richtige Richtung zieht
    if ((currentPlayer == 1 && endY > startY) || (currentPlayer == 2 && endY < startY)) {
    std::cout << "Bauer zieht in falsche Richtung." << std::endl;
    return false;
    }

    // Bauer zieht 2 Felder vor im ersten Zug
    if (((currentPlayer == 1 && startY == 6 && endY == 4) || (currentPlayer == 2 && startY == 1 && endY == 3))) {
    // Der Bauer zieht zwei Felder vorwärts
    return true;
    }

    // Bauer zieht 1 feld vor
    if ((endY == startY - 1 && currentPlayer == 1) || (endY == startY + 1 && currentPlayer == 2)) {
    return true;
    }

        // Weitere Überprüfungen für spezielle Bauerzüge...

        return true;


}



void spiel::makeMove(const std::string& move) {
    // Implementiere das Aktualisieren des Spielbretts entsprechend dem Zug
}

bool spiel::isCheckmate() {

    return false;
}

bool spiel::isDraw() {
    // Implementiere die Überprüfung auf Remis
}

void spiel::endSpiel() {
    brett.resetBoard(); // Setze das Spielbrett zurück
}
