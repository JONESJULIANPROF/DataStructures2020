// STL Stack Queue Set Lecture 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <stack>
#include "FullName.h"
#include <queue>
#include <set>

using namespace std;

void stringStack() {
    stack <string> words;   //custom class must have <, >, and == defined
    
    words.push("word 1");
    words.push("word 2");
    words.push("word 3");
    words.push("word 4");

    cout << words.size() << " words in the stacks\n";

    cout << words.top() << " is at the top of the stack\n";
    string aWord = words.top();//do something witht he object
    if (!words.empty()) {
        words.pop();    //eliminate the item at the top
    }
    cout << words.top() << " is at the top of the stack after popping\n";
}
void stackOfClass() {
    stack <fullName> clownCar;
    clownCar.push(fullName("Lee", "Cottrell"));
    clownCar.push(fullName("Dylan", "Carfley"));
    clownCar.push(fullName("Jacob", "Berger"));
    clownCar.push(fullName("John", "Vinski"));
    clownCar.push(fullName("Fengqi", "Zhang"));

    while (!clownCar.empty()) {
        cout << clownCar.top() << " gets out\n";
        clownCar.pop();
    }

}

queue <string> vocabWords;
void fillTheQueue() {
    vocabWords.push("computer");
    vocabWords.push("memory");
    vocabWords.push("storage");
    vocabWords.push("monitor");
    vocabWords.push("keyboard");
    vocabWords.push("processor");
}

void learnTheWords() {
    char moveOn;
    while (!vocabWords.empty()) {
        cout << "What is the definition of " << vocabWords.front() << "?\n";
        cout << "Enter a letter when ready for next word ";
        cin >> moveOn;
        vocabWords.pop();//remove current word from front of the line
    }
}

void fillTheSet(set <fullName, less<fullName>> &people) {
    ifstream fin("fullnames.txt");
    string fname, lname;

    if (fin.fail()) {
        cout << "fullnames did not open, quitting\n";
        exit(1);
    }
    while (!fin.eof()) {
        fin >> fname >> lname;
        people.insert(fullName(fname, lname));
    }
    fin.close();
    cout << people.size() << " names read in\n";
}

void printTheSet(set <fullName, less<fullName>> people) {
    ostream_iterator<fullName> screen(cout, "\n");
        //<< must be defined for the class
    copy(people.begin(), people.end(), screen);
}

fullName findAPerson(set <fullName, less<fullName>> people, string fname, string lname) {
    fullName personToFind(fname, lname);
    set<fullName>::iterator found;  //location of item in the list
                                    //if not found will hold people.end()
    found = people.find(personToFind);//O(log n)
    if (found != people.end()) {
        return *found;
    }
    else {
        return fullName("found", "not");
    }

}

void showIterators() {
    ifstream fin("wordlist.txt");

    if (fin.fail()) {
        cout << "file did not open\n";
        exit(1);
    }
    set <string>::iterator itr;
    set <string, greater<string>> words;
    itr = words.begin();
    copy(istream_iterator<string>(fin), istream_iterator<string>(), inserter(words, itr));
                                                                //back_insert for stack and queue
    fin.close();
    ostream_iterator<string> screen(cout, "\n");
    copy(words.begin(), words.end(), screen);
}
int main()
{
    showIterators();
   // stringStack();
    //stackOfClass();
   // fillTheQueue();
    //learnTheWords();
  //  set <fullName, less<fullName>> people;
    //fillTheSet(people);
    //printTheSet(people);
 //   fullName peep = findAPerson(people, "Candi", "Corn");
 //   cout << peep << endl;
//
    /*set <string, greater<string>> words;
    words.insert("food");
    words.insert("food");

    cout << words.size() << " words in set\n";*/
}

