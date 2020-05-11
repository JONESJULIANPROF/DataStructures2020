// StringManipulationDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>    //need for replace
//techiedelight.com/replace-occurrences-character-string-cpp/
//https://en.cppreference.com/w/cpp/algorithm
using namespace std;

int main()
{
    /*C++ strings are in two types
    string 
    a mutable class
    char array
    char name[] = "Lee";
    char* lname = new char[11];
    strcpy_s(lname, 11, "a string");

    page 497 of the book
    */

    string word = "hi";
    if (word == "hi") {
        cout << "hi back\n";
    }
    
    //strings are arrays
    word[0] = 'H';
    int pos = 0;
    cout << word + " Lee" << endl;  //concatenation
    string sentence = "Four score and seven years ago";
    //replace years with decades
    pos = sentence.find("years");
    sentence.erase(pos, 5);
    sentence.insert(pos, "decades");
    //sentence = sentence.replace(pos, 1, "week");


    //replace characters using string replace and loop
                                //max size of a string
        while ((pos = sentence.find('e')) != string::npos) {
            sentence.replace(pos, 1, "3");
         }
    //replace characters using algorithm
    replace(sentence.begin(), sentence.end(), 'o', '0');
    cout << sentence << endl;
    string revSentence;

    //reverse the string
    reverse(sentence.begin(), sentence.end());
    cout << sentence << endl;


}

