#pragma once
//generic class, will hold any data type
#include <iostream>
#include <iomanip>
using namespace std;
template <class C>
class GenClass
{
protected:
	C theValue;
public:
	GenClass() {
		theValue = NULL;
	}
	GenClass(C data) {
		theValue = data;
	}
	void setTheValue(C data) {
		theValue = data;
	}
	C getTheValue() {
		return theValue;
	}
	friend ostream& operator<<(ostream& out, const C data) {
		out << data << endl;
		return out;
	}
};

