#pragma once
#include <string>
using namespace std;
class Sandwich
{//class to hold a sammie
protected:
	string bread;
	bool meat[5] = { false, false, false, false, false };
	string meatNames[5] = { "ham", "roast beef", "turkey", "salami", "chicken" };
	//better to read from a file
	double meatPrices[5] = { 3, 5, 4, 2, 4 };
	string cheese;
	bool veggies[3] = { false, false, false };
	string veggieNames[3] = { "tomato", "lettuce", "onion" };
	string size;
	bool condiments[4] = { false, false, false, false };
	string condimentNames[4] = { "ketchup", "mustard", "bbq sauce", "hot sauce" };
	double price;
public:
	//ham, roast beef, turkey, salami, chicken
	//0    1            2       3        4
	void calcPrice(){
		//small = 8, med = 10, large = 12
		price = 0;//reset the price to 0
		for (int x = 0; x < 5; x++) {
			if (meat[x]) {
				price += meatPrices[x];
			}
		}
		int sizeNum = 1;
		
		/*
		double sizePrices[3] = { 8, 10, 12 };
		price += sizePrices[sizeNum];
		
		if (sizeNum == 1) {
			price += 8;
		}
		size = "small";
		*/
		if (size == "small") {
			price += 8;
		}
		else if (size == "medium"){
			price += 10;
		}
		else if (size == "large") {
			price += 12;
		}
		else if (size == "massive") {
			price += 20;
		}
		else {
			size = "large";
			price += 12;
		}
	}
	void setMeat(int meatNum) {
		meat[meatNum] = true;
	}

	string getMeatList() {
		string meats;
		for (int x = 0; x < 5; x++) {
			if (meat[x])
			{
				meats += meatNames[x] + " ";
			}
		}
		return meats;
	}

	Sandwich() {

	}
	//Parameterized
	//setters, getters

	void setBread(string breadType) {
		this->bread = breadType;
	}
	string getBread() {
		return this->bread;
	}
	void setCheese(string cheeseChoice) {
		this->cheese = cheeseChoice;
	}
	string getCheese() {
		return this->cheese;
	}
	void setSize(string size) {
		this->size = size;
	}
	string getSize() {
		return this->size;
	}
	//to_string
	//calc price

	void prebuiltSammie(int sammieNum, string size) {
		this->size = size;
		int x;
		for (x = 0; x < 5; x++) {
			meat[x] = false;
		}
		for (x = 0; x < 3; x++) {
			veggies[x] = false;
		}
		for (x = 0; x < 4; x++) {
			condiments[x] = false;
		}
		if (sammieNum == 0) {
			//ham and swiss on rye with lettuce and mayo
			//clear out meats, veggies, condiments

			meat[0] = true;
			cheese = "swiss";
			bread = "rye";
			condiments[3] = true;
		}
		else if (sammieNum == 1) {
			//turky calami colby on pumpernickle
			meat[2] = true;
			meat[3] = true;
			cheese = "colby";
			bread = "pumpernickle";
		}
	}
};


