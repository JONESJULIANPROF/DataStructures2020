// BuildIndexLecture2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <fstream>
#include <set>
#include "Person.h"

using namespace std;
//key type, data type
map <int, Person> database;
map <string, int> fullNameIndex;	
map <string, set<int>> countryIndex;
//fullName, ID
void populateDatabase(string fileName) {
	//read the file one line at a time
	//read the line one , at a time
	//columns are fields, line is a record

	ifstream fin(fileName);
	string line;
	char* field;
	char* nextField;//after the next , in the line
	Person aPerson;

	if (fin.fail()) {
		cout << fileName << " did not open\n";
		exit(1);
	}

	getline(fin, line);//read in first line, then ignore it
	while (getline(fin, line)) {
		
		if (!line.empty()) {
			char* record = new char[line.length() + 1];
			strcpy_s(record, line.length() + 1, line.c_str());
			//converts line to a char * string

			field = strtok_s(record, ",", &nextField);
			aPerson.setId(stoi(field));

			field = strtok_s(NULL, ",", &nextField);	//gets the next field
			aPerson.setFname(field);

			field = strtok_s(NULL, ",", &nextField);
			aPerson.setLname(field);

			field = strtok_s(NULL, ",", &nextField);
			aPerson.setGender(field);

			field = strtok_s(NULL, ",", &nextField);
			aPerson.setCountry(field);

			//cout << aPerson << endl;
			database[aPerson.getId()] = aPerson;
			fullNameIndex[aPerson.getFullName()] = aPerson.getId();
			countryIndex[aPerson.getCountry()].insert(aPerson.getId());
		}
	}

	fin.close();

}
void buildIndexes() {
	map <int, Person>::iterator dataItr;
	//map iterator
	//first is the key
	//second is the data
	for (dataItr = database.begin(); dataItr != database.end(); dataItr++) {
		fullNameIndex[dataItr->second.getFullName()] = dataItr->first;
		countryIndex[dataItr->second.getCountry()].insert(dataItr->first);
	}

	/*for (auto itr = database.begin(); itr != database.end(); itr++) {

	}*/
}
int main()
{
	populateDatabase("indexdata.csv");
	//buildIndexes();

	cout << database[163] << endl;//O(1)

	cout << database[fullNameIndex["Em Burns"]] << endl;//O(1)
	//search for fullname


	/*
		read the database
		array = select unique countryName from table
		order by countryName
		loop array{
			spinner.addItem()
		}
	*/
	string cname = "New Zealand";
	set<int>::iterator countryItr;

	for (countryItr = countryIndex[cname].begin(); countryItr != countryIndex[cname].end();countryItr++) {
		//cout << *countryItr << " Index of a new zealand record\n";
		cout << database[*countryItr] << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
