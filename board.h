#include<vector>

namespace Connect4
{
    class Board
    {
        public: void drawBoard(std::vector<std::vector<char>> columns);

        public: void clearBoard();

        public: bool isOutOfBounds(int x, int y);
    };
}