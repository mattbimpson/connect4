#include<iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "moves.cpp"
#include "drawing.cpp"
using namespace std;


class Game
{
    public:
        Game() {};

    Moves   _moves;
    Drawing _drawing;
    int     _turnCount = 0;

    void start()
    {
        _drawing.clearBoard();
        drawBoard();
        cout << "Game starts!" << endl;
        cout << endl;

        bool gameOver = false;
        bool isPlayerTurn = true;
        while(!gameOver)
        {
            isPlayerTurn = (_turnCount % 2 == 0);
            int column = 0;
            if (isPlayerTurn)
            {
                cout << "Choose a column #1 - 7:" << endl;
                cout << endl;
                cin >> column;
            } else
            {
                cout << "CPU takes their turn..." << endl;
                sleep();
                column = rand() % 7;
            }
            
            gameOver = _moves.placeToken(column, isPlayerTurn);
            _drawing.clearBoard();
            drawBoard();

            ++_turnCount;
        }

        cout << isPlayerTurn ? "You won!" : "CPU wins :(";
    }

    private: void sleep()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    private: void drawBoard()
    {
        vector<vector<char>> columns = _moves.getColumns();
        _drawing.drawBoard(columns);
    }
};

int main()
{
    Game game;
    game.start();
    getchar();
    return 0;
}