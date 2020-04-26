#include<vector>
#include <stdlib.h>
#include "cpu.h"
#include "board.h"
#include "moves.h"
using namespace std;
using namespace Connect4;

class Cpu
{
    private: Board _board;
    private: Moves _moves;
    private: int _style = Defensive;
    private: vector<vector<char>> _columns;
    private: char _human = 'X';
    private: char _cpu = 'O';

    public: Cpu()
    {
        _style = rand() % 2;
    };

    private: enum PlayStyle
    {
        Defensive,
        Offensive
    };

    public: int chooseColumn()
    {
        _columns = _moves.getColumns();

        if (_style == Defensive)
        {
            return blockLongest();
        }

        return attemptLine();
    }

    private: int blockLongest()
    {
        for (int x = 0; x < 7; x++)
        {
            for (int y = 5; y >= 0; y--)
            {
                if (_board.isOutOfBounds(x, y)) continue;
                if (_columns[x][y] == _human)
                {
                    return x;
                }
            }
        }

        return 0;
    }

    private: int attemptLine()
    {
        return 0;
    }
};