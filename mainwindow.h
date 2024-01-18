#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QGridLayout>
#include <QObject>
#include "knightstour.h"
#include "mystack.h"
#include <string>
#include <QtTest>
#include<iostream>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public :
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void getRow();
    void getCol();
    void getMoves();
    void displayMoves();






private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    void drawChessBoard();
    void knightsMoves();
    int row;
    int col;
    myStack<std::string> list;
    KnightsTour tour;
    std::string movesArray[64];




};

#endif // MAINWINDOW_H
