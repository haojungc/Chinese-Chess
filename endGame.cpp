#include "mainwindow.h"

void MainWindow::showWinner(){
    // set label
    winnerLabel->setGeometry(90, 300, 500, 100);

    // show winner
    if(winner == 1)
        winnerLabel->setText(tr("Winner is Player 1"));
    else {
        winnerLabel->setText(tr("Winner is Player 2"));
    }

    // set font
    font = winnerLabel->font();
    font.setPointSize(32);
    font.setBold(true);
    winnerLabel->setFont(font);
    winnerLabel->setAlignment(Qt::AlignCenter);

    winnerLabel->show();
    playerLabel->hide();
}

void MainWindow::showEndGameBackground(){
    endGameBackground->show();
}
