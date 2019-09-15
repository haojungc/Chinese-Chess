#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set scene size to fit graphicsView
    this->scene = new QGraphicsScene(-10, -10, ui->graphicsView->width() - 2 - 10, ui->graphicsView->height() - 2 - 10);
    // set graphicsview to show scene
    ui->graphicsView->setScene(this->scene);

    // set brush color & pen color
    redBrush = new QBrush(Qt::red);
    redPen.setColor(Qt::red);
    whiteBrush = new QBrush(QColor(255, 255, 255, 200));
    whitePen.setColor(QColor(255, 255, 255, 200));

    // add label
    winnerLabel = new QLabel(this);
    winnerLabel->hide();
    playerLabel = new QLabel(this);
    player1_label = new QLabel(this);
    player2_label = new QLabel(this);

    player1_label->setGeometry(740, 40, 135, 60);
    player2_label->setGeometry(905, 40, 135, 60);

    player1_label->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    player2_label->setFrameStyle(QFrame::NoFrame);

    // add LCD timer
    timer = new QTimer(this);
    LCDTimer = new QLCDNumber(this);
    LCDTimer->setGeometry(850, 130, 150, 40);
    LCDTimer->setDigitCount(5);

    // setup
    loadImage();
    initialize();
    showPlayer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkWin(){
    if(status[RED_KING] == DEAD)
        winner = 2;
    if(status[BLACK_KING] == DEAD)
        winner = 1;

    // king face to king
    if(xGrid[BLACK_KING] == xGrid[RED_KING]){
        for(int i = yGrid[BLACK_KING] + 1; i < yGrid[RED_KING]; i++){
            if(board[xGrid[BLACK_KING]][i] != NAN)
                break;
            else if(i == yGrid[RED_KING] - 1)
                winner = player;
        }
    }

    if(winner){
        gameover = true;
        showEndGameBackground();
        showWinner();
    }
}

void MainWindow::showPlayer(){
    playerLabel->setGeometry(750, 200, 300, 100);

    // set font
    font = winnerLabel->font();
    font.setPointSize(30);
    font.setBold(true);

    if(editMode == true){
        playerLabel->setText(tr("You're in edit mode"));
        font.setPointSize(20);
    }
    else if(player == 1){
        playerLabel->setText(tr("Player 1's turn"));
    }
    else if(player == 2){
        playerLabel->setText(tr("Player 2's turn"));
    }

    playerLabel->setFont(font);
    playerLabel->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_editButton_clicked()
{
    if(editMode == false && rematch == false && gameover == false){
        editMode = true;
        initialize();
        showPlayer();
        ui->editButton->setText(tr("Quit Edit Mode"));
    }
    else if(editMode == true){
        editMode = false;
        player = 1;
        showPlayer();
        ui->editButton->setText(tr("Edit Mode"));
    }
}

void MainWindow::on_surrenderButton_clicked()
{
    if(rematch == false && gameover == false){
        rematch = true;
        if(player == 1)
            winner = 2;
        else if(player == 2)
            winner = 1;
        showEndGameBackground();
        showWinner();
        gameover = true;
        ui->surrenderButton->setText(tr("Rematch"));
    }
    else if(rematch == true){
        rematch = false;
        ui->surrenderButton->setText(tr("Surrender"));
        initialize();
        showPlayer();
    }
}
