#ifndef FIGUR_H
#define FIGUR_H

#include <string>

class figur
{
public:
    enum FigurTyp {KÖNIG, DAME, TURM, SPRINGER, LÄUFER, BAUER, LEER};
    figur(FigurTyp typ, bool isBlack);                              //Konstruktor
    figur();
    bool istSchwarz;                                                //Farbe der Figur
    FigurTyp figurTyp;                                              //Typ der Figur
    std::string getPosition() const;
    void setPosition(int x, int y);
    bool getColor() const;
    std::string getFigurName() const;

private:
     std::string position;                                           //Position der Figur
};

#endif // FIGUR_H
