#pragma once
#include "Person.h"
class Doctor :
	public Person
{
protected:
	string speciality;
	string id;//read only - build an ID
public:
	void setSpeciality(string spec);
	string getSpeciality();
	string getId();

	void buildID() {
		id = "Dr" + firstName.substr(0,1) + lastName + "-" + speciality.substr(0,3);
	}
	string to_string() {
		return "Doctor " + Person::to_string();
	}

	Doctor();
	Doctor(string First, string Last, string spec);//intentionally leaving ID out
};

