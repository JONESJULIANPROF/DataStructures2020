#include "FoodItem.h"
#include <iostream>
#include <iomanip>

FoodItem::FoodItem() {
	//default constructor
	name = "No name";
	calories = 0;
	cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost) {
	//parameterized constructor
	name = Name;
	calories = Calories;
	cost = Cost;
}

FoodItem::~FoodItem() {
	//destructor
	std::cout << "Eating " << name << endl;
}

double FoodItem::perCalorieCost()
{
	return cost / calories;
}

void FoodItem::setName(string Name) {
	this->name = Name;
}

string FoodItem::getName() {
	return this->name;
}

void FoodItem::setCalories(int Calories) {
	this->calories = Calories;
}

int FoodItem::getCalories() {
	return this->calories;
}

void FoodItem::setCost(double Cost) {
	this->cost = Cost;
}

double FoodItem::getCost() {
	return this->cost;
}

string FoodItem::toString() {
	return name + " has " + to_string(calories) + " and costs " + to_string(cost);
}
