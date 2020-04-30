// Lecture2Ch4Ex34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ch3 num 34

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double bill=0, pay=0, credit=0, penalty=0;
    cout << "Enter the bill amount " << endl;
    cin >> bill;
    cout << "Enter the payment amount " << endl;
    cin >> pay;

    if (pay >= bill) {//pay off the bill
        credit = bill * .01;
        if (credit > 10) {
            credit = 10;
        }
        //smaller of bill * .01 or 10
        //bill -= credit + pay;
        bill -= credit;
        bill -= pay;
        cout << "You have a credit of " << credit << " Thank you!" << endl;
    }
    else if (pay >= bill / 2) {
        
        bill -= pay;

        penalty = bill * .05;//calculate penalty after payment
        bill += penalty;

        cout << "You were assessed a penalty of " << penalty << endl;
        cout << "Thank you for your payment!" << endl;
    }
    else if (pay >= bill * .2 && pay < bill / 2) {
        bill -= pay;

        penalty = bill * .1;//calculate penalty after payment
        bill += penalty;

        cout << "You were assessed a penalty of " << penalty << endl;
        cout << "Thank you for your payment!" << endl;
    }
    else if (pay >= 0 && pay < bill * .2) {
        bill -= pay;

        penalty = bill * .2;//calculate penalty after payment
        bill += penalty;

        cout << "You were assessed a penalty of " << penalty << endl;
        cout << "Thank you for your payment!" << endl;
    }
    else {
        //bad things
        cout << "The payment is invalid, no penalty or credit\n";
        return 1;
    }


    cout << "Payment of " << pay << endl;
    cout << "Remaining balance = " << bill;
   
}


