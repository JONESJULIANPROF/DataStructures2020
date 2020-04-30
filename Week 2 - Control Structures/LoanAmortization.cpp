// LoanAmortization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double P = 20000;
	double yearlyRate = .075;
	double r;
	double monthlyPayment;
	int term = 5, n;

	//get input here

	r = yearlyRate / 12;
	n = term * 12;
	double numerator = r * pow(1 + r, n);
	double denominator = pow(1 + r, n) - 1;

	monthlyPayment = P * (numerator / denominator);
	/*monthlyPayment =
		 principal * ((monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);*/
	cout << setprecision(2) << fixed << endl;
	cout << "Monthly Payment = $" << monthlyPayment << endl;

	cout << "Monthly payment schedule" << endl;
	cout << setw(15) << left << "Balance" << setw(14) << "Interest Paid" << endl;

	double interestPaid;
	for (int m = 1; m <= n; m++) {
		//add interest then subtract the payment
		interestPaid = P * r; //calculate interest
		P -= monthlyPayment;

		P += interestPaid;
		cout << setw(10) << right << P << setw(14) << right << interestPaid << endl;
		//add a line every year
		//cout << setw(29) << setfill('_') << endl;
		if (m % 12 == 0) {
			cout << "_________________________\n";
		}
	}


}

