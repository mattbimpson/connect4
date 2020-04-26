#include<vector>

namespace Connect4
{
    class Moves
    {
        public: std::vector<std::vector<char>> getColumns();

        public: bool placeToken(int col, bool isPlayer);
    };
}