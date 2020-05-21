// SimplePointerLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //so pointers = the address of the value you give it

    double payroll = 1234.56;
    double tax = payroll * .07;

    int hours = 40;
    //pointers to hold the location of data
    //datatype * variableName;
    double* payrollPtr, * taxPtr;

    //link the pointer to the variable
    payrollPtr = &payroll;  //pointer type and variable type must match
    //payrollPtr = &hours;  //error cannot assign int to double
    taxPtr = &tax;

    cout << "Payroll address is " << payrollPtr << endl;
    cout << "Tax address is " << taxPtr << endl;

    //dereference the pointer
    //get the value in the location held by pointer
    cout << "Payroll value is " << *payrollPtr << endl;
    double stupidMath = (*payrollPtr) * (*taxPtr);  //dont do this if yiou can avoid it

    //reset a pointer
    payrollPtr = &someOtherVar;//reset before using another variable

    payrollPtr = NULL;  //wipes out a pointer
                        //do before reusing a pointer



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
