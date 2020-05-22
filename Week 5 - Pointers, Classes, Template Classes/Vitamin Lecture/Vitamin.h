#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class Vitamin
{
protected:
	string vitName;
	int amount;
	double percentDaily;
public:
	Vitamin();
	Vitamin(string Name, int Amount, double PDA);

	string getVitaminName();
	void setVitaminName(string Name);

	int getVitaminAmount();
	void setVitaminAmount(int Amt);

	double getVitaminPDA();
	void setVitaminPDA(double PDA);

	string to_string();

	friend ostream& operator <<(ostream& out, const Vitamin& item);
	friend istream& operator >>(istream& in, Vitamin& item);
};

