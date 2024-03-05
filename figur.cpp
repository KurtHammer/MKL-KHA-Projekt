#include "figur.h"
#include "utilities.h"

figur::figur(FigurTyp typ, bool isBlack){
    figurTyp = typ;
    istSchwarz = isBlack;
}

figur::figur() : figur(LEER, true) {}

std::string figur::getPosition() const {
    return position;
}

bool figur::getColor() const {
    return istSchwarz;
}

void figur::setPosition(int x, int y) {
    position = convertToChessNotation(x, y);
}

std::string figur::getFigurName() const {
    switch(figurTyp) {
        case KÖNIG: return istSchwarz ? "König Schwarz" : "König Weiß";
        case DAME: return istSchwarz ? "Dame Schwarz" : "Dame Weiß";
        case TURM: return istSchwarz ? "Turm Schwarz" : "Turm Weiß";
        case SPRINGER: return istSchwarz ? "Springer Schwarz" : "Springer Weiß";
        case LÄUFER: return istSchwarz ? "Läufer Schwarz" : "Läufer Weiß";
        case BAUER: return istSchwarz ? "Bauer Schwarz" : "Bauer Weiß";
        default: return "Unbekannt"; // Falls ein unbekannter Figurtyp vorliegt
    }
}
