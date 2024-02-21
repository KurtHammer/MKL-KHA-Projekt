#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "chessboardwidget.h"

ChessboardWidget::ChessboardWidget(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0); // Abstand Felder

    QStringList colors = {"#FFFFFF", "#808080"};

    QPixmap blackpawnPixmap(":/Figuren/black_pawn.svg");
    QPixmap blackrookPixmap(":/Figuren/black_rook.svg");
    QPixmap blackknightPixmap(":/Figuren/black_knight.svg");
    QPixmap blackbishopPixmap(":/Figuren/black_bishop.svg");
    QPixmap blackqueenPixmap(":/Figuren/black_queen.svg");
    QPixmap blackkingPixmap(":/Figuren/black_king.svg");
    QPixmap whitepawnPixmap(":/Figuren/white_pawn.svg");
    QPixmap whiterookPixmap(":/Figuren/white_rook.svg");
    QPixmap whiteknightPixmap(":/Figuren/white_knight.svg");
    QPixmap whitebishopPixmap(":/Figuren/white_bishop.svg");
    QPixmap whitequeenPixmap(":/Figuren/white_queen.svg");
    QPixmap whitekingPixmap(":/Figuren/white_king.svg");


    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = new QPushButton(this);
            QLabel *label = new QLabel(this);
            button->setFixedSize(100, 100); // Größe der Felder
            button->setStyleSheet(QString("background-color: %1").arg(colors[(row + col) % 2]));

            layout->addWidget(button, row, col);

            // Definiere eine Map für die Startpositionen der Figuren
            std::map<std::pair<int, int>, QPixmap> startPositions = {
                {{0, 0}, blackrookPixmap},     // Turm Schwarz
                {{0, 1}, blackknightPixmap},   // Springer Schwarz
                {{0, 2}, blackbishopPixmap},   // Läufer Schwarz
                {{0, 3}, blackqueenPixmap},    // Dame Schwarz
                {{0, 4}, blackkingPixmap},     // König Schwarz
                {{0, 5}, blackbishopPixmap},   // Läufer Schwarz
                {{0, 6}, blackknightPixmap},   // Springer Schwarz
                {{0, 7}, blackrookPixmap},     // Turm Schwarz
                {{1, 0}, blackpawnPixmap},     // Bauer 1 Schwarz
                {{1, 1}, blackpawnPixmap},     // Bauer 2 Schwarz
                {{1, 2}, blackpawnPixmap},     // Bauer 3 Schwarz
                {{1, 3}, blackpawnPixmap},     // Bauer 4 Schwarz
                {{1, 4}, blackpawnPixmap},     // Bauer 5 Schwarz
                {{1, 5}, blackpawnPixmap},     // Bauer 6 Schwarz
                {{1, 6}, blackpawnPixmap},     // Bauer 7 Schwarz
                {{1, 7}, blackpawnPixmap},     // Bauer 8 Schwarz
                {{7, 8}, whiterookPixmap},     // Turm Weiß
                {{7, 1}, whiteknightPixmap},   // Springer Weiß
                {{7, 2}, whitebishopPixmap},   // Läufer Weiß
                {{7, 3}, whitequeenPixmap},    // Dame Weiß
                {{7, 4}, whitekingPixmap},     // König Weiß
                {{7, 5}, whitebishopPixmap},   // Läufer Weiß
                {{7, 6}, whiteknightPixmap},   // Springer Weiß
                {{7, 7}, whiterookPixmap},     // Turm Weiß
                {{6, 0}, whitepawnPixmap},      // Bauer Weiß
                {{6, 1}, whitepawnPixmap},      // Bauer Weiß
                {{6, 2}, whitepawnPixmap},      // Bauer Weiß
                {{6, 3}, whitepawnPixmap},      // Bauer Weiß
                {{6, 4}, whitepawnPixmap},      // Bauer Weiß
                {{6, 5}, whitepawnPixmap},      // Bauer Weiß
                {{6, 6}, whitepawnPixmap},      // Bauer Weiß
                {{6, 7}, whitepawnPixmap}      // Bauer Weiß
            };

            // Überprüfe, ob die gegebene Position eine Startposition ist, und wenn ja, platziere die entsprechende Figur
            auto it = startPositions.find(std::make_pair(row, col));
            if (it != startPositions.end()) {
                label->setPixmap(it->second);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }
        }
    }

    // Neustart-Button erstellen und hinzufügen
    QPushButton *restartButton = new QPushButton("Neustart", this);
    layout->addWidget(restartButton, 0, 8); // Zum Layout hinzufügen, Position (8, 0)

    // Aufgeben-Button erstellen und hinzufügen
    QPushButton *surrenderButton = new QPushButton("Aufgeben", this);
    layout->addWidget(surrenderButton, 1, 8); // Zum Layout hinzufügen, Position (8, 1)

    // Hier könntest du die Signale und Slots für die Buttons verbinden


}

void ChessboardWidget::restartGame() {
    // Logik für Neustart des Spiels hier einfügen
}

void ChessboardWidget::surrenderGame() {
    // Logik für Aufgeben des Spiels hier einfügen
}
