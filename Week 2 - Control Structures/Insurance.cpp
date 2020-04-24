// Lecture1Insurance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Calculate monthly life insurance costs based on conditions

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int age;
    double perHundred;      //per hundred thousand
    double totalMonthly;    //monthly you spend
    int insuranceDesired;   
    string name;
    char smoke;
    char overweight;
    
    cout << "Enter your name ";
    getline(cin, name);
            //input, variable, opt delimiter

    cout << "how old are you " << name << "? ";
    cin >> age;

    cout << "Do you smoke " << name << " (Y/N)? ";
    cin >> smoke;

    cout << "Are you overweight " << name << " (Y/N)? ";
    cin >> overweight;

    //force to uppercase
    smoke = toupper(smoke);
    overweight = toupper(overweight);

    //echo the input
    cout << name << " is " << age << " years smoke " << smoke << " overweight "
        << overweight << endl;
    /*
    10 to 20	6.54
    20 to 30	7.77
    30 to 40	9.65
    40 to 50	10.21
    50 to 60	12.45
    60 to 100	14.45
    Otherwise	-1 (error condition)

    */
    //calculate the perHundred based on age
    if (age >= 10 && age < 20) {
        perHundred = 6.54;
    }
    else if (age >= 20 && age < 30) {
        perHundred = 7.77;
    }
    else if (age >= 30 && age < 40) {
        perHundred = 9.65;
    }
    else if (age >= 40 && age < 50) {
        perHundred = 10.21;
    }
    else if (age >= 50 && age < 60) {
        perHundred = 12.45;
    }
    else if (age >= 60 && age < 100) {
        perHundred = 14.45;
    }
    else {
        perHundred = -1;
        //else should be error condition
        //avoid using else for valid data or response
    }//end of if age ladder
    //if else if ladder
    //bunch of possibilibites of which ONE can be true

    if (perHundred < 0) {
        //error condition I set
        cout << "We cannot insure you, your age is outside of our range of 10-100" << endl;
        return -1;
    }//end of error if

    cout << "Before modifications, perHundred is " << perHundred << endl;

    //standalone if statements for tests that are exclusive 
    //each possibility could happen

    if (smoke == 'Y') {
        perHundred += .02 * (int)(100 - age);
    }//end if smoke

    if (overweight == 'N') {
        perHundred *= .9;//10 percent discount;
    }//end if overweight

    cout << "After modifications, perHundred is " << perHundred << endl;

    cout << "How much insurance do you want? ";
    cin >> insuranceDesired;

    totalMonthly = perHundred * (insuranceDesired / 100000.0);
                                //forces the math to upconvert to double

    cout << name << " for " << insuranceDesired << " you will spend "
        << totalMonthly << " per month" << endl;

}

