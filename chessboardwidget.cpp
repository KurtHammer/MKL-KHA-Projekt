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

            if ((row == 0 && col == 0) || (row == 0 && col == 7)){          // Startposition Turm Schwarz
                label->setPixmap(blackrookPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 0 && col == 1) || (row == 0 && col == 6)){     // Startposition Springer Schwarz
                label->setPixmap(blackknightPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 0 && col == 2) || (row == 0 && col == 5)){     // Startposition Läufer Schwarz
                label->setPixmap(blackbishopPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 0 && col == 3){                                 // Startposition Dame Schwarz
                label->setPixmap(blackqueenPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 0 && col == 4){                                 // Startposition König Schwarz
                label->setPixmap(blackkingPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 1){                                             // Startposition Bauer Schwarz
                label->setPixmap(blackpawnPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 0) || (row == 7 && col == 7)){     // Startposition Turm Weiß
                label->setPixmap(whiterookPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 1) || (row == 7 && col == 6)){     // Startposition Springer Weiß
                label->setPixmap(whiteknightPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if((row == 7 && col == 2) || (row == 7 && col == 5)){     // Startposition Läufer Weiß
                label->setPixmap(whitebishopPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 7 && col == 3){                                 // Startposition Dame Weiß
                label->setPixmap(whitequeenPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 7 && col == 4){                                 // Startposition König Weiß
                label->setPixmap(blackkingPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }else if(row == 6){                                             // Startposition Bauer Weiß
                label->setPixmap(whitepawnPixmap);
                label->setAlignment(Qt::AlignCenter);
                layout->addWidget(label, row, col);
            }
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
