#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawChessBoard();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawChessBoard()

{
    for(size_t i = 0; i < 8; ++i)
      for(size_t j = 0; j < 8; ++j)
      {
          QLabel *newLabel = new QLabel;
          newLabel->setFixedHeight(65);
          newLabel->setFixedWidth(65);

          if((i+j)%2)
          {
              newLabel->setText("");
              newLabel->setStyleSheet("QLabel { background-color : gray}");
          }
          else
          {
              newLabel->setText("");
              newLabel->setStyleSheet("QLabel { background-color : white}");

          }
          newLabel->show();
          ui->chessBoard->addWidget(newLabel,i,j);
      }

}


void MainWindow::on_pushButton_clicked()
{
    drawChessBoard();

    tour.startGame(ui->lineEdit->text().toStdString());
    on_pushButton_2_clicked();

}

void MainWindow::on_pushButton_2_clicked()
{
    std::string moves = "";

    for(int i = 63; i >= 0; i-- )
    {
        movesArray[i] = tour.stack.peek();
        tour.stack.pop();

    }

    for(int i = 0; i < 64; i++)
    {
        moves +=movesArray[i];
        moves += "\n";
    }

    ui->textBrowser->setText(QString::fromStdString(moves));

}

void MainWindow::on_pushButton_3_clicked()
{
    QPixmap tempKnight("/Users/HangTran/Desktop/CS8 Programs/Test 1/Knights Tour Animation/knight.png");
    QPixmap knight= tempKnight.scaled(QSize(60,60),  Qt::KeepAspectRatio);


    int row;
    int col;
    int number = 1;
    QLabel *pic = new QLabel;

    for(int i = 0; i < 64; i++)
    {
        std::string currentNum = "";
        currentNum = std::to_string(number);

        QLabel *num = new QLabel;
        num->setAlignment(Qt::AlignCenter);

        num->setText(QString::fromStdString(currentNum));

        row = tour.convertChessNametoRow(movesArray[i]);
        col = tour.convertChessNametoCol(movesArray[i]);

        pic->setPixmap(knight);

        QApplication::processEvents();
        QThread::msleep(100); // 1 second

        ui->chessBoard->addWidget(pic,row,col);
        ui->chessBoard->addWidget(num,row,col);

        number++;

       QApplication::processEvents();
       QThread::msleep(1); // 1 second
    }


}
