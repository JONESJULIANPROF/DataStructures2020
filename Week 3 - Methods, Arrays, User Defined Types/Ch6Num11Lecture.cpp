// Ch6Num11Lecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14
using namespace std;
//protetype
double calcDistance(double centerX, double centerY, double pointX, double pointY);
double calcCircumference(double radius);
double calcArea(double radius);

int main()
{
    double centerX =1, pointX=3, centerY=5, pointY=15;
    double radius, circumference, area;

    radius = calcDistance(centerX, centerY, pointX, pointY);
    cout << "Radius is " << radius << endl;
    circumference = calcCircumference(radius);
    area = calcArea(radius);

    cout << "Circumference is " << circumference << endl;
    cout << "Area is " << area << endl;
}

double calcDistance(double centerX, double centerY, double pointX, double pointY) {
    double dist = 0;
    //do the math
    dist = sqrt(pow(centerX - pointX, 2) + pow(centerY - pointY, 2));
    return dist;
}

double calcCircumference(double radius)
{
    return 6.28 * radius;   //2 * 3.14
    //M_PI
}

double calcArea(double radius)
{
    return 3.14 * radius * radius;
}

