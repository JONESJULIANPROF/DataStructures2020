// FractionLecture2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction half(1,2);
    Fraction third(1, 3);
    Fraction answer;

    cout << half << endl;
    cout << third << endl;
   // cin >> answer;
    
    answer = half + third;
    
    cout << answer << endl;
    
}
