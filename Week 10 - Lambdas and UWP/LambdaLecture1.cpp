// LambdaLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Food.h"
using namespace std;

vector <int> ray = { 1, 3, 6, -12, -54, 0, 4, -13, 18, 10 };

template <class T>//not required for lambda, just using it here to simplify my life
void printVector(vector<T> v) {
	for_each(v.begin(), v.end(),
		//[] is capture, (T val) parameters
		[](T val) {
			cout << val << endl;
			//function body
		}
	);
}

int main()
{
	fillFoodVector();
	//printVector(ray);
	//cout << endl;
	//printVector(yummy);
	//find_if algorithm that finds values in a structure
	//pass in function that does the finding
	//find first value in ray that is > 4
	//auto p = find_if(ray.begin(), ray.end(), 
	//    [](int i)->int {
	//        return i > 4;
	//    }
	//    );

	//cout << "First larger than 4 " << *p << endl;

	//cout << "Find first food item that costs 10 " << endl;

	//auto f = find_if(yummy.begin(), yummy.end(), [](FoodItem food) {return food.getCost() == 10; });
	//cout << *f << endl;
   /* cout << "Default sort \n";
	sort(yummy.begin(), yummy.end());
	printVector(yummy);
	cout << endl << "Sort by name, descending \n";

	sort(yummy.begin(), yummy.end(), [](FoodItem a, FoodItem b)->bool {
		return a.getName() > b.getName();
		});

	printVector(yummy);*/

	auto square = [](int x)->int {return x * x; };
	cout << square(12) << endl;

	/*sort(yummy.begin(), yummy.end(), [](FoodItem a, FoodItem b)->bool {
		return a.getName() > b.getName();
		}
	);*/

	//Using captures
	//tend to use captures to pass in values from the current program or scope

	//print food that costs more than a variable in main
	//pass in minCost by value
	int minCost = 8;
	for_each(yummy.begin(), yummy.end(),
		[minCost](FoodItem f) {
			if (f.getCost() > minCost) {
				cout << f << endl;
			}
			//minCost = 10000;
		}
	);

	//find most expensive food item
	int maxCost = 0;
	for_each(yummy.begin(), yummy.end(),
		[&maxCost](FoodItem f) {
			if (f.getCost() > maxCost) {
				maxCost = f.getCost();
			}
		}
	);
	cout << "Most expensive price is " << maxCost << endl;

	FoodItem maxFood;
	for_each(yummy.begin(), yummy.end(),
		[&maxFood](FoodItem f) {
			if (f.getCost() > maxFood.getCost()) {
				maxFood = f;
			}
		}
	);
	cout << "Most expensive item is " << maxFood << endl;

	for_each(yummy.begin(), yummy.end(),
		[&maxCost](FoodItem f) {
			if (f.getCost() == maxCost) {
				cout << f << endl;
			}
		}
	);//end of the for_each


	//create a new vector from an existing vector
	//new vector will hold values larger than an existing number
	vector <int> positive;
	int value = 0;
	for_each(ray.begin(), ray.end(),
		[&positive, value](int i) {
			if (i >= value) {
				positive.push_back(i);
			}
		}
	);//end of for_each statement

	sort(positive.begin(), positive.end());
	printVector(positive);

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
