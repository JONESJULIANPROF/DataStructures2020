// TemplateLecture2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "GenClass.h"
#include "rectangleType.h"
using namespace std;

//int bigger(int a, int b) {
//	if (a < b) {
//		return b;
//	}
//	else {
//		return a;
//	}
//}
//
//string bigger(string a, string b) {
//	if (a < b) {
//		return b;
//	}
//	else {
//		return a;
//	}
//}

template <class T>
T bigger(T a, T b) {
	if (a >  b) {
		return a;
	}
	else
	{
		return b;
	}
}

//two different data types
template <class T1, class T2>
T1 addEm(T1 a, T2 b) {
	return a + b;
}

int main()
{
	int a = 42, b = 15;
	string n1 = "Lee", n2 = "Julian";

	double pi = 3.1415927;
	cout << addEm(a, pi) << endl;
	cout << addEm(pi, a) << endl;


	cout << bigger(a, b) << endl;
	cout << bigger(n1, n2) <<endl;

	

	
	GenClass<string> c1("Lee Cottrell");
	GenClass<int> aNumber(42);

	cout << c1.getTheValue() << " " << aNumber.getTheValue() << endl;

}

