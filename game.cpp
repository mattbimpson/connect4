#include<iostream>
using namespace std;

int playerMoves[21];
int cpuMoves[21];
string column1[7] = { " ", " ", " ", " ", " ", " ", " " };
string column2[7] = { " ", " ", " ", " ", " ", " ", " " };
string column3[7] = { " ", " ", " ", " ", " ", " ", " " };
string column4[7] = { " ", " ", " ", " ", " ", " ", " " };
string column5[7] = { " ", " ", " ", " ", " ", " ", " " };
string column6[7] = { " ", " ", " ", " ", " ", " ", " " };
string column7[7] = { " ", " ", " ", " ", " ", " ", " " };
int turnCount = 0;

void drawBoard();
void placeToken(int col, bool isPlayer);

int main()
{
    drawBoard();
    cout << "Game starts!" << endl;
    cout << endl;

    bool gameOver = false;
    do
    {
        cout << "Choose a column #1 - 7:" << endl;
        cout << endl;
        int column = 0;
        cin >> column;
        placeToken(column, true);
        drawBoard();

        if (turnCount == 42) gameOver = true;
    } while (!gameOver);
    
    return 0;
}

bool isOccupied(string text)
{
    return text != " ";
}

void placeToken(int col, bool isPlayer)
{
    switch(col)
    {
        case 1:
            for(string &text : column1)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 2:
            for(string &text : column2)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 3:
            for(string &text : column3)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 4:
            for(string &text : column4)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 5:
            for(string &text : column5)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 6:
            for(string &text : column6)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        case 7:
            for(string &text : column7)
            {
                if (!isOccupied(text))
                {
                    text = isPlayer ? "X" : "O";
                    return;
                }
            }
            break;
        default:
            break;
    }

    ++turnCount;
}

void drawBoard()
{
    system("clear");
    cout << "\nConnect 4\n";
    cout << endl;
    cout << " _________________________________________" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[5] << "  |  " << column2[5] << "  |  " << column3[5] << "  |  " << column4[5] << "  |  " << column5[5] << "  |  " << column6[5] << "  |  " << column7[5] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[4] << "  |  " << column2[4] << "  |  " << column3[4] << "  |  " << column4[4] << "  |  " << column5[4] << "  |  " << column6[4] << "  |  " << column7[4] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[3] << "  |  " << column2[3] << "  |  " << column3[3] << "  |  " << column4[3] << "  |  " << column5[3] << "  |  " << column6[3] << "  |  " << column7[3] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[2] << "  |  " << column2[2] << "  |  " << column3[2] << "  |  " << column4[2] << "  |  " << column5[2] << "  |  " << column6[2] << "  |  " << column7[2] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[1] << "  |  " << column2[1] << "  |  " << column3[1] << "  |  " << column4[1] << "  |  " << column5[1] << "  |  " << column6[1] << "  |  " << column7[1] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  " << column1[0] << "  |  " << column2[0] << "  |  " << column3[0] << "  |  " << column4[0] << "  |  " << column5[0] << "  |  " << column6[0] << "  |  " << column7[0] << "  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << endl;
}