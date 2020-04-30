// Lecture 1 Ch3num12 Population Growth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int popA = 5000;
    int popB = 8000;
    double growthA = .04;
    double growthB = .02;
    int count = 0;
    //test before loop - 0 to infinite repetitions
    while (popA < popB) {
        popA *= (1 + growthA);
        popB *= (1 + growthB);
        count++;
        cout << popA << " " << popB << " " << count << endl;
    }
    
    cout << "Town A will exceed Town B in " << count << " years\n";
    cout << "Town A pop = " << popA << endl;
    cout << "Town B pop = " << popB << endl;

    
}

