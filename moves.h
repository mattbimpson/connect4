#ifndef MOVES_H
#define MOVES_H

#include<vector>

namespace Connect4
{
    class Moves
    {
        public: std::vector<std::vector<char>> getColumns();

        public: bool placeToken(int col, bool isPlayer);

        private: bool checkForLine(bool isPlayer, int startX, int startY);

        private: char getMark(bool isPlayer);

        private: bool isOccupied(char text);
    };
}

#endif
