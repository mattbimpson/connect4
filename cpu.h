#ifndef CPU_H
#define CPU_H

#include "moves.h"
#include "board.h"
#include<vector>

namespace Connect4 
{
    class Cpu
    {
        private: Moves _moves;
        private: enum PlayStyle
        {
            Defensive,
            Offensive
        };
        private: int _style = Defensive;
        private: std::vector<std::vector<char>> _columns;
        private: char _human = 'X';
        private: char _cpu = 'O';

        public: Cpu(int playStyle, Moves moves);

        public: int chooseColumn(bool firstTurn);

        private: int blockLongest(std::vector<std::vector<char>>);

        private: int attemptLine(bool firstTurn);
    };
}

#endif
