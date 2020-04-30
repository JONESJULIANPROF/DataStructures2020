/*
calculate roots of quadratic equation using the quadratic formula
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	cout << "Ch4 num 7 - real roots\n\n";
	double a, b, c, root1, root2, disc;
	cout << "Enter a, b and c from your formula ";
	cin >> a >> b >> c;

	cout << a << "x^2 + " << b << "x + " << c << endl;
	
	disc = b * b - 4 * a * c;

	if (disc == 0) {
		cout << "One real root\n";
		root1 = (-b + sqrt(disc)) / 2 * a;
		cout << "Root of equation = " << root1 << endl;
	}
	else if (disc > 0) {
		cout << "Two real roots\n";
		root1 = (-b + sqrt(disc)) / 2 * a;
		root2 = (-b - sqrt(disc)) / 2 * a;

		cout << "Root of equation = " << root1 << endl;
		cout << "Root of equation = " << root2 << endl;

	}
	else if (disc < 0) {
		cout << "No real roots, only imaginary\n";
	}
	else {
		cout << "Something weird happened! No roots at all";
		return -1;
	}


	return 0;	// no errors, c++ does that for us 
	
}