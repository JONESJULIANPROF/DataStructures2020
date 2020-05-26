// LinkedListLecture2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "unorderedLinkedList.h"
#include "FoodItem.h"
#include "orderedLinkedList.h"


using namespace std;

int main()
{
    //unorderedLinkedList<string> words;
    orderedLinkedList<string> words;
    words.initializeList();//optional = deletes nodes in an existing list
    words.insertLast("hi");
    words.insertLast("there");
    words.insertLast("class");
    words.insertLast("coding!");
    words.insertFirst("cool");
    words.insertFirst("neato");
    words.insertLast("hi");
    words.deleteSmallest();

    words.print();
    cout << endl;
    /*
    can use any data type
    must overload ==, !=, <, >, <=, >=, <<, >>
    */
    unorderedLinkedList<FoodItem> breakfast;
    breakfast.insertFirst(FoodItem("eggs", 100, 1));
    breakfast.insertFirst(FoodItem("bacon", 300, 5));
    FoodItem toast("Toast", 200, 3);
    breakfast.insertFirst(toast);

    breakfast.deleteSmallest();

    breakfast.print();


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
