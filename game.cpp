#include<iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "moves.cpp"
using namespace std;


class Game
{
    public:
        Game() {};

    Moves _moves;
    int turnCount = 0;

    void start()
    {
        clearBoard();
        drawBoard();
        cout << "Game starts!" << endl;
        cout << endl;

        bool gameOver = false;
        bool isPlayerTurn = true;
        while(!gameOver)
        {
            isPlayerTurn = (turnCount % 2 == 0);
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
            clearBoard();
            drawBoard();

            ++turnCount;
        }

        cout << isPlayerTurn ? "You won!" : "CPU wins :(";
    }

    private: void sleep()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    private: void clearBoard()
    {
        try
        {
            // Linux/MacOS
            system("clear");
        }
        catch(const std::exception& e) {}

        try
        {
            // Windows
            system("cls");
        }
        catch(const std::exception& e) {}
    }

    private: void drawBoard()
    {
        vector<vector<char>> columns = _moves.getColumns();
        cout << "\nConnect 4\n";
        cout << endl;
        cout << " _________________________________________" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][5] << "  |  " << columns[1][5] << "  |  " << columns[2][5] << "  |  " << columns[3][5] << "  |  " << columns[4][5] << "  |  " << columns[5][5] << "  |  " << columns[6][5] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][4] << "  |  " << columns[1][4] << "  |  " << columns[2][4] << "  |  " << columns[3][4] << "  |  " << columns[4][4] << "  |  " << columns[5][4] << "  |  " << columns[6][4] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][3] << "  |  " << columns[1][3] << "  |  " << columns[2][3] << "  |  " << columns[3][3] << "  |  " << columns[4][3] << "  |  " << columns[5][3] << "  |  " << columns[6][3] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][2] << "  |  " << columns[1][2] << "  |  " << columns[2][2] << "  |  " << columns[3][2] << "  |  " << columns[4][2] << "  |  " << columns[5][2] << "  |  " << columns[6][2] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][1] << "  |  " << columns[1][1] << "  |  " << columns[2][1] << "  |  " << columns[3][1] << "  |  " << columns[4][1] << "  |  " << columns[5][1] << "  |  " << columns[6][1] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << "|     |     |     |     |     |     |     |" << endl;
        cout << "|  " << columns[0][0] << "  |  " << columns[1][0] << "  |  " << columns[2][0] << "  |  " << columns[3][0] << "  |  " << columns[4][0] << "  |  " << columns[5][0] << "  |  " << columns[6][0] << "  |" << endl;
        cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
        cout << endl;
    }
};

int main()
{
    Game game;
    game.start();
    getchar();
    return 0;
}