#pragma once
//ensures that the elements in this file are 
//added ONE time to a project

namespace mySpace {
	const double PI = 3.14;
	const double PA_TAX = .07;

	void printLine(int length = 80) {
		for (int x = 0; x < length; x++) {
			std::cout << "-";
		}
		std::cout << "\n";
	}
}
