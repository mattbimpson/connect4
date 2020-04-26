#ifndef MOVES_H
#define MOVES_H

#include<vector>

namespace Connect4
{
    class Moves
    {
        public: std::vector<std::vector<char>> getColumns();

        public: bool placeToken(int col, bool isPlayer);
    };
}

#endif
