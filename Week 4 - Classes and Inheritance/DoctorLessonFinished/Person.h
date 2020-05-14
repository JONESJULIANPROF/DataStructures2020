#pragma once
#include <string>

using namespace std;
class Person
{
public:
	void setName(string first, string last);
	void setFirstName(string first);
	void setLastname(string last);

	string getFirstName();
	string getLastName();

	Person(string first, string last);
	Person();

	//create inline function - speed up function calls
	//prototype and define function here
	string to_string() {
		return lastName + ", " + firstName;
	}
protected:
	string firstName;
	string lastName;

};

