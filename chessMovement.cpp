#include "mainwindow.h"

void MainWindow::showPath(){
    //qDebug() << "X = " << xPos << "Y = " << yPos << endl;
    // black Ju
    if(editMode == false){
    if(clickedChess == BLACK_JU_1 || clickedChess == BLACK_JU_2){
        for(int i = xPos-1; i >= 0; i--){
            if(board[i][yPos] == NAN || board[i][yPos] >= 16){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN)
                break;
        }
        for(int i = xPos+1; i < 10; i++){
            if(board[i][yPos] == NAN || board[i][yPos] >= 16){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN)
                break;
        }
        for(int j = yPos-1; j >= 0; j--){
            if(board[xPos][j] == NAN || board[xPos][j] >= 16){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN)
                break;
        }
        for(int j = yPos+1; j < 10; j++){
            if(board[xPos][j] == NAN || board[xPos][j] >= 16){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN)
                break;
        }
    }

    // red Ju
    if(clickedChess == RED_JU_1 || clickedChess == RED_JU_2){
        for(int i = xPos-1; i >= 0; i--){
            if(board[i][yPos] == NAN || board[i][yPos] < 16){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN)
                break;
        }
        for(int i = xPos+1; i < 10; i++){
            if(board[i][yPos] == NAN || board[i][yPos] < 16){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN)
                break;
        }
        for(int j = yPos-1; j >= 0; j--){
            if(board[xPos][j] == NAN || board[xPos][j] < 16){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN)
                break;
        }
        for(int j = yPos+1; j < 10; j++){
            if(board[xPos][j] == NAN || board[xPos][j] < 16){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN)
                break;
        }
    }

    // black Ma
    if(clickedChess == BLACK_MA_1 || clickedChess == BLACK_MA_2){
        if(xPos >= 2 && board[xPos-1][yPos] == NAN){
            if(yPos >= 1 && (board[xPos-2][yPos-1] >= 16 || board[xPos-2][yPos-1] == NAN))
                path[xPos-2][yPos-1]->show();
            if(yPos <= 8 && (board[xPos-2][yPos+1] >= 16 || board[xPos-2][yPos+1] == NAN))
                path[xPos-2][yPos+1]->show();
        }
        if(xPos <= 6 && board[xPos+1][yPos] == NAN){
            if(yPos >= 1 && (board[xPos+2][yPos-1] >= 16 || board[xPos+2][yPos-1] == NAN))
                path[xPos+2][yPos-1]->show();
            if(yPos <= 8 && (board[xPos+2][yPos+1] >= 16 || board[xPos+2][yPos+1] == NAN))
                path[xPos+2][yPos+1]->show();
        }
        if(yPos >= 2 && board[xPos][yPos-1] == NAN){
            if(xPos >= 1 && (board[xPos-1][yPos-2] >= 16 || board[xPos-1][yPos-2] == NAN))
                path[xPos-1][yPos-2]->show();
            if(xPos <= 7 && (board[xPos+1][yPos-2] >= 16 || board[xPos+1][yPos-2] == NAN))
                path[xPos+1][yPos-2]->show();
        }
        if(yPos <= 7 && board[xPos][yPos+1] == NAN){
            if(xPos >= 1 && (board[xPos-1][yPos+2] >= 16 || board[xPos-1][yPos+2] == NAN))
                path[xPos-1][yPos+2]->show();
            if(xPos <= 7 && (board[xPos+1][yPos+2] >= 16 || board[xPos+1][yPos+2] == NAN))
                path[xPos+1][yPos+2]->show();
        }
    }

    // red Ma
    if(clickedChess == RED_MA_1 || clickedChess == RED_MA_2){
        if(xPos >= 2 && board[xPos-1][yPos] == NAN){
            if(yPos >= 1 && board[xPos-2][yPos-1] < 16)
                path[xPos-2][yPos-1]->show();
            if(yPos <= 8 && board[xPos-2][yPos+1] < 16)
                path[xPos-2][yPos+1]->show();
        }
        if(xPos <= 6 && board[xPos+1][yPos] == NAN){
            if(yPos >= 1 && board[xPos+2][yPos-1] < 16)
                path[xPos+2][yPos-1]->show();
            if(yPos <= 8 && board[xPos+2][yPos+1] < 16)
                path[xPos+2][yPos+1]->show();
        }
        if(yPos >= 2 && board[xPos][yPos-1] == NAN){
            if(xPos >= 1 && board[xPos-1][yPos-2] < 16)
                path[xPos-1][yPos-2]->show();
            if(xPos <= 7 && board[xPos+1][yPos-2] < 16)
                path[xPos+1][yPos-2]->show();
        }
        if(yPos <= 7 && board[xPos][yPos+1] == NAN){
            if(xPos >= 1 && board[xPos-1][yPos+2] < 16)
                path[xPos-1][yPos+2]->show();
            if(xPos <= 7 && board[xPos+1][yPos+2] < 16)
                path[xPos+1][yPos+2]->show();
        }
    }

    // black Xiang
    if(clickedChess == BLACK_XIANG_1 || clickedChess == BLACK_XIANG_2){
        if(xPos >= 2 && yPos >= 2 && board[xPos-1][yPos-1] == NAN){
            if(board[xPos-2][yPos-2] >= 16 || board[xPos-2][yPos-2] == NAN)
                path[xPos-2][yPos-2]->show();
        }
        if(xPos <= 6 && yPos >= 2 && board[xPos+1][yPos-1] == NAN){
            if(board[xPos+2][yPos-2] >= 16 || board[xPos+2][yPos-2] == NAN)
                path[xPos+2][yPos-2]->show();
        }
        if(xPos >= 2 && yPos <= 7 && board[xPos-1][yPos+1] == NAN){
            if(board[xPos-2][yPos+2] >= 16 || board[xPos-2][yPos+2] == NAN)
                path[xPos-2][yPos+2]->show();
        }
        if(xPos <= 6 && yPos <= 7 && board[xPos+1][yPos+1] == NAN){
            if(board[xPos+2][yPos+2] >= 16 || board[xPos+2][yPos+2] == NAN)
                path[xPos+2][yPos+2]->show();
        }
    }

    // red Xiang
    if(clickedChess == RED_XIANG_1 || clickedChess == RED_XIANG_2){
        if(xPos >= 2 && yPos >= 2 && board[xPos-1][yPos-1] == NAN){
            if(board[xPos-2][yPos-2] < 16 || board[xPos-2][yPos-2] == NAN)
                path[xPos-2][yPos-2]->show();
        }
        if(xPos <= 6 && yPos >= 2 && board[xPos+1][yPos-1] == NAN){
            if(board[xPos+2][yPos-2] < 16 || board[xPos+2][yPos-2] == NAN)
                path[xPos+2][yPos-2]->show();
        }
        if(xPos >= 2 && yPos <= 7 && board[xPos-1][yPos+1] == NAN){
            if(board[xPos-2][yPos+2] < 16 || board[xPos-2][yPos+2] == NAN)
                path[xPos-2][yPos+2]->show();
        }
        if(xPos <= 6 && yPos <= 7 && board[xPos+1][yPos+1] == NAN){
            if(board[xPos+2][yPos+2] < 16 || board[xPos+2][yPos+2] == NAN)
                path[xPos+2][yPos+2]->show();
        }
    }

    // black Shi
    if(clickedChess == BLACK_SHI_1 || clickedChess == BLACK_SHI_2){
        if(xPos == 3 && yPos == 0){
            if(board[xPos+1][yPos+1] >= 16 || board[xPos+1][yPos+1] == NAN)
                path[xPos+1][yPos+1]->show();
        }

        if(xPos == 3 && yPos == 2){
            if(board[xPos+1][yPos-1] >= 16 || board[xPos+1][yPos-1] == NAN)
                path[xPos+1][yPos-1]->show();
        }

        if(xPos == 4 && yPos == 1){
            if(board[xPos+1][yPos-1] >= 16 || board[xPos+1][yPos-1] == NAN)
                path[xPos+1][yPos-1]->show();
            if(board[xPos+1][yPos+1] >= 16 || board[xPos+1][yPos+1] == NAN)
                path[xPos+1][yPos+1]->show();
            if(board[xPos-1][yPos+1] >= 16 || board[xPos-1][yPos+1] == NAN)
                path[xPos-1][yPos+1]->show();
            if(board[xPos-1][yPos-1] >= 16 || board[xPos-1][yPos-1] == NAN)
                path[xPos-1][yPos-1]->show();
        }

        if(xPos == 5 && yPos == 0){
            if(board[xPos-1][yPos+1] >= 16 || board[xPos-1][yPos+1] == NAN)
                path[xPos-1][yPos+1]->show();
        }

        if(xPos == 5 && yPos == 2){
            if(board[xPos-1][yPos-1] >= 16 || board[xPos-1][yPos-1] == NAN)
                path[xPos-1][yPos-1]->show();
        }
    }

    // red Shi
    if(clickedChess == RED_SHI_1 || clickedChess == RED_SHI_2){
        if(xPos == 3 && yPos == 7){
            if(board[xPos+1][yPos+1] < 16)
                path[xPos+1][yPos+1]->show();
        }

        if(xPos == 3 && yPos == 9){
            if(board[xPos+1][yPos-1] < 16)
                path[xPos+1][yPos-1]->show();
        }

        if(xPos == 4 && yPos == 8){
            if(board[xPos+1][yPos-1] < 16)
                path[xPos+1][yPos-1]->show();
            if(board[xPos+1][yPos+1] < 16)
                path[xPos+1][yPos+1]->show();
            if(board[xPos-1][yPos+1] < 16)
                path[xPos-1][yPos+1]->show();
            if(board[xPos-1][yPos-1] < 16)
                path[xPos-1][yPos-1]->show();
        }

        if(xPos == 5 && yPos == 7){
            if(board[xPos-1][yPos+1] < 16)
                path[xPos-1][yPos+1]->show();
        }

        if(xPos == 5 && yPos == 9){
            if(board[xPos-1][yPos-1] < 16)
                path[xPos-1][yPos-1]->show();
        }
    }

    // black King
    if(clickedChess == BLACK_KING){
        if(xPos == 3 && yPos == 0){
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
        }
        if(xPos == 3 && yPos == 1){
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
        }
        if(xPos == 3 && yPos == 2){
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
        }
        if(xPos == 4 && yPos == 0){
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 4 && yPos == 1){
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 4 && yPos == 2){
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] >= 16 || board[xPos+1][yPos] == NAN)
                path[xPos+1][yPos]->show();
        }
        if(xPos == 5 && yPos == 0){
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 5 && yPos == 1){
            if(board[xPos][yPos+1] >= 16 || board[xPos][yPos+1] == NAN)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
        }
        if(xPos == 5 && yPos == 2){
            if(board[xPos-1][yPos] >= 16 || board[xPos-1][yPos] == NAN)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] >= 16 || board[xPos][yPos-1] == NAN)
                path[xPos][yPos-1]->show();
        }
    }

    // red King
    if(clickedChess == RED_KING){
        if(xPos == 3 && yPos == 7){
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
        }
        if(xPos == 3 && yPos == 8){
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
        }
        if(xPos == 3 && yPos == 9){
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
        }
        if(xPos == 4 && yPos == 7){
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 4 && yPos == 8){
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 4 && yPos == 9){
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
            if(board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
        }
        if(xPos == 5 && yPos == 7){
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
        }
        if(xPos == 5 && yPos == 8){
            if(board[xPos][yPos+1] < 16)
                path[xPos][yPos+1]->show();
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
        }
        if(xPos == 5 && yPos == 9){
            if(board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
        }
    }

    // black Pao
    if(clickedChess == BLACK_PAO_1 || clickedChess == BLACK_PAO_2){
        bool first = true;
        for(int i = xPos-1; i >= 0; i--){
            if(first == true && board[i][yPos] == NAN){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN){
                if(first == false){
                    if(board[i][yPos] >= 16){
                        path[i][yPos]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int i = xPos+1; i < 10; i++){
            if(first == true && board[i][yPos] == NAN){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN){
                if(first == false){
                    if(board[i][yPos] >= 16){
                        path[i][yPos]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int j = yPos-1; j >= 0; j--){
            if(first == true && board[xPos][j] == NAN){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN){
                if(first == false){
                    if(board[xPos][j] >= 16){
                        path[xPos][j]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int j = yPos+1; j < 10; j++){
            if(first == true && board[xPos][j] == NAN){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN){
                if(first == false){
                    if(board[xPos][j] >= 16){
                        path[xPos][j]->show();
                        break;
                    }
                }
                first = false;
            }
        }
    }

    // red Pao
    if(clickedChess == RED_PAO_1 || clickedChess == RED_PAO_2){
        bool first = true;
        for(int i = xPos-1; i >= 0; i--){
            if(first == true && board[i][yPos] == NAN){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN){
                if(first == false){
                    if(board[i][yPos] < 16){
                        path[i][yPos]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int i = xPos+1; i < 10; i++){
            if(first == true && board[i][yPos] == NAN){
                path[i][yPos]->show();
            }
            if(board[i][yPos] != NAN){
                if(first == false){
                    if(board[i][yPos] < 16){
                        path[i][yPos]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int j = yPos-1; j >= 0; j--){
            if(first == true && board[xPos][j] == NAN){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN){
                if(first == false){
                    if(board[xPos][j] < 16){
                        path[xPos][j]->show();
                        break;
                    }
                }
                first = false;
            }
        }

        first = true;
        for(int j = yPos+1; j < 10; j++){
            if(first == true && board[xPos][j] == NAN){
                path[xPos][j]->show();
            }
            if(board[xPos][j] != NAN){
                if(first == false){
                    if(board[xPos][j] < 16){
                        path[xPos][j]->show();
                        break;
                    }
                }
                first = false;
            }
        }
    }

    // black Soldier
    if(clickedChess == BLACK_SOLDIER_1 || clickedChess == BLACK_SOLDIER_2 || clickedChess == BLACK_SOLDIER_3 || clickedChess == BLACK_SOLDIER_4 || clickedChess == BLACK_SOLDIER_5){
        if(yPos <= 4){
            if(board[xPos][yPos+1] == NAN || board[xPos][yPos+1] >= 16)
                path[xPos][yPos+1]->show();
        }
        else{
            // forward
            if(yPos <= 8 && (board[xPos][yPos+1] == NAN || board[xPos][yPos+1] >= 16))
                path[xPos][yPos+1]->show();

            // left
            if(xPos >= 1 && (board[xPos-1][yPos] == NAN || board[xPos-1][yPos] >= 16))
                path[xPos-1][yPos]->show();

            // right
            if(xPos <= 7 && (board[xPos+1][yPos] == NAN || board[xPos+1][yPos] >= 16))
                path[xPos+1][yPos]->show();
        }
    }

    // red Soldier
    if(clickedChess == RED_SOLDIER_1 || clickedChess == RED_SOLDIER_2 || clickedChess == RED_SOLDIER_3 || clickedChess == RED_SOLDIER_4 || clickedChess == RED_SOLDIER_5){
        if(yPos >= 5){
            if(board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();
        }
        else{
            // forward
            if(yPos >= 1 && board[xPos][yPos-1] < 16)
                path[xPos][yPos-1]->show();

            // left
            if(xPos >= 1 && board[xPos-1][yPos] < 16)
                path[xPos-1][yPos]->show();

            // right
            if(xPos <= 7 && board[xPos+1][yPos] < 16)
                path[xPos+1][yPos]->show();
        }
    }
    }

    else if (editMode == true) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 10; j++){
                if(board[i][j] == NAN)
                    path[i][j]->show();
            }
        }
    }
}

void MainWindow::hidePath(){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 10; j++)
            path[i][j]->hide();
}

void MainWindow::moveChess(int x, int y){
    // update dead chess
    if(board[x][y] != NAN){
        chessPiece[board[x][y]]->hide();
        xGrid[board[x][y]] = NAN;
        yGrid[board[x][y]] = NAN;
        status[board[x][y]] = DEAD;
    }

    // update board
    board[x][y] = clickedChess;
    board[xGrid[clickedChess]][yGrid[clickedChess]] = NAN;

    // update clickedChess
    chessPiece[clickedChess]->setPos(X[x], Y[y]);
    xGrid[clickedChess] = x;
    yGrid[clickedChess] = y;
}
