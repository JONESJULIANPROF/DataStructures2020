#include "Doctor.h"

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

Doctor::Doctor():Person() {
	speciality = "General";
	id = "";
}

Doctor::Doctor(string First, string Last, string spec):Person(First, Last)
{
	speciality = spec;
	buildID();
}
