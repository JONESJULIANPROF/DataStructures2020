#include "Person.h"

void Person::setName(string first, string last)
{
	this->firstName = first;
	lastName = last;
}

void Person::setFirstName(string first)
{
	firstName = first;
}



string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

void Person::setLastname(string last)
{
	lastName = last;
}

Person::Person(string first, string last)
{
	this->firstName = first;
	lastName = last;
}

Person::Person()
{
	firstName = "";
	lastName = "";
}
