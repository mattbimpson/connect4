#include<iostream>
#include<vector>
#include "board.h"
#include "moves.h"

using namespace std;
using namespace Connect4;

class Moves
{
    vector<vector<char>> _columns = {
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ' }
    };

    public: vector<vector<char>> getColumns()
    {
        return _columns;
    }

    public: bool placeToken(int col, bool isPlayer)
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

    private: bool checkForLine(bool isPlayer, int startX, int startY)
    {
        Board _board;
        char mark = getMark(isPlayer);

        int matching = 0;
        int startofLine = startY - 4;
        int endOfLine = startY + 4;
        // check vertical
        for (int rowIndex = startofLine; rowIndex < endOfLine; rowIndex++)
        {
            if (_board.isOutOfBounds(startX, rowIndex)) continue;
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
            if (_board.isOutOfBounds(colIndex, startY)) continue;
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
            if (_board.isOutOfBounds(col, row)) continue;
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
            if (_board.isOutOfBounds(col, row)) continue;
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

    private: char getMark(bool isPlayer)
    {
        return isPlayer ? 'X' : 'O';
    }

    private: bool isOccupied(char text)
    {
        return text != ' ';
    }
};