// STL Forward List Lecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#include <forward_list>
#include <algorithm>
#include <iterator>
using namespace std;
void fillTheList(forward_list<string> &theList, string fileName);
void showTheList(forward_list<string> theList);
void caseString(string &word);

int main()
{
	forward_list <string> adjectives, nouns, allWords;
	fillTheList(adjectives, "adjective.txt");
	fillTheList(nouns, "nouns.txt");

	//caseString("cottrell");
	//showTheList(nouns);

	//binary search call - returns true if found, false if not found
	if (binary_search(nouns.begin(), nouns.end(), "cell")) {
		cout << "Cell is found!\n";
	}
	else {
		cout << "Cell is NOT found :(\n";
	}

	//merge 
	allWords.splice_after(allWords.before_begin(), adjectives);
	allWords.splice_after(allWords.before_begin(), nouns);
	allWords.sort();
	//showTheList(allWords);
	for_each(allWords.begin(), allWords.end(), caseString);
	//apply a method (caseString to all the elements in the container
	showTheList(allWords);
	

}
void showTheList(forward_list<string> theList) {
	//use iterators to walk through the list
	//beginning and end of the container
	forward_list<string>::iterator word;	//it is a common iterator name
	int count = 1;
	//.begin returns the pointer to the start of the container
	for (word = theList.begin(); word != theList.end(); word++) {
		cout << left << setw(15) << *word;
		if (count % 5 == 0) {
			cout << endl;
		}
		count++;
	}
}
void caseString(string &word)
{
	for (char& x : word) {
		x = toupper(x);
	}
	//cout << word << " ";

}
void fillTheList(forward_list<string>& theList, string fileName) {
	string word;
	int count = 0;
	ifstream fin(fileName);	//open at the same time
	if (fin.fail()) {
		cout << fileName << " failed to open - quitting" << endl;
		exit(1);
	}
	while (!fin.eof()) {
		fin >> word;
		count++;
		theList.push_front(word);	//puts the word into the list
	}
	cout << count << " words read from " << fileName << endl;
	fin.close();

	theList.sort();
}
