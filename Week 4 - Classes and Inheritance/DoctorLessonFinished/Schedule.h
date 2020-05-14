#pragma once
#include "Patient.h"
#include "Doctor.h"

class Schedule
{
protected:
	Patient thePatient;
	Doctor theDoc;
	int hour;
public:
	Schedule();
	Schedule(Patient pat, Doctor doc, int hr);
	//not using classes in the main
	//Schedule(string pFirst, string pLast, string pComplaint, string dFirst, string dLast, string dspec, int hr);
	//would instantiante variables of Patient and Doctor

	void setPatient(Patient pat);
	void setDoctor(Doctor doc);
	void setHour(int hr);

	Patient getPatient();
	Doctor getDoctor();
	int getHour();

	string to_string() {
		return thePatient.to_string() + " will see " + theDoc.to_string() + " at " + std::to_string(hour)
			+ " o:clock";
	}
};

