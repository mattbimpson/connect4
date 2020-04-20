#include<iostream>
#include <chrono>
#include <thread>
using namespace std;

char columns[7][6] = {
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ' }
};

int turnCount = 0;

void drawBoard();
bool placeToken(int col, bool isPlayer);
void sleep();
bool checkForLine(bool isPlayer, int startX, int startY);

int main()
{
    drawBoard();
    cout << "Game starts!" << endl;
    cout << endl;

    bool gameOver = false;
    do
    {
        bool isPlayerTurn = (turnCount % 2 == 0);
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
        
        bool win = placeToken(column, isPlayerTurn);

        if(win)
        {
            cout << isPlayerTurn ? "You won!" : "CPU wins :(";
            cin.get();
            gameOver = true;
        }

        drawBoard();

        ++turnCount;
    } while (!gameOver);
    
    return 0;
}

char getMark(bool isPlayer)
{
    return isPlayer ? 'X' : 'O';
}

void sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

bool isOccupied(char text)
{
    return text != ' ';
}

bool placeToken(int col, bool isPlayer)
{
    int rowIndex = 0;
    --col;
    for(char &text : columns[col])
    {
        if (!isOccupied(text))
        {
            text = getMark(isPlayer);
            return checkForLine(isPlayer, col, rowIndex);
        }

        ++rowIndex;
    }

    return false;
}

bool checkForLine(bool isPlayer, int startX, int startY)
{
    char mark = getMark(isPlayer);

    int matching = 0;
    // check vertical
    for (int rowIndex = (startY - 4); rowIndex < (startY + 4); rowIndex++)
    {
        if (columns[startX][rowIndex] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else
        {
            matching = 0;
        }
    }

    matching = 0;
    // check horizontal
    for (int colIndex = (startX - 4); colIndex < (startX + 4); colIndex++)
    {
        if (columns[startX][startY] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        } else
        {
            matching = 0;
        }
    }

    // check diagonal right up

    // check diagonal right down

    return false;
}


void drawBoard()
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