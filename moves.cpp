#include<iostream>
#include<vector>
#include "board.h"
#include "moves.h"

using namespace std;
using namespace Connect4;

vector<vector<char>> _columns = {
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' }
};

vector<vector<char>> Moves::getColumns()
{
    return _columns;
}

bool Moves::placeToken(int col, bool isPlayer)
{
    int rowIndex = 0;
    --col;
    for(char &text : _columns[col])
    {
        if (!isOccupied(text))
        {
            text = getMark(isPlayer);
            return checkForLine(isPlayer, col, rowIndex);
        }

        ++rowIndex;
    }

    return false;
}

bool Moves::checkForLine(bool isPlayer, int startX, int startY)
{
    Board board;
    char mark = getMark(isPlayer);

    int matching = 0;
    int startofLine = startY - 4;
    int endOfLine = startY + 4;
    // check vertical
    for (int rowIndex = startofLine; rowIndex < endOfLine; rowIndex++)
    {
        if (board.isOutOfBounds(startX, rowIndex)) continue;
        if (_columns[startX][rowIndex] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else
        {
            matching = 0;
        }
    }

    matching = 0;
    startofLine = startX - 4;
    endOfLine = startX + 4;
    // check horizontal
    for (int colIndex = startofLine; colIndex < endOfLine; colIndex++)
    {
        if (board.isOutOfBounds(colIndex, startY)) continue;
        if (_columns[colIndex][startY] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else
        {
            matching = 0;
        }
    }

    // check diagonal right up
    matching = 0;
    int row = startY - 3;
    for (int col = startX -3; col < startX + 4; col++)
    {
        if (board.isOutOfBounds(col, row)) continue;
        if (_columns[col][row] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else {
            matching = 0;
        }

        ++row;
    }

    // check diagonal right down
    matching = 0;
    row = startY + 3;
    for (int col = startX - 3; col < startX + 4; col++)
    {
        if (board.isOutOfBounds(col, row)) continue;
        if (_columns[col][row] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else {
            matching = 0;
        }

        --row;
    }

    return false;
}

char Moves::getMark(bool isPlayer)
{
    return isPlayer ? 'X' : 'O';
}

bool Moves::isOccupied(char text)
{
    return text != ' ';
}