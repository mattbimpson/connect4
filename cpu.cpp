#include<vector>
#include<stdlib.h>
#include "cpu.h"
#include "board.h"
#include "moves.h"
using namespace std;
using namespace Connect4;


Cpu::Cpu()
{
    _style = rand() % 1;
};

int Cpu::chooseColumn(Moves moves)
{
    _columns = moves.getColumns();

    if (_style == Defensive)
    {
        return blockLongest(_columns);
    }

    return attemptLine(_columns);
}

int Cpu::blockLongest(vector<vector<char>> columns)
{
    // todo - only blocks longest vertical
    for (int x = 0; x < 7; x++)
    {
        for (int y = 5; y --> 0; )
        {
            if (columns[x][y] == _human)
            {
                return x;
            }
        }
    }

    return 0;
}

int Cpu::attemptLine(vector<vector<char>> columns)
{
    return rand() % 7;
}