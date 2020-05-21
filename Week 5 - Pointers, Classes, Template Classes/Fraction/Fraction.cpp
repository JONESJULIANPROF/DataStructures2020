#include "Fraction.h"
#include <iostream>
#include <iomanip>
using namespace std;
Fraction::Fraction()
{
	num = 0;
	den = 1;
	dec = 0;
}
Fraction::Fraction(int n, int d)
{
	num = n;
	if (d != 0) {
		den = d;
	}
	else {
		den = 1;
	}
	decValue();
}
double Fraction::decValue()
{//call in setters
	dec = num / (double) den;
	return dec;
}

Fraction Fraction::operator+(Fraction& frac)
{
	/*
	determine if the fraction needs a common denominator
	if multiply the denominators to get gcd
	*/
	Fraction sum;
	if (this->den == frac.den) {
		//already the same denominator
		sum.num = this->num + frac.num;
		sum.den = this->den;
	}
	else {
		//need a common denominator
		int gcd = this->den * frac.den;
		sum.den = gcd;
		//    1/2   +  1/3 = 5/6
		//    this     frac
		sum.num = this->den * frac.num + frac.den * this->num;
	}

	return sum;

}

ostream& operator<<(ostream& out, const Fraction& frac)
{
	//cout << half << endl;
	out << frac.num << "/" << frac.den;
	return out;
}

istream& operator>>(istream& in, Fraction& frac)
{
	cout << "Enter the numerator ";
	in >> frac.num;
	
	do {
		cout << "Enter a non-zero denominator ";
		in >> frac.den;
	} while (frac.den == 0);

	return in;
}
