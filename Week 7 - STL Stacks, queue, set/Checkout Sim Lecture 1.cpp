// Checkout Sim Lecture 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <queue>
#include "Customer.h"
#include <fstream>
using namespace std;

queue <customer> checkoutLine;
int curCustTime = 0;
int custCount = 0;
int itemsSold = 0;

void addCustomer();
void checkout();

int main()
{
	srand(time(NULL));
	ofstream out("checkoutstats.csv");
	if (out.fail()) {
		cout << "checkoutstats failed to open, dying, aaaargh\n";
		exit(0);
	}
	out << "Left in queue,Customers Checked out,itemsSold" << endl;

	//customer aCust;
	//cout << aCust.to_string();

	int minutes = 0;
	for (int x = 1; x <= 15000; x++) {
		for (minutes = 1; minutes <= 120; minutes++) {
			//do the checkout stuff here
			addCustomer();
			if (!checkoutLine.empty()) {
				checkout();
			}
		}
	/*	cout << "After 2 hours " << endl;
		cout << checkoutLine.size() << " left in queue" << endl;
		cout << custCount << " customers checked out" << endl;
		cout << itemsSold << " items sold" << endl;
		cout << 120.0 / custCount << " min per customer " << endl;
		cout << itemsSold / custCount << " avg items in buggy" << endl;*/

		out << checkoutLine.size() << "," << custCount << "," << itemsSold << endl;

		//resetting each line
		//queue<customer> checkoutLine;	//rebuild the queue - emptys it
		while (!checkoutLine.empty()) {
			checkoutLine.pop();
			//pop remaining items in the queue
		}
		itemsSold = 0;
		custCount = 0;
	}
	out.close();
	cout << "simulation is done\n";
}
void addCustomer() {
	//assume 1 customer per minute
	//checkoutLine.push(customer());

	//randomize the number of customers 0, 1, 2, 3
	//linear regression
	//build a formula to calculate the times to checkout based on the number of customers
	int newCust = int(rand() % 20);//higher number will mean fewer customers
	switch (newCust) {
	case 0://add three customers
		checkoutLine.push(customer());
		checkoutLine.push(customer());
		checkoutLine.push(customer());
		break;
	case 2:
	case 1://add two customers
		checkoutLine.push(customer());
		checkoutLine.push(customer());
		break;
	case 6:
	case 3:
	case 4:
	case 5:
		//one customer
		checkoutLine.push(customer());
		break;
	default://6, 7, 8, 9
		//no customer added
		break;
	}


}
void checkout() {
	customer current = checkoutLine.front();
	curCustTime++;//add one to current time
	if (curCustTime >= current.getCheckoutTime()) {
		custCount++;
		curCustTime = 0;
		//cout << "checkout " << current << endl;
		itemsSold += current.getItemsInBuggy();
		checkoutLine.pop();
	}
}