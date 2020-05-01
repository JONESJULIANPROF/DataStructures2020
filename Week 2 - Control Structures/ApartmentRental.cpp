// Lecture1ApartmentRental.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#define increase 40
using namespace std;

int main()
{
    int rent = 600, units = 50;
    const int maintenance = 27;
    int prevProfit = 0, newProfit = 1;
    //prevProfit = (rent - maintenance)* units;
    do {
        prevProfit = newProfit; //hold onto the last profit;
        rent += increase;
        units--;
        newProfit = (rent - maintenance) * units;
        cout << units << " prev " << prevProfit << " new " << newProfit << endl;
    } while (prevProfit < newProfit);
    //undo the last math
    rent -= 40;
    units++;
    newProfit = (rent - maintenance) * units;

    cout << "Units " << units << endl;
    cout << "Rent  " << rent << endl;
    cout << "Profit " << newProfit << endl;


}
