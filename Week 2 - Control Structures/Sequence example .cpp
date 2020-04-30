// Lecture2Ch5Num7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ch5 number 7 - algorithm to wlak backwards through a number

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number = 8784205;
    int digit;
    int total = 0;
    int count = 0;
    //stoi == string to integer
    //ctoi == char to integer
    cout << "Number is " << number << endl;
    while (number > 0) {
        digit = number % 10;
        number = number / 10;
        if (count % 2 == 0) {
            //even
            total += digit;
        }
        else if (count % 2 == 1) {
            //odd
            total -= digit;
        }
        count++;

    }
    cout << "total = " << total << endl;
    if (total % 11 == 0) {
        cout << "is divisible by 11";
    }
    else {
        cout << "NOT divisible by 11";
    }
}

