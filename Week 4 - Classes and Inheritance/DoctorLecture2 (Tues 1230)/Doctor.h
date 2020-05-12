#pragma once
#include "Person.h"
class Doctor :
	public Person
{
public:
	Doctor();
	Doctor(string first, string last, string spec);
	void setSpeciality(string spec);
	string getSpeciality();
	string getId();

	void buildId() {
		//DrLCottrell-Pro
		//Dr First Letter Firstname Full LastName-First three letters specialization
		id = "Dr" + firstName.substr(0, 1) + lastName + "-" + speciality.substr(0, 3);
	}
	string to_string() {
		return "Doctor " + Person::to_string();
	}
protected:
	string speciality;
	string id;
};

