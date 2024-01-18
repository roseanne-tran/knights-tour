#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

#include<iostream>
#include<iomanip>
#include "mystack.h"


class KnightsTour
{
    public:
        KnightsTour();
        ~KnightsTour();
        void initializeBoard();
        void printBoard();
        bool isValid(int row,int col);
        bool isClosedTour(int row, int col);
        void solve(int row, int col, int currentNum);
        void pushToStack(int row, int col);
        int convertChessNametoRow(std::string position);
        int convertChessNametoCol(std::string position);
        void convertRowColtoChessName(int row, int col);
        int nextPossibleMoves(int row, int col);
        void startGame(std::string startPos);
        void clear();
        bool validateInput(std::string position);

        int **chessBoard;
        myStack<std::string> stack;



    private:
        int rowSize;
        int colSize;
        std::string chessName;

        void nukem();


};

#endif // KNIGHTSTOUR_H
