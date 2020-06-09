// TimingLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <fstream>
#include <windows.h>	//need for timing
#include <random>		//need to finish shuffle
#include <vector>
#define WORDS 370099
//stl array

using namespace std;
//array<string, WORDS> manyWords;
vector<string> manyWords;
/*
array of nearly infinite size
resizable array
works just like arrays once populated

RAM hog - will take more RAM than needed
you need to trim the vector once populated
slower than arrays
*/

void swap(string* xp, string* yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}
// A function to implement bubble sort  
void bubbleSort()
{
	int i, j;
	for (i = 0; i < WORDS - 1; i++) {
		// Last i elements are already in place  
		for (j = 0; j < WORDS - i - 1; j++) {
			if (manyWords[j] > manyWords[j + 1])
				swap(&manyWords[j], &manyWords[j + 1]);
		}
		//cout << i << " ";
	}
}
/*
court
courter
*/

void fillStructure() {
	//int counter = 0;
	string aWord = "";
	ifstream fin("words.txt");
	if (fin.fail()) {
		cout << "words failed\n";
		exit(1);
	}

	while (!fin.eof()) {
		fin >> aWord;
		manyWords.push_back(aWord);
		//manyWords[counter] = aWord;
		//counter++;
	}
	fin.close();
	//cout << counter << " words read\n";
	cout << manyWords.size() << " words read\n";
	cout << manyWords.capacity() << " actual size in RAM\n";
	manyWords.shrink_to_fit();//make the size equal to the capacity
	//need to do this if the vector will not grow again
}
int main()
{
	//for timing
	//get the before time
	//do the algorithm
	//get the after time
	//elapsed = after - before
	long beforeMS;
	long afterMS;
	long elapsedMS;
	SYSTEMTIME time;
	
	//timing algorithm
	GetSystemTime(&time);//holds when the function ran
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	fillStructure();
	//do algorithm here
	GetSystemTime(&time);//holds when the function ran
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;

	elapsedMS = afterMS - beforeMS;
	cout << "Elapsed time " << elapsedMS << " MS" << endl;

	//search the file
	//binary search, brute force linear search
	//O(log n), O(n)

	GetSystemTime(&time);//holds when the function ran
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	//algorithm include
	binary_search(manyWords.begin(), manyWords.end(), "superultrafrostified");
	//do algorithm here
	//binary search depends on a sorted list, but it is really really fast
	GetSystemTime(&time);//holds when the function ran
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;

	elapsedMS = afterMS - beforeMS;
	cout << "Binary search elapsed time " << elapsedMS << " MS" << endl;


	//sorted linear search
	//shuffle the words
	random_device rnd;
	shuffle(manyWords.begin(), manyWords.end(), rnd);
	//cout << manyWords[0] << endl;

	GetSystemTime(&time);//holds when the function ran
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	
	//array<string, WORDS>::iterator word;
	vector<string>::iterator word;
	for (word = manyWords.begin(); word != manyWords.end(); word++) {
		if (*word == "zwitterionic") {
			break;//quit looop
		}
	}

	GetSystemTime(&time);//holds when the function ran
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;

	elapsedMS = afterMS - beforeMS;
	cout << "Linear search elapsed time " << elapsedMS << " MS" << endl;


	GetSystemTime(&time);//holds when the function ran
	beforeMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;
	sort(manyWords.begin(), manyWords.end());
	//quick sort O(n log n)
	//bubble sort O(n^2)
	//bubbleSort();
	
	GetSystemTime(&time);//holds when the function ran
	afterMS = ((time.wMinute * 60 + time.wSecond) * 1000) + time.wMilliseconds;

	elapsedMS = afterMS - beforeMS;
	cout << "Quick Sort elapsed time " << elapsedMS << " MS" << endl;

}
/*
//do something
	int total = 0;
	double average = 0;
	for (int x = 0; x < 1000000; x++) {
		//cout << x << endl;
		total += x;
		if (x % 2 == 0) {

		}
	}
	average = total / 1000000.0;
*/
//do something
//int total = 0;
//int avg = 0;
//for (int x = 0; x < 100000; x++) {
//	//cout << x << endl;
//	total += x;
//	
//}
//avg = total / 100000;