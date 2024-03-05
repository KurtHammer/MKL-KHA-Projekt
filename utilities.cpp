// utilities.cpp

#include "utilities.h"

std::string convertToChessNotation(int x, int y) {
    char column = 'A' + x;
    char row = '1' + y;
    return std::string(1, column) + std::string(1, row);
}


bool convertFromChessNotation(const std::string& notation, int& x, int& y) {
    if (notation.length() != 2) {
        return false;
    }

    char column = std::toupper(notation[0]); // Die Spalte ist der erste Buchstabe der Notation
    char row = notation[1]; // Die Zeile ist der zweite Buchstabe der Notation

    if (column < 'A' || column > 'H' || row < '1' || row > '8') {
        return false; // Die Schachnotation entspricht nicht den erlaubten Werten
    }

    // Konvertiere den Spaltenbuchstaben in eine Zahl (0-7)
    x = column - 'A';

    // Konvertiere die Zeile in eine Zahl (0-7)
    y = row - '1';

    return true;
}
