#include "knightstour.h"


KnightsTour::KnightsTour()
{
    rowSize = 8;
    colSize = 8;
    chessBoard = NULL;
    chessName = "";

}


KnightsTour::~KnightsTour()
{
    chessBoard = NULL;
    stack.clear();

}


void KnightsTour::initializeBoard()
{

    //create a size row size board
    chessBoard = new int*[rowSize];

    for (int i = 0; i < rowSize; i++)
        chessBoard[i] = new int[colSize];

    //fill table with 0

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            chessBoard[i][j] = 0;
        }
    }

}

void KnightsTour::printBoard()
{
    stack.printReverse();

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            std::cout<< std::setw(3) << chessBoard[i][j] << " ";
        }

        std::cout<< std::endl;
    }

    std::cout<< std::endl;


}

bool KnightsTour::isValid(int row, int col)
{
    //spot is available if it equals to 0
    if(row >= 0 && row < rowSize && col >= 0 && col < colSize && chessBoard[row][col] == 0)
        return true;
    else
        return false;
}


int KnightsTour::convertChessNametoRow(std::string position)
{
    int chessRow[8] = {1,2,3,4,5,6,7,8};

    int row = 0;

    if (position.length() == 3)
    {
        for(int i = 0; i < rowSize; i++)
        {
            // minus '0' to convert char to int, 6 minus the result to get the index
            if((position[2] - '0') == chessRow[i])
                row = 7 - i;
        }
    }

    if (position.length() == 2)
    {
        for(int i = 0; i < rowSize; i++)
        {
            if(position[1] - '0' == chessRow[i])
                row = 7 - i;
        }
    }


    return row;

}


int KnightsTour::convertChessNametoCol(std::string position)
{
    int col = 0;
    std::string colName;
    colName = "";

    std::string chessCol[8]= {"QR", "QK", "QB", "Q", "K", "KB", "KK", "KR"};

    if (position.length() == 3)
    {
        colName += position[0];
        colName += position[1];

        for(int j = 0; j < colSize; j++)
        {
            if(colName == chessCol[j])
                col = j;
        }
    }

    if (position.length() == 2)
    {
        colName += position[0];

        for(int j = 0; j < colSize; j++)
        {
            if(colName == chessCol[j])
                col = j;
        }
    }

    return col;
}


void KnightsTour::convertRowColtoChessName(int row, int col)
{
    chessName = "";
    if (col == 0)
        chessName += "QR";
    else if (col == 1)
        chessName += "QK";
    else if (col == 2)
        chessName += "QB";
    else if (col == 3)
        chessName += "Q";
    else if (col == 4)
        chessName += "K";
    else if (col == 5)
        chessName += "KB";
    else if (col == 6)
        chessName += "KK";
    else // (col == 7)
        chessName += "KR";
    chessName += std::to_string(8 - row);

}


void KnightsTour::solve(int row, int col, int currentNum)
{
    int maxPossibleMoves = 8;
    int coorX[] = {-2,-1,1,2,2,1,-1,-2};
    int coorY[] = {1,2,2,1,-1,-2,-2,-1};

    int count = 0;
    int leastMoves = 8;
    int leastMovesIndex = 0;
    int newRow = row;
    int newCol = col;

    chessBoard[row][col] = currentNum;
    pushToStack(row, col);

    if (currentNum == rowSize*colSize)
    {
        printBoard();
        if(isClosedTour(row, col))
            std::cout<< "The Solution is a Closed Tour" << std::endl;
        else
            std::cout<< "The Solution is a Open Tour" << std::endl;
        return;
    }

    else
    {
        for(int k = 0; k < maxPossibleMoves; k++)
        {
              newRow += coorX[k];
              newCol += coorY[k];
             if(isValid(newRow, newCol))
             {

                 count = nextPossibleMoves(newRow, newCol);
                 if(count <= leastMoves)
                 {
                     leastMoves = count;
                     leastMovesIndex = k;
                 }
              }
             newRow = row;
             newCol = col;

        }

        newRow += coorX[leastMovesIndex];
        newCol += coorY[leastMovesIndex];
        solve(newRow, newCol, currentNum+1);
        }

//    chessBoard[row][col] = 0;
//    stack.pop();
}

int KnightsTour::nextPossibleMoves(int row, int Y)
{

    int count = 0;
    int maxPossibleMoves = 8;
    int coorX[] = {-2,-1,1,2,2,1,-1,-2};
    int coorY[] = {1,2,2,1,-1,-2,-2,-1};


    for (int i = 0; i < maxPossibleMoves; ++i)
    {
        if (isValid(row+coorX[i], Y+coorY[i]))
            count++;
    }

    return count;
}



void KnightsTour::pushToStack(int row,int col)
{
    convertRowColtoChessName(row, col);
    stack.push(chessName);
}

bool KnightsTour::isClosedTour(int row, int col)
{
    int maxPossibleMoves = 8;
    int coorX[] = {-2,-1,1,2,2,1,-1,-2};
    int coorY[] = {1,2,2,1,-1,-2,-2,-1};

    for (int i = 0; i < maxPossibleMoves; ++i)
    {
            if (row+coorX[i] >= 0 && row+coorX[i] < rowSize
                    && col+coorY[i] >= 0 && col+coorY[i]< colSize
                    && chessBoard[row+coorX[i]][col+coorY[i]] == 1)
                return true;
    }

    return false;
}

void KnightsTour::startGame(std::string startPos)
{
    int currentNum = 1;
    int row;
    int col;
    row = convertChessNametoRow(startPos);
    col = convertChessNametoCol(startPos);

    initializeBoard();

    solve(row, col, currentNum);
}

void KnightsTour::clear()
{
    nukem();
}

void KnightsTour::nukem()
{
    initializeBoard();
    stack.clear();
}

bool KnightsTour::validateInput(std::string position)
{
    bool validRow = false;
    bool validCol = false;
    std::string name = "";
    int row[8] = {1,2,3,4,5,6,7,8};
    std::string col[8]= {"QR", "QK", "QB", "Q", "K", "KB", "KK", "KR"};

    if (position.length() == 3)
    {
        name += position[0];
        name += position[1];

        for(int i = 0; i < 8; i++)
        {
            std::cout<< position[2] - '0' << std::endl;
            if (position[2] - '0' == row[i] )
                validRow = true;

            if (name == col[i])
                validCol = true;
        }
    }

    else
    {
        name += position[0];
        for(int i = 0; i < 8; i++)
        {
            if (position[1] - '0' == row[i])
                validRow = true;
            if (name == col[i])
                validCol = true;
        }

    }

   if (validRow == true && validCol == true)
       return true;
   else
       return false;

}



