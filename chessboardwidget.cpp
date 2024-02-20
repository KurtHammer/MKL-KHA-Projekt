#include <QGridLayout>
#include <QPushButton>
#include "chessboardwidget.h"

ChessboardWidget::ChessboardWidget(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);
    layout->setSpacing(0); // Abstand Felder

    QStringList colors = {"#FFFFFF", "#808080"};
    
    

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(100, 100); // Größe der Felder
            button->setStyleSheet(QString("background-color: %1").arg(colors[(row + col) % 2]));

            layout->addWidget(button, row, col);

            // Hier könntest du Signale und Slots verbinden, um auf Klicks zu reagieren
        }
    }

    // Neustart-Button erstellen und hinzufügen
    QPushButton *restartButton = new QPushButton("Neustart", this);
    layout->addWidget(restartButton, 8, 0); // Zum Layout hinzufügen, Position (8, 0)

    // Aufgeben-Button erstellen und hinzufügen
    QPushButton *surrenderButton = new QPushButton("Aufgeben", this);
    layout->addWidget(surrenderButton, 8, 1); // Zum Layout hinzufügen, Position (8, 1)

    // Hier könntest du die Signale und Slots für die Buttons verbinden


}

void ChessboardWidget::restartGame() {
    // Logik für Neustart des Spiels hier einfügen
}

void ChessboardWidget::surrenderGame() {
    // Logik für Aufgeben des Spiels hier einfügen
}
