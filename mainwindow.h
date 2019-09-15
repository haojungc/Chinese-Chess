#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QFont>
#include <QColor>
#include <QFrame>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>

#define BLACK_JU_1 0
#define BLACK_MA_1 1
#define BLACK_XIANG_1 2
#define BLACK_SHI_1 3
#define BLACK_KING 4
#define BLACK_SHI_2 5
#define BLACK_XIANG_2 6
#define BLACK_MA_2 7
#define BLACK_JU_2 8
#define BLACK_PAO_1 9
#define BLACK_PAO_2 10
#define BLACK_SOLDIER_1 11
#define BLACK_SOLDIER_2 12
#define BLACK_SOLDIER_3 13
#define BLACK_SOLDIER_4 14
#define BLACK_SOLDIER_5 15

#define RED_JU_1 16
#define RED_MA_1 17
#define RED_XIANG_1 18
#define RED_SHI_1 19
#define RED_KING 20
#define RED_SHI_2 21
#define RED_XIANG_2 22
#define RED_MA_2 23
#define RED_JU_2 24
#define RED_PAO_1 25
#define RED_PAO_2 26
#define RED_SOLDIER_1 27
#define RED_SOLDIER_2 28
#define RED_SOLDIER_3 29
#define RED_SOLDIER_4 30
#define RED_SOLDIER_5 31

#define NAN -1
#define ALIVE 1
#define DEAD 0

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadImage();
    void initialize();
    void showPath();
    void showImg();
    void hidePath();
    bool isInRange(int, int);
    void convertPos(int, int);
    void moveChess(int, int);
    void checkWin();
    void showPlayer();
    void showWinner();
    void showEndGameBackground();

private slots:
    void showTime();

    void on_editButton_clicked();

    void on_surrenderButton_clicked();

private:
    Ui::MainWindow *ui;

    // create scene
    QGraphicsScene *scene;
    QGraphicsEllipseItem *path[9][10];
    QGraphicsRectItem *endGameBackground;
    QGraphicsPixmapItem *chessPiece[32];
    QBrush *redBrush, *whiteBrush;
    QPen redPen, whitePen;
    QLabel *winnerLabel, *player1_label, *player2_label, *playerLabel;
    QFont font;
    QTimer *timer;
    QTime time;
    QLCDNumber *LCDTimer;
    QList<QPixmap> pics;
    int picIndex = 0;
    const int chessSize = 60;
    const int X[9] = {36, 110, 188, 267, 342, 421, 499, 573, 647};
    const int Y[10] = {50, 112, 179, 247, 319, 391, 464, 536, 605, 669};
    int xGrid[32];
    int yGrid[32];
    int status[32];
    int xPos;
    int yPos;
    int board[9][10]; // black: 0-15, red: 16-31
    int clickedChess = NAN;
    int player = 1, winner = 0;
    bool gameover = false;
    bool editMode = false;
    bool rematch = false;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
