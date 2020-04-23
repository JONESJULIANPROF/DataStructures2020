// Lecturech3Num9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14
using namespace std;

int main()
{
    double radius = 5, height = 10, cubeWidth;
    double volume;
    //cout and cin to get values
    volume = PI * radius * radius * height;
                //pow(radius, 2)
                //radius^2
    cubeWidth = pow(volume, 1/3.0);

    cout << setprecision(2) << fixed;
    //setfill('.')
    cout << left << setw(17) << "Cylinder " << setw(7) << right << radius << endl;
    cout << left << setw(17) << "Cylinder height " << setw(7) << right << height << endl;
    cout << left << setw(17) << "Volume is " << setw(7) << right << volume << endl;
    cout << left << setw(17) << "Cube width " << setw(7) << right << cubeWidth << endl;
    //negative width is left aligned



}

