#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Fraction
{
protected:
	int num;
	int den;
	double dec;
public:
	Fraction();
	Fraction(int n, int d);
	double decValue();

	//create <<   >>   +

	friend ostream& operator <<(ostream& out, const Fraction& frac);
	friend istream& operator >>(istream& in, Fraction& frac);

	Fraction operator+ (Fraction& frac);
	//compare decValue

};

