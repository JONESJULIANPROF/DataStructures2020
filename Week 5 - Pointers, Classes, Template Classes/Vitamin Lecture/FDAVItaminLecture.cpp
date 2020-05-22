// TestVitamins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vitamin.h"
#include "FoodItem.h"
using namespace std;
FoodItem dinner[3];
void preLoadArrays() {
    Vitamin myList[3];
    myList[0] = Vitamin("Iron", 10, 15);
    myList[1] = Vitamin("Zinc", 15, 25);
    myList[2] = Vitamin("B12", 100, 200);

    Vitamin myList2[4];
    myList2[0] = Vitamin("Potassium", 10, 15);
    myList2[1] = Vitamin("Radium", 15, 25);
    myList2[2] = Vitamin("Rat Poop", 1, .01);
    myList2[3] = Vitamin("Kryptonite", 1, 3000);

    dinner[0] = FoodItem("Chicken", 300, 3, myList, 3);
    dinner[1] = FoodItem("Potato", 200, 2, myList2, 4);
    dinner[2] = FoodItem("Carrots", 100, 5, myList, 3);
}
int main()
{
    preLoadArrays();
    //for (int x = 0; x < 3; x++) {
    //    cout << "Enter the food item\n";
    //    cin >> dinner[x];
    //    cin.ignore(100, '\n');
    //    //could ask if want vitamins
    //    dinner[x].setVitamins();
    //}

    //menu interface here
    for (int x = 0; x < 3; x++) {
        //output
        cout << dinner[x] << endl;
        cout << "-----------------------------" << endl;
    }


    //FoodItem cookie("Oreo", 150, 3);

    //cookie.setVitamins();
    //cookie.getVitamins();
    //cout << cookie << endl;


  /*  Vitamin iron("Iron", 5, 10);
    cout << iron << endl;

    cout << "To string " << iron.to_string() << endl;*/
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
