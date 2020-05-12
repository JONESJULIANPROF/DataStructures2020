#pragma once
#include <string>
using namespace std;
class Person
{
public:
	Person();
	Person(string first, string last);

	void setFirstName(string first);
	void setLastName(string last);
	string getFirstName();
	string getLastName();

	//inline functions
	//faster call, code inserted into the main when used
	//works well for small functions
	string to_string() {
		return lastName + ", " + firstName;
	}
protected:
	string firstName;
	string lastName;
};

