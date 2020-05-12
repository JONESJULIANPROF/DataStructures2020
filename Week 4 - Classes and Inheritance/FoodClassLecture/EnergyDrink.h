#pragma once
#include "FoodItem.h"
class EnergyDrink :
	public FoodItem
{
public:
	void setCaffeine(int mgs);
	int getCaffeine();

	//override parent toString
	string toString();
	//Constrcutors

	EnergyDrink();
	EnergyDrink(string Name, int Calories, double Cost, int Mgs);

protected:
	int caffeine;
};

