// Map Lecture 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include "Food.h"
#include <set>
using namespace std;
map <string, double> gradePoints;
map <string, FoodItem> foodMap;
void calcGrades();
void fillGradeMap();
void mapOfClass();
void useFood();

int main()
{
  //  fillGradeMap();
  //  calcGrades();
    mapOfClass();
    useFood();
}
void useFood()
{
    string foodName;
    multiset<FoodItem, less <FoodItem>> eaten;
    int totalCalories = 0;
    do {
        cout << "Enter food you ate, done to quit ";
        cin >> foodName;

        if (foodMap[foodName].getName() != "No name") {//if food not found, 
            //returns default constructor
            eaten.insert(foodMap[foodName]);//do something with the found food
            totalCalories += foodMap[foodName].getCalories();
        }

    } while (foodName != "done");
    cout << "You ate " << totalCalories << " calories " << endl;
}

void mapOfClass() {
    ifstream fin("foodlist.txt");
    string foodName;
    FoodItem someFood;
    int calories, cost;
    if (fin.fail()) {
        cout << "foodList failed to open\n";
        exit(1);
    }
    while (!fin.eof()) {
        fin >> foodName >> calories >> cost;
        someFood = FoodItem(foodName, calories, cost);
        foodMap[foodName] = someFood;
        //add foodName to a dropdown list or array for future use
    }
    fin.close();
    cout << foodMap.size() << " food records read" << endl;
}
void calcGrades()
{
    double totalScore = 0;
    int count = 0;
    string grade = "";
    do {
        cout << "Enter a letter grade from A-F including +, -  X to exit ";
        cin >> grade;
        //lookup in the map
        //use string as the array index, returns null if not found
        if (gradePoints[grade] != NULL || grade == "F") {
            totalScore += gradePoints[grade];
            count++;
            cout << grade << " is worth " << gradePoints[grade] << " points\n";
        }
        /*
        if(grade == "A+"){
            totalScore += 4.25;
            count ++;}
        if(grade == "A"){
            totalScore += 4;
            count ++;} 
        */
    } while (grade != "X");
    if (count > 0) {
        cout << "GPA = " << totalScore / count;
    }
}

void fillGradeMap()
{
    gradePoints["A+"] = 4.25;
    gradePoints["A"] = 4;
    gradePoints["A-"] = 3.75;
    gradePoints["B+"] = 3.5;
    gradePoints["B"] = 3.0;
    gradePoints["B-"] = 2.75;
    gradePoints["C+"] = 2.5;
    gradePoints["C"] = 2.0;
    gradePoints["C-"] = 1.75;
    gradePoints["D+"] = 1.5;
    gradePoints["D"] = 1.0;
    gradePoints["D-"] = 0.75;
    gradePoints["F"] = 0.0;
    gradePoints["Z"] = 0.0;

}

