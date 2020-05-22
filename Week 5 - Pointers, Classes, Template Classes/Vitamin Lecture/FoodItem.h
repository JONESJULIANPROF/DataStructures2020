#pragma once
#include <string>
#include "Vitamin.h"
using namespace std;
class FoodItem
{
public:
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	FoodItem(string Name, int Calories, double Cost, 
		Vitamin list[], int numVit );
	~FoodItem();
	void setName(string Name);
	void setCalories(int Cal);
	void setCost(double Cost);
	string to_string();

	string getName();
	int getCalories();
	double getCost();

	//operators
	//cookie + milk
	FoodItem operator + (FoodItem& item);
	friend ostream& operator <<(ostream& out, const FoodItem& item);
	friend istream& operator >>(istream& in, FoodItem& item);

	//if(cookie > milk)
	//    lhs      rhs
	friend bool operator>(FoodItem& lhs, FoodItem& rhs);
	friend bool operator<(FoodItem& lhs, FoodItem& rhs);
	friend bool operator>=(FoodItem& lhs, FoodItem& rhs);
	friend bool operator<=(FoodItem& lhs, FoodItem& rhs);
	friend bool operator==(FoodItem& lhs, FoodItem& rhs);
	
	FoodItem operator * (double amt);

	//postfix and prefix ++
	//unary operators, work on one variable
	FoodItem operator++();	//prefix ++
	//++egg

	FoodItem operator++(int);	//postfix, the int is a dummy and is not used
	//egg++

	//need a way to add vitamins to the clas
	//need a way to print out the vitamins in the class
	void setVitamins(Vitamin list[], int numVit);
	void setVitamins();//interactive add to the array

	void getVitamins(); //print to the screen
	Vitamin getAVitamin(int vitNum);	//return one vitamin

	


protected:
	string name;
	int calories;
	double cost;

	//adding vitamin information
	Vitamin vitamins[10];
	int numVitamins=0;
};


