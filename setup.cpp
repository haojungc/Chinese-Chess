#include "mainwindow.h"

void MainWindow::loadImage(){
    // add images
    QPixmap background(":/img/src/board.jpg");

    // addPixmap returns a QGraphicsPixmapItem
    this->scene->addPixmap(background.scaled(650, 650));

    // add black chess pieces
    chessPiece[BLACK_KING] = scene->addPixmap(QPixmap(":/img/src/blackJiang.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SHI_1] = scene->addPixmap(QPixmap(":/img/src/blackShi.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SHI_2] = scene->addPixmap(QPixmap(":/img/src/blackShi.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_XIANG_1] = scene->addPixmap(QPixmap(":/img/src/blackXiang.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_XIANG_2] = scene->addPixmap(QPixmap(":/img/src/blackXiang.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_MA_1] = scene->addPixmap(QPixmap(":/img/src/blackMa.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_MA_2] = scene->addPixmap(QPixmap(":/img/src/blackMa.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_PAO_1] = scene->addPixmap(QPixmap(":/img/src/blackPao.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_PAO_2] = scene->addPixmap(QPixmap(":/img/src/blackPao.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_JU_1] = scene->addPixmap(QPixmap(":/img/src/blackJu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_JU_2] = scene->addPixmap(QPixmap(":/img/src/blackJu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SOLDIER_1] = scene->addPixmap(QPixmap(":/img/src/blackZu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SOLDIER_2] = scene->addPixmap(QPixmap(":/img/src/blackZu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SOLDIER_3] = scene->addPixmap(QPixmap(":/img/src/blackZu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SOLDIER_4] = scene->addPixmap(QPixmap(":/img/src/blackZu.png").scaled(chessSize, chessSize));
    chessPiece[BLACK_SOLDIER_5] = scene->addPixmap(QPixmap(":/img/src/blackZu.png").scaled(chessSize, chessSize));

    // add red chess pieces
    chessPiece[RED_KING] = scene->addPixmap(QPixmap(":/img/src/redShuai.png").scaled(chessSize, chessSize));
    chessPiece[RED_SHI_1] = scene->addPixmap(QPixmap(":/img/src/redShi.png").scaled(chessSize, chessSize));
    chessPiece[RED_SHI_2] = scene->addPixmap(QPixmap(":/img/src/redShi.png").scaled(chessSize, chessSize));
    chessPiece[RED_XIANG_1] = scene->addPixmap(QPixmap(":/img/src/redXiang.png").scaled(chessSize, chessSize));
    chessPiece[RED_XIANG_2] = scene->addPixmap(QPixmap(":/img/src/redXiang.png").scaled(chessSize, chessSize));
    chessPiece[RED_MA_1] = scene->addPixmap(QPixmap(":/img/src/redMa.png").scaled(chessSize, chessSize));
    chessPiece[RED_MA_2] = scene->addPixmap(QPixmap(":/img/src/redMa.png").scaled(chessSize, chessSize));
    chessPiece[RED_PAO_1] = scene->addPixmap(QPixmap(":/img/src/redPao.png").scaled(chessSize, chessSize));
    chessPiece[RED_PAO_2] = scene->addPixmap(QPixmap(":/img/src/redPao.png").scaled(chessSize, chessSize));
    chessPiece[RED_JU_1] = scene->addPixmap(QPixmap(":/img/src/redJu.png").scaled(chessSize, chessSize));
    chessPiece[RED_JU_2] = scene->addPixmap(QPixmap(":/img/src/redJu.png").scaled(chessSize, chessSize));
    chessPiece[RED_SOLDIER_1] = scene->addPixmap(QPixmap(":/img/src/redBing.png").scaled(chessSize, chessSize));
    chessPiece[RED_SOLDIER_2] = scene->addPixmap(QPixmap(":/img/src/redBing.png").scaled(chessSize, chessSize));
    chessPiece[RED_SOLDIER_3] = scene->addPixmap(QPixmap(":/img/src/redBing.png").scaled(chessSize, chessSize));
    chessPiece[RED_SOLDIER_4] = scene->addPixmap(QPixmap(":/img/src/redBing.png").scaled(chessSize, chessSize));
    chessPiece[RED_SOLDIER_5] = scene->addPixmap(QPixmap(":/img/src/redBing.png").scaled(chessSize, chessSize));

    endGameBackground = scene->addRect(-10, -20, 720, 700, whitePen, *whiteBrush);
}

void MainWindow::initialize(){ 
    // initialize board & draw hidden path
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 10; j++){
            board[i][j] = NAN;
            path[i][j] = scene->addEllipse(X[i]-26, Y[j]-45, 20, 20, redPen, *redBrush);
            path[i][j]->hide();
        }

    // initialize xGrid & yGrid & alive
    for(int i = 0; i < 32; i++){
        xGrid[i] = NAN;
        yGrid[i] = NAN;
        status[i] = ALIVE;
    }

    // set chessPiece offset
    for(int i = 0; i < 32; i++){
        chessPiece[i]->setOffset(-45, -66);
    }

    // set chessPiece position
    for(int i = BLACK_JU_1; i <= BLACK_JU_2; i++){
        chessPiece[i]->setPos(X[i], Y[0]);
        chessPiece[i + 16]->setPos(X[i], Y[9]);
        xGrid[i] = i;
        yGrid[i] = 0;
        xGrid[i + 16] = i;
        yGrid[i + 16] = 9;

        // remember which chessPiece is on the board
        board[i][0] = i;
        board[i][9] = i + 16;
    }

    for(int i = BLACK_SOLDIER_1; i <= BLACK_SOLDIER_5; i++){
        chessPiece[i]->setPos(X[(i-BLACK_SOLDIER_1)*2], Y[3]);
        chessPiece[i + 16]->setPos(X[(i-BLACK_SOLDIER_1)*2], Y[6]);
        xGrid[i] = (i-BLACK_SOLDIER_1)*2;
        yGrid[i] = 3;
        xGrid[i + 16] = (i-BLACK_SOLDIER_1)*2;
        yGrid[i + 16] = 6;

        // remember which chessPiece is on the board
        board[(i-BLACK_SOLDIER_1)*2][3] = i;
        board[(i-BLACK_SOLDIER_1)*2][6] = i + 16;
    }

    // black pao
    chessPiece[BLACK_PAO_1]->setPos(X[1], Y[2]);
    xGrid[BLACK_PAO_1] = 1;
    yGrid[BLACK_PAO_1] = 2;
    chessPiece[BLACK_PAO_2]->setPos(X[7], Y[2]);
    xGrid[BLACK_PAO_2] = 7;
    yGrid[BLACK_PAO_2] = 2;

    // red pao
    chessPiece[RED_PAO_1]->setPos(X[1], Y[7]);
    xGrid[RED_PAO_1] = 1;
    yGrid[RED_PAO_1] = 7;
    chessPiece[RED_PAO_2]->setPos(X[7], Y[7]);
    xGrid[RED_PAO_2] = 7;
    yGrid[RED_PAO_2] = 7;

    // remember which chessPiece is on the board
    board[1][2] = BLACK_PAO_1;
    board[7][2] = BLACK_PAO_2;
    board[1][7] = RED_PAO_1;
    board[7][7] = RED_PAO_2;

    showImg();
    hidePath();
    winnerLabel->hide();
    endGameBackground->hide();

    gameover = false;
    player = 1;
    winner = 0;
    playerLabel->show();
}

void MainWindow::showTime(){
    //int min = time.elapsed()/60;
    //int sec = time.elapsed()%60;
}

void MainWindow::showImg(){
    for(int i = 0; i < 32; i++)
        chessPiece[i]->show();
}
