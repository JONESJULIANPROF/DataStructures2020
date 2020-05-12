#include "Person.h"
Person::Person()
{
	firstName = "";
	lastName = "";
}

Person::Person(string first, string last)
{
	this->firstName = first;
	this->lastName = last;
}

void Person::setFirstName(string first)
{
	this->firstName = first;
}

string Person::getFirstName()
{
	return firstName;
}

void Person::setLastName(string last)
{
	this->lastName = last;
}

string Person::getLastName()
{
	return lastName;
}
