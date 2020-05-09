#include<iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "moves.h"
#include "board.h"
#include "cpu.h"
using namespace std;
using namespace Connect4;

Moves   _moves;
Board   _board;
int     _turnCount = 0;
void    sleep();
void    start();
void    drawBoard();

int main()
{
    start();
    getchar();
    return 0;
}

void start()
{
    int playStyle = ((double) rand() / (RAND_MAX)) + 1;
    Cpu cpu = Cpu(playStyle);
    _board.clearBoard();
    drawBoard();
    cout << "Game starts!" << endl;
    cout << endl;

    bool gameOver = false;
    bool isPlayerTurn = true;
    while(!gameOver)
    {
        int column;
        isPlayerTurn = (_turnCount % 2 == 0);
        
        if (isPlayerTurn)
        {
            cout << "Choose a column #1 - 7:" << endl;

            bool validInput;
            validInput = false;
            while(!validInput)
            {
                validInput = true;
                cin >> column;
                validInput = (column > 0 && column <= 7);
                cin.clear();
                cin.ignore();
            };
        } else
        {
            cout << "CPU takes their turn..." << endl;
            sleep();
            column = cpu.chooseColumn(_moves) + 1;
        }
        
        gameOver = _moves.placeToken(column, isPlayerTurn);
        _board.clearBoard();
        drawBoard();

        ++_turnCount;
    }

    cout << isPlayerTurn ? "You won!" : "CPU wins :(";
}

void sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void drawBoard()
{
    vector<vector<char>> columns = _moves.getColumns();
    _board.drawBoard(columns);
}