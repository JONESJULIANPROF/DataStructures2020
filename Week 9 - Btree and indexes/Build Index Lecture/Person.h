#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	int id;
	string fname;
	string lname;
	string gender;
	string country;
public:
	Person() {

	}
	Person(int Id, string Fname, string Lname, string Gender, string Country) {
		this->id = Id;
		this->fname = Fname;
		this->lname = Lname;
		this->gender = Gender;
		this->country = Country;
	}
	friend ostream& operator << (ostream& out, const Person& aPerson)
	{
		out << aPerson.id << " " << aPerson.fname << " " << aPerson.lname << " lives in " << aPerson.country;
		return out;
	}
	int getId() {
		return this->id;
	}

	string getFname() {
		return this->fname;
	}

	string getLname() {
		return this->lname;
	}

	string getGender() {
		return this->gender;
	}

	string getCountry() {
		return this->country;
	}

	string getFullName() {
		return this->fname + " " + this->lname;
	}

	void setId(int id) {
		this->id = id;
	}

	void setFname(string fname) {
		this->fname = fname;
	}

	void setLname(string lname) {
		this->lname = lname;
	}

	void setCountry(string country) {
		this->country = country;
	}

	void setGender(string gender) {
		this->gender = gender;
	}
};

