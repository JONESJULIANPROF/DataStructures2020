#include "Doctor.h"

Doctor::Doctor():Person()
{
	speciality = "";
	id = "";
}

Doctor::Doctor(string first, string last, string spec):Person(first, last)
{
	speciality = spec;
	buildId();
}

void Doctor::setSpeciality(string spec)
{
	speciality = spec;
}

string Doctor::getSpeciality()
{
	return speciality;
}

string Doctor::getId()
{
	return id;
}
