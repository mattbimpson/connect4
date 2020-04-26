#ifndef CPU_H
#define CPU_H

#include "moves.h"
#include "board.h"
#include<vector>

namespace Connect4 
{
    class Cpu
    {
        Moves _moves;
        Board _board;

        enum PlayStyle
        {
            Defensive,
            Offensive
        };

        int _style = Defensive;
        std::vector<std::vector<char>> _columns;
        char _human = 'X';
        char _cpu = 'O';

        public: Cpu(Board board, Moves moves);

        public: int chooseColumn();

        public: int blockLongest();

        public: int attemptLine();
    };
}

#endif
