#include<vector>
#include<stdlib.h>
#include<iostream>
#include "cpu.h"
#include "board.h"
#include "moves.h"
using namespace std;
using namespace Connect4;


Cpu::Cpu(int playStyle, Moves moves)
{
    _style = playStyle;
    _moves = moves;
};

vector<int> _longestCoordsCpu = { 0, 0 };

int Cpu::chooseColumn(bool firstTurn)
{
    cout << "style: " << _style;
    _columns = _moves.getColumns();

    // if (_style == Defensive)
    // {
    //     return blockLongest(_columns);
    // }

    return attemptLine(firstTurn);
}

int Cpu::blockLongest(vector<vector<char>> columns)
{
    for (int x = 0; x < 7; x++)
    {
        for (int y = 5; y --> 0;)
        {
            if (columns[x][y] == _human)
            {
                return x;
            }
        }
    }

    return 0;
}

int Cpu::attemptLine(bool firstTurn)
{
    if (firstTurn)
    {
        for (int x = 0; x < 7; x++)
        {
            if (!_moves.isOccupied(_columns[x][0]))
            {
                _longestCoordsCpu = { x, 0 };
                return x;
            }
        }
    } else
    {
        // check vertical
        int longestX = _longestCoordsCpu[0];
        int longestY = _longestCoordsCpu[1];
        if (!_moves.isOccupied(_columns[longestX][longestY + 1]))
        {
            _longestCoordsCpu = { longestX, longestY + 1 };
            return longestX;
        }

        // check horizontal
        if (!_moves.isOccupied(_columns[longestX + 1][longestY]))
        {
            _longestCoordsCpu = { longestX + 1, longestY };
            return longestX + 1;
        }

        return longestX + 1;
    }

    return 0;
}
