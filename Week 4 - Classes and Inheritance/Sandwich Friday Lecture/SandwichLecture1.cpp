// SandwichLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sandwich.h"
using namespace std;

int main()
{
    Sandwich sammie;//calls default constructor
    //Sandwich sammie();
    sammie.setBread("rye");
    sammie.setCheese("swiss");
    sammie.setSize("large");
    //sammie.setMeat(0);//ham
    sammie.prebuiltSammie(1, "small");

    cout << sammie.getMeatList() << endl;
}

