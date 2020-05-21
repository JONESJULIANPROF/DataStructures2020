// OverloadOperatorsLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "FoodItem.h"
using namespace std;

int main()
{
    cout << "Yummy food!\n";

    FoodItem cookie("Oreo", 150, 2);
    FoodItem milk("Millk Jug", 200, 3);
    FoodItem egg("Egg", 90, 1);
    FoodItem apple("Apple", 90, 2);

    FoodItem otherFood;
    FoodItem snack;
    int a = 3, b = 7;

    a + b;
    cin >> otherFood;
    snack = cookie * 5 + milk + otherFood;
    cout << snack << endl;

    if (cookie > milk) {
        cout << cookie << " is bigger " << endl;
    }
    else
    {
        cout << milk << " is bigger " << endl;
    }

   // cout << snack.to_string() << endl;


   /* double cost = cookie.getCost() + milk.getCost();
    int calories = cookie.getCalories() + milk.getCalories();
    string eaten = cookie.getName() + " AND " + milk.getName();
    cout << eaten << " cal " << calories << endl;*/
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
