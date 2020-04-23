// LectureDistanceXY.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>    //<math.h>
#include <iomanip>

using namespace std;
//read and write payroll to a file

int main()
{
    int x1 = 5, x2=10, y1=5, y2=10; //(5,5)   (10,10)
    double distance = 0;

    //cout, cin
    //dist = sqrt(dif^2 + dif^2)
    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

    
    cout << setprecision(2) << fixed;
    cout << "Distance is " << distance << endl;
}

