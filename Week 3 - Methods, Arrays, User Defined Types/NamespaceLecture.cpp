// NamespaceLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyHeader.h"
using namespace std;
using namespace mySpace;

namespace myCode {
	void printLine(int length = 80) {
		for (int x = 0; x < length; x++) {
			std::cout << "#";
		}
		std::cout << endl;
	}
}
int main()
{
	std::cout << "Hello World!\n";//scope resolution operator :: 

	cout << mySpace::PI << endl;
	cout << PA_TAX << endl;
	mySpace::printLine(10);
	myCode::printLine(10);
}
