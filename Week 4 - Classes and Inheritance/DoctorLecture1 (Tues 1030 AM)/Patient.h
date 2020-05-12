#pragma once
#include "Person.h"
class Patient :
	public Person
{
protected:
	string complaint;
public:
	void setComplaint(string Complaint);
	string getComplaint();
	string to_string() {
		return "Patient " + Person::to_string();
	}

	Patient();
	Patient(string First, string Last, string Complaint);
};

