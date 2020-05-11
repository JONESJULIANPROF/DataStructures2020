// MagicSquareLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
void fillSquare();
bool isMagicSquare();//return true == magic square

//int square[3][3];
int square[3][3] =
{ {7,2, 6},
{9, 5, 1},
{4, 3, 8} };

int main()
{
    cout << "Enter a magic square" << endl;
    //fillSquare();
    if (isMagicSquare()) {
        cout << "You entered a magic square!" << endl;
    }
    else {
        cout << "You did NOT enter a magic square." << endl;
    }
}


bool isMagicSquare() {
    int rows[3] = { 0,0,0 };
    int cols[3] = { 0,0,0 };
    int diags[2] = { 0,0 };
    int x;
    for (x = 0; x < 3; x++) {
        rows[x] = square[x][0] + square[x][1] + square[x][2];
        cols[x] = square[0][x] + square[1][x] + square[2][x];
      /*  cout << rows[x] << endl;
        cout << cols[x] << endl;*/
    }
    /*
    rows[0] = square[0][0] + square[0][1] + square[0][2]
    rows[1] = square[1][0] + square[1][1] + square[1][2]
    rows[2] = square[2][0] + square[2][1] + square[2][2]
    */
    
    diags[0] = square[0][0] + square[1][1] + square[2][2];
    diags[1] = square[2][0] + square[1][1] + square[0][2];
    /*cout << diags[0] << endl;
    cout << diags[1] << endl;*/
    if (rows[0] != rows[1] || rows[1] != rows[2]) {
        return false;
    }

    if (cols[0] != cols[1] || cols[1] != cols[2]) {
        return false;
    }

    if (cols[0] != rows[1]) {
        return false;
    }

    if (diags[0] != diags[1] || diags[0] != rows[1]) {
        return false;
    }

    return true;
}

void fillSquare() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << "Enter position " << r << " " << c << endl;
            cin >> square[r][c];
        }
    }
}

