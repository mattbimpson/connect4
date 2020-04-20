#include<iostream>
#include<vector>

using namespace std;

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

    private: bool isOutOfBounds(int x, int y)
    {
        if (x < 0 || x > 6) return true;
        if (y < 0 || y > 5) return true;

        return false;
    }

    private: bool checkForLine(bool isPlayer, int startX, int startY)
    {
        char mark = getMark(isPlayer);

        int matching = 0;
        int startofLine = startY - 4;
        int endOfLine = startY + 4;
        // check vertical
        for (int rowIndex = startofLine; rowIndex < endOfLine; rowIndex++)
        {
            if (isOutOfBounds(startX, rowIndex)) continue;
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
            if (isOutOfBounds(colIndex, startY)) continue;
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
            if (isOutOfBounds(col, row)) continue;
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
            if (isOutOfBounds(col, row)) continue;
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