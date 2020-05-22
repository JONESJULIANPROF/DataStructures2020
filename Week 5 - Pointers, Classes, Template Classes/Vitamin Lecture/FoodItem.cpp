#include "FoodItem.h"
#include "Vitamin.h"
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

FoodItem::FoodItem(string Name, int Calories, double Cost, Vitamin list[], int numVit)
{
	name = Name;
	calories = Calories;
	cost = Cost;
	//vitamins = list;	//copy the array
	if (numVit > 10) {
		numVit = 10;
	}
	if (numVit < 0) {
		numVit = 0;
	}
	for (int x = 0; x < numVit; x++) {
		vitamins[x] = list[x];
	}
	numVitamins = numVit;

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
FoodItem FoodItem::operator+(FoodItem& item)
{	//cookie + milk
	//this->   item
	FoodItem sum;
	sum.calories = this->calories + item.calories;
	sum.cost = this->cost + item.cost;
	sum.name = this->name + ", " + item.name;
	return sum;
}
FoodItem FoodItem::operator*(double amt)
{
	FoodItem product;

	char outnum[20];
	sprintf_s(outnum, 20, "%.2f of ", amt);
	product.name = outnum + this->name;
	product.calories = this->calories*amt;
	product.cost = this->cost * amt;

	return product;
}
FoodItem FoodItem::operator++()
{
	//prefix ++
	//we define what it means
	//I define that ++ food means to double the amount of calories and cost
	//return the item with the math done to it
	this->calories *= 2;
	this->cost *= 2;
	return FoodItem(this->getName(), this->getCalories(), this->getCost());
	//return a brand new FoodITem created by the constructor
}
FoodItem FoodItem::operator++(int)
{
	//postfix ++
	FoodItem orig(this->getName(), this->getCalories(), this->getCost());

	this->calories *= 2;
	this->cost *= 2;

	return orig;
	//return the value before the math
	
}
void FoodItem::setVitamins(Vitamin list[], int numVit)
{
	if (numVit > 10) {
		numVit = 10;
	}
	if (numVit < 0) {
		numVit = 0;
	}
	for (int x = 0; x < numVit; x++) {
		vitamins[x] = list[x];
	}
	numVitamins = numVit;
}
void FoodItem::setVitamins()
{
	//interactive add to the list
	//do while loop until finished
	string moreVit = "yes";
	int count = 0;
	do {
		cout << "Enter vitamin\n";
		cin >> vitamins[count];
		count++;
		cout << "More vitamins? (yes or no) ";
		cin >> moreVit;
		//newline screwed up the cin for vitmain
		cin.ignore(100, '\n');
	} while (moreVit == "yes" && count < 10);
	numVitamins = count;
}
void FoodItem::getVitamins()
{
	//cout to screen
	for (int x = 0; x < numVitamins; x++) {
		cout << vitamins[x] << endl;
	}
}
Vitamin FoodItem::getAVitamin(int vitNum)
{
	if (vitNum < numVitamins && vitNum >= 0) {
		return vitamins[vitNum];
	}
	return Vitamin();//blank return for NULL
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

ostream& operator<<(ostream& out, const FoodItem& item)
{
	out << fixed << setprecision(0);
	out << item.name << " has " << item.calories << " calories";
	out << fixed << setprecision(2);
	out << " and costs $" << item.cost;

	if (item.numVitamins > 0) {
		out << "\nVitamins\n";
		for (int x = 0; x < item.numVitamins; x++) {
			out << item.vitamins[x] << endl;
		}
	}

	return out;
}

istream& operator>>(istream& in, FoodItem& item)
{
	cout << "Enter the name ";
	getline(in, item.name);

	cout << "Enter the calories ";
	in >> item.calories;

	cout << "Enter the cost";
	in >> item.cost;

	return in;

}

//comparison
bool operator>(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories > rhs.calories);
}

bool operator<(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories < rhs.calories);
}

bool operator>=(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories >= rhs.calories);
}

bool operator<=(FoodItem& lhs, FoodItem& rhs) {
	return(lhs.calories <= rhs.calories);
}

bool operator==(FoodItem& lhs, FoodItem& rhs) {
	/*
	if just one property of class
		return(lhs.calories == rhs.calories);
	*/

	//comparing multiple properties
	if (lhs.name == rhs.name
		&& lhs.calories == rhs.calories
		&& lhs.cost == rhs.cost) {
		return true;
	}
	else {
		return false;
	}

}
