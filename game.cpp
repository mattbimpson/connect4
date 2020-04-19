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
void placeToken(int col, bool isPlayer);
void sleep();
bool hasMadeARow(bool isPlayer);

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
        
        placeToken(column, isPlayerTurn);

        if(hasMadeARow(isPlayerTurn))
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

void placeToken(int col, bool isPlayer)
{
    --col;
    for(char &text : columns[col])
    {
        if (!isOccupied(text))
        {
            text = getMark(isPlayer);
            return;
        }
    }
}

bool checkDiagonalRight(char mark, int startX, int startY, bool up)
{
    int matching = 0;
    int rowIndex = startY;
    for (int colIndex = startX; colIndex < 7; colIndex++)
    {
        if (columns[colIndex][rowIndex] == mark)
        {
            ++matching;
            if (matching == 4) return true;
        }

        if (up)
            ++rowIndex;
        else
            --rowIndex;
    }

    return false;
}

bool checkHorizontal(char mark)
{
    int matching = 0;
    for (int rowIndex = 0; rowIndex < 6; rowIndex++)
    {
        for (int colIndex = 0; colIndex < 7; colIndex++)
        {
            if (columns[colIndex][rowIndex] == mark)
            {
                ++matching;
                if (matching == 4) return true;
            } else
            {
                matching = 0;
            }
        }
    }

    return false;
}

bool checkVertical(char mark)
{
    int matching = 0;
    for (int colIndex = 0; colIndex < 7; colIndex++)
    {
        for (int rowIndex = 0; rowIndex < 6; rowIndex++)
        {
            if (columns[colIndex][rowIndex] == mark)
            {
                ++matching;
                if (matching == 4) return true;
            } else
            {
                matching = 0;
            }
        }
    }

    return false;
}

// Todo: very inefficient with so many loops,
// figure out how to improve this
bool hasMadeARow(bool isPlayer)
{
    char mark = getMark(isPlayer);

    // Horizontal
    if (checkHorizontal(mark)) return true;

    // Vertical
    if (checkVertical(mark)) return true;

    // Check the diagonal up-right lines,
    // we can only start these at position 0, 2.
    if (checkDiagonalRight(mark, 0, 2, true)) return true;
    if (checkDiagonalRight(mark, 0, 1, true)) return true;
    if (checkDiagonalRight(mark, 0, 0, true)) return true;
    if (checkDiagonalRight(mark, 1, 1, true)) return true;
    if (checkDiagonalRight(mark, 1, 2, true)) return true;
    if (checkDiagonalRight(mark, 1, 3, true)) return true;
    // Check the diagonal down-right lines
    // we can only start these at position 0, 3.
    if (checkDiagonalRight(mark, 0, 3, false)) return true;
    if (checkDiagonalRight(mark, 0, 4, false)) return true;
    if (checkDiagonalRight(mark, 0, 5, false)) return true;
    if (checkDiagonalRight(mark, 1, 5, false)) return true;
    if (checkDiagonalRight(mark, 2, 5, false)) return true;
    if (checkDiagonalRight(mark, 3, 5, false)) return true;

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