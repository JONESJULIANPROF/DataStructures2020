#include "Patient.h"

Patient::Patient():Person()
{
	complaint = "";
}

Patient::Patient(string first, string last, string comp):Person(first, last)
{
	complaint = comp;
}

string Patient::getComplaint()
{
	return complaint;
}

void Patient::setComplaint(string comp)
{
	complaint = comp;
}
