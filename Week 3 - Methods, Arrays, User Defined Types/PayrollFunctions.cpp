// Lecture1PayrollFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Create methods

#include <iostream>
#include <iomanip>
using namespace std;
//everything must be declared before you use it

//prototype functions here
//prototype return type, name, parameter list;
void printMyAddress();
void printLine(int length);
double calcGrossPay(double hours, double hourly=10);
//default have to be at the end of the list
//cannot pick and choose whicf to default
int someFunction(int a = 1, int b = 3, int c = 6);
//someFunction()
//someFunction(5);
//someFunction(5, 15);
//someFunction(5, 15, 13);
//invalid call
//someFunction( , 10, );

//double calcGrossPay(double, double);
int main()
{
    printMyAddress();   //function call
    printLine(10);
    printMyAddress();
    printLine(10);

    double hours = 40, hourly = 15.5, grossPay = 0;

    grossPay = calcGrossPay(hours);//default to 10

    cout << setprecision(2) << fixed << endl;
    cout << "You made " << grossPay << endl;

    grossPay = calcGrossPay(hours, hourly);

    cout << setprecision(2) << fixed << endl;
    cout << "You made " << grossPay << endl;


}

//define functions here
                                //hourly is defaulted to 10 in prototype
double calcGrossPay(double hours, double hourly) {
    return hours * hourly;
}

void printMyAddress() {
    cout << "Lee Cottrell" << endl;
    cout << "1434 Justine Street" << endl;
    cout << "Pittsburgh, PA 15204" << endl;
}

void printLine(int length) {
    for (int x = 0; x < length; x++)
    {
        cout << "_";
    }
    cout << endl;
}