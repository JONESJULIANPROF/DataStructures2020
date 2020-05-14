#include "Schedule.h"
#include "Schedule.h"

Schedule::Schedule()
{
	hour = 0;
}

Schedule::Schedule(Patient pat, Doctor doc, int hr)
{
	thePatient = pat;
	theDoc = doc;
	hour = hr;
}

Patient Schedule::getPatient()
{
	return thePatient;
}
void Schedule::setPatient(Patient pat)
{
	thePatient = pat;
}

void Schedule::setDoctor(Doctor doc)
{
	theDoc = doc;
}

void Schedule::setHour(int hr)
{
	hour = hr;
}



Doctor Schedule::getDoctor()
{
	return theDoc;
}

int Schedule::getHour()
{
	return hour;
}
