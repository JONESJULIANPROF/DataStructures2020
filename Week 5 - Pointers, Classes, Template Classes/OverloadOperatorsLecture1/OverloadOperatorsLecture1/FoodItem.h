#pragma once
#include <string>

using namespace std;
class FoodItem
{
public:
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	~FoodItem();
	void setName(string Name);
	void setCalories(int Cal);
	void setCost(double Cost);
	string to_string();

	string getName();
	int getCalories();
	double getCost();

	//operators
	FoodItem operator + (FoodItem& item);
	FoodItem operator * (double amt);

	//output
	friend ostream& operator <<(ostream& out, const FoodItem& item);
	friend istream& operator >>(istream& in, FoodItem& item);

	//comparison
	//if(cookie > milk)
	//		lhs	   rhs
	friend bool operator >(FoodItem& lhs, FoodItem& rhs);
	friend bool operator <(FoodItem& lhs, FoodItem& rhs);
	friend bool operator ==(FoodItem& lhs, FoodItem& rhs);
	friend bool operator >=(FoodItem& lhs, FoodItem& rhs);
	friend bool operator <=(FoodItem& lhs, FoodItem& rhs);
	//define all of these for a class


protected:
	string name;
	int calories;
	double cost;
};


