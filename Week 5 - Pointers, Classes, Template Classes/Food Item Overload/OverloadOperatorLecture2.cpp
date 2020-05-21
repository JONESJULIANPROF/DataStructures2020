// OverloadOperatorLecture2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FoodItem.h"
#include <string>
#include <iomanip>
#include "Candy.h"
using namespace std;

int main()
{
    FoodItem cookie("Oreo", 150, 2);
    FoodItem milk("Milk Jug", 200, 3);
    FoodItem snack;
    FoodItem pizza;

    FoodItem egg("Egg", 90, 1);
    FoodItem candy("Candy", 90, 2);

    Candy mm("M and M", 120, 3, 100, true);

    cout << mm.to_string();
    cout << mm << endl;

    egg++;
    cout << "After ++ " << egg << endl;

    //cin >> pizza;

    snack = cookie * 4 + milk;
    //snack = cookie.multiple(4);
    //snack += milk.getCalories();;
    cout << snack << endl;
   
    if (cookie > milk) {
        cout << cookie << " is bigger " << endl;
    }
    else {
        cout << milk << " is bigger " << endl;
    }
    
    
    
    //cout << snack << endl;

   /* double totalCost = cookie.getCost() + milk.getCost();
    int totalCalories = cookie.getCalories() + milk.getCalories();
    string newName = cookie.getName() + ", " + milk.getName();

    cout << newName << " has " << totalCalories << endl;
    */



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
