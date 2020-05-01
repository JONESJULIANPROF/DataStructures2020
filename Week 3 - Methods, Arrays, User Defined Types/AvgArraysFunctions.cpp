// LectureAvgArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//prototype less functions
//if the functions will not call each other
//only if they will be called in main
const int SIZE = 5;

void showNumbers(double list[]) {
    for (int x = 0; x < SIZE; x++) {
        cout << x << " : " << list[x] << endl;
    }
}

double arithmeticMean(double list[]) {
    double total = 0;
    double average = 0;

    for (int x = 0; x < SIZE; x++) {
        total += list[x];
    }
    average = total / SIZE;

    return average;
}

double geometricMean(double list[]) {
    double total = 1;//need for product
    double average = 0;
    for (int x = 0; x < SIZE; x++) {
        total *= list[x];
    }
    //SIZE root
    average = pow(total, 1.0/SIZE);
    return average;
}

double harmonicMean(double list[]);

int main()
{
    double values[SIZE] = { 4, 36, 45, 50, 75 };
    double avg;
    showNumbers(values);
    cout << setprecision(2) << fixed;
    cout << "Arithmetic mean " << arithmeticMean(values) << endl;

    cout << "Geometric mean " << geometricMean(values) << endl;
    avg = harmonicMean(values);//need to reuse the result
    cout << "Harmonic mean " << avg << endl;
}

double harmonicMean(double list[]) {
    double total = 0;
    double average = 0;
    for (int x = 0; x < SIZE; x++) {
        total += 1/ list[x];//reciprocal of the list value
    }
    average = SIZE / total;
    return average;
}