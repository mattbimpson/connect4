#ifndef MOVES_H
#define MOVES_H

#include<vector>

namespace Connect4
{
    class Moves
    {
        public: std::vector<std::vector<char>> getColumns();

        public: bool placeToken(int col, bool isPlayer);

        public: bool isOccupied(char text);

        private: bool checkForLine(bool isPlayer, int startX, int startY);

        private: char getMark(bool isPlayer);

        private: enum Direction
        {
            Vertical,
            Horizontal,
            DiagonalLeft,
            DiagonalRight
        };

        private: void showLine(int endX, int endY, int direction);
    };
}

#endif
