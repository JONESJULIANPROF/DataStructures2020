#include "Vitamin.h"

Vitamin::Vitamin()
{
}

Vitamin::Vitamin(string Name, int Amount, double PDA)
{
	this->vitName = Name;
	this->amount = Amount;
	this->percentDaily = PDA;
}

string Vitamin::getVitaminName()
{
	return this->vitName;
}

void Vitamin::setVitaminName(string Name) {
	this->vitName = Name;
}

int Vitamin::getVitaminAmount()
{
	return this->amount;
}

void Vitamin::setVitaminAmount(int Amt) {
	this->amount= Amt;
}

double Vitamin::getVitaminPDA()
{
	return this->percentDaily;
}

void Vitamin::setVitaminPDA(double PDA) {
	this->percentDaily = PDA;
}

string Vitamin::to_string()
{
	string output;
	output = "Vitamin: " + vitName;
	return output;
}

ostream& operator<<(ostream& out, const Vitamin& item)
{
	out << fixed << setprecision(0);
	out << item.vitName << " Amount " << item.amount;
	out << fixed << setprecision(1);
	out << " PDA " << item.percentDaily ;
	return out;
}

istream& operator>>(istream& in, Vitamin& item)
{
	cout << "Enter the name ";
	getline(in, item.vitName);

	cout << "Enter the amount ";
	in >> item.amount;

	cout << "Enter the PDA ";
	in >> item.percentDaily;

	return in;

}