// SwitchExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "C++ Switch examples" << endl;
    int choice = 5;
 /*   if (choice == 1) {

    }
    else if (choice == 2) {

    }*/
    //can switch on int, char, enum
    //CANNOT switch on string, double
    switch (choice) {
    case 1:
        //do some code
        break;
    case 2:
        //do some code
        break;
    case 3:
        //do some code
        break;
        //etc
    default:
        //do some code
        break;
    }

    for (int x = 0; x < 10; x++) {
     /*  switch (x % 2) {
        case 1:
            cout << x << " is odd" << endl;
            break;
        case 0:
            cout << x << " is even" << endl;
            break;
        default:
            cout << x << " is not a real number\n";
        }*/
        
        //ternary operator ? 
        //test ? true : false;

        x % 2 == 0 ? cout << x << " is even\n" : cout << x << " is odd\n";

    }
}

