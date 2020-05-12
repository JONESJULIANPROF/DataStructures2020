#pragma once
#include "Person.h"
class Patient :
	public Person
{
protected:
	string complaint;
public:
	Patient();
	Patient(string first, string last, string comp);
	string getComplaint();
	void setComplaint(string comp);

	string to_string() {
		return "Patient " + Person::to_string();
	}
};

