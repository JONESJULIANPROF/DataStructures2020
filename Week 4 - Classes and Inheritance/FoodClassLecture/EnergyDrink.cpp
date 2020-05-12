#include "EnergyDrink.h"

void EnergyDrink::setCaffeine(int mgs)
{
	caffeine = mgs;
}

int EnergyDrink::getCaffeine()
{
	return caffeine;
}

string EnergyDrink::toString()
{
	string output = FoodItem::toString();//call parent toString
	output += " with mgs of caffeine " + to_string(caffeine);
	return output;
}

EnergyDrink::EnergyDrink():FoodItem()
{
	caffeine = 0;
}

EnergyDrink::EnergyDrink(string Name, int Calories, double Cost, int Mgs)
	:FoodItem(Name, Calories, Cost)
{
	caffeine = Mgs;
}
