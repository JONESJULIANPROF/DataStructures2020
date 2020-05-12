// FoodClassLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "FoodItem.h"
#include "EnergyDrink.h"

using namespace std;

int main()
{
    FoodItem cookies("Oreo", 100, 3);
    FoodItem milk;
    EnergyDrink monster("Monster", 200, 4.5, 300);
    milk.setName("Moo Juice");
    milk.setCalories(150);
    milk.setCost(1.75);
    //cout << setprecision(2) << fixed;
    cout << cookies.toString() << " and " << milk.toString() << endl;

    cout << cookies.perCalorieCost() << " Per calorie cost for " << cookies.getName() << endl;
    cout << monster.toString() << endl;
}

