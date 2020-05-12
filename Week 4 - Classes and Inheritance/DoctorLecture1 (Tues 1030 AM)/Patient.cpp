#include "Patient.h"

void Patient::setComplaint(string Complaint)
{
	complaint = Complaint;
}

string Patient::getComplaint()
{
	return complaint;
}

Patient::Patient():Person()
{
	complaint = "";
}

Patient::Patient(string First, string Last, string Complaint):Person(First, Last)
{
	complaint = Complaint;
}
