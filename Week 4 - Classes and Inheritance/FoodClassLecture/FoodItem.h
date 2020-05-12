#pragma once
#include <string>
using namespace std;

class FoodItem
{
protected:
	//inherited variables
	string name;
	int calories;
	double cost;
private:
	//noninherited variables
public:
	//methods prototypes
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	void setName(string Name);
	string getName();
	void setCalories(int Calories);
	int getCalories();
	void setCost(double Cost);
	double getCost();
	string toString();
	//destructor - called when class goes out of scope
	~FoodItem();

	double perCalorieCost();
};

