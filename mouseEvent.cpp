#include "mainwindow.h"

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << event->pos() << endl;

        if(gameover == false && isInRange(event->x(), event->y())){
        convertPos(event->x(), event->y());

        // start timer
        timer->start(1000);
        time.start();
        showTime();
        connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));

        if(editMode == false){
        switch(player){
        case 1:{ // red: player 1
            if(board[xPos][yPos] >= 16){                
                hidePath();
                this->clickedChess = board[xPos][yPos];
                showPath();
            }

            else if(path[xPos][yPos]->isVisible()){                
                moveChess(xPos, yPos);
                hidePath();
                player = 2;
                checkWin();
                showPlayer();
                player2_label->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
                player1_label->setFrameStyle(QFrame::NoFrame);
            }

            else{
                qDebug() << "Wrong Place" << endl;
            }

            break;
        }
        case 2:{ // black: player 2
            if(board[xPos][yPos] < 16 && board[xPos][yPos] != NAN){
                hidePath();
                this->clickedChess = board[xPos][yPos];
                showPath();
            }

            else if(path[xPos][yPos]->isVisible()){
                moveChess(xPos, yPos);
                hidePath();
                player = 1;
                checkWin();
                showPlayer();
                player1_label->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
                player2_label->setFrameStyle(QFrame::NoFrame);
            }

            else{
                qDebug() << "Wrong Place" << endl;
            }
            break;
        }
        }
        }

        else if(editMode == true){
            if(board[xPos][yPos] != NAN){
                this->clickedChess = board[xPos][yPos];
                showPath();
            }

            else if(path[xPos][yPos]->isVisible()){
                moveChess(xPos, yPos);
                hidePath();
            }
        }
        }

        else if(gameover == true){
            qDebug() << "GAME ENDS" << endl;
        }

        else{
            qDebug() << "Out of Range" << endl;
        }
    }
}


void MainWindow::convertPos(int x, int y){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 10; j++){
            if(x >= X[i] - chessSize/2 && x <= X[i] + chessSize/2 && y >= Y[j] - chessSize/2 && y <= Y[j] + chessSize/2){
                xPos = i;
                yPos = j;
                return;
            }
        }
    }
}

bool MainWindow::isInRange(int x, int y){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 10; j++){
            // in range
            if(x >= X[i] - chessSize/2 && x <= X[i] + chessSize/2 && y >= Y[j] - chessSize/2 && y <= Y[j] + chessSize/2){
                xPos = i;
                yPos = j;
                return true;
            }
        }
    }

    // not in range
    return false;
}
