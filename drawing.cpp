#include<iostream>
#include<vector>
using namespace std;

class Drawing
{
    public: void drawBoard(vector<vector<char>> columns)
    {
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

    public: void clearBoard()
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
};