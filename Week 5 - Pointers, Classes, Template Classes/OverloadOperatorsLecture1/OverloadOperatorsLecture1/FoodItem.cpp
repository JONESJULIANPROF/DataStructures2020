#include "FoodItem.h"
#include <iomanip>
#include <iostream>
using namespace std;
//constructors
#pragma region Constructors and Destructors
FoodItem::FoodItem() {
	name = "No name";
	calories = 0;
	cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost) {
	name = Name;
	calories = Calories;
	cost = Cost;
}

FoodItem::~FoodItem() {
	//destructor
	//only needed to clean up memory
}

#pragma endregion 

#pragma region Setters and Getters

void FoodItem::setName(string Name) {
	name = Name;
}

void FoodItem::setCalories(int Cal) {
	calories = Cal;
}

void FoodItem::setCost(double Cost) {
	cost = Cost;
}

string FoodItem::getName() {
	return name;
}
int FoodItem::getCalories() {
	return calories;
}

double FoodItem::getCost() {
	return cost;
}
#pragma endregion

string FoodItem::to_string() {
	string output = "";
	//why type std??
	output = name + " has " + std::to_string(calories) + " calories "
		+ "and costs $" + std::to_string(cost);

	//we will do this better next week
	return output;
}


#pragma region operators

//snack = cookies + milk

FoodItem FoodItem::operator + (FoodItem& item) {
	FoodItem sum;
	sum.calories = this->calories + item.calories;
	sum.cost = this->cost + item.cost;
	sum.name = this->name + ", " + item.name;
	return sum;
}

//cout << snack << endl;
ostream& operator<<(ostream& out, const FoodItem& item)
{
	// TODO: insert return statement here
	out << fixed << setprecision(0);
	out << item.name << " has " << item.calories;
	out << fixed << setprecision(2);
	out << " calories and costs $" << item.cost;

	return out;
}
//cin >> otherFood;
istream& operator >>(istream& in, FoodItem& item) {
	cout << "Enter the name ";
	in >> item.name;

	cout << "Enter the calories ";
	in >> item.calories;

	cout << "Enter the cost ";
	in >> item.cost;

	return in;
}
//comparing using calories
bool operator >(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories > rhs.calories);
}

bool operator <(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories < rhs.calories);
}

bool operator >=(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories >= rhs.calories);
}

bool operator <=(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories <= rhs.calories);
}

bool operator == (FoodItem & lhs, FoodItem & rhs) {
	/*
	if just on calories
	return(lhs.calories == rhs.calories);
	*/
	//could have used .name, .calories, .cost
	if (lhs.getName() == rhs.getName()
		&& lhs.getCalories() == rhs.getCalories()
		&& lhs.getCost() == rhs.getCost()) {
		return true;
	}
	else {
		return false;
	}

}

FoodItem FoodItem::operator * (double amt) {
	FoodItem product;
	char output[20];
	sprintf_s(output,20, "%.2f of ", amt);
	product.name = output + this->name;
	product.calories = this->calories * amt;
	product.cost = this->cost * amt;
	return product;
}


#pragma endregion