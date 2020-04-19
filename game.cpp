#include<iostream>
using namespace std;

void drawBoard();

int main()
{
    drawBoard();
    cout << "Game starts! Choose a column #1 - 7 to continue." << endl;
    return 0;
}

void drawBoard()
{
    system("clear");
    cout << "\nConnect 4\n";
    cout << endl;
    cout << " _________________________________________" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "| 36  | 37  | 38  | 39  | 40  | 41  | 42  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "| 29  | 30  | 31  | 32  | 33  | 34  | 35  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "| 22  | 23  | 24  | 25  | 26  | 27  | 28  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "| 15  | 16  | 17  | 18  | 19  | 20  | 21  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  8  |  9  | 10  | 11  | 12  | 13  | 14  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << "|     |     |     |     |     |     |     |" << endl;
    cout << "|  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|" << endl;
    cout << endl;
}