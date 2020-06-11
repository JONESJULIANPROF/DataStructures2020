#pragma once
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class player {
protected:
	int playerNum;
	string fname;
	string lname;
	double batAvg;
public:
	player() {
		playerNum = 0;
		fname = "no";
		lname = "name";
		batAvg = 0.0;
	}
	player(int num, string First, string Last, double BatAvg) {
		this->playerNum = num;
		this->fname = First;
		this->lname = Last;
		//this->batAvg = BatAvg;
		this->setBatAvg(BatAvg);
				  //not batAvg
	}

	void setPlayerNum(int num) {
		playerNum = num;
	}
	int getPlayerNum() {
		return playerNum;
	}

	//.000 - 1.000
	void setBatAvg(double BatAvg) {
		if (BatAvg >= 0 && BatAvg <= 1)
		{
			batAvg = BatAvg;
		}
		else {
			batAvg = 0.0;
		}
	}
	double getBatAvg() {
		return batAvg;
	}

	void setFname(string First) {
		fname = First;
	}
	string getFname() {
		return fname;
	}

	void setLname(string Last) {
		lname = Last;
	}
	string getLname() {
		return lname;
	}

	string to_string() {
		return fname + " " + lname;
	}

	friend ostream & operator<<(ostream& out,  const player item) {
		out << item.fname << " " << item.lname;
		return out;
	}

	friend bool operator <(player lhs, player rhs) {
		return lhs.playerNum < rhs.playerNum;
	}

	friend bool operator >(player lhs, player rhs) {
		return lhs.playerNum > rhs.playerNum;
	}

	friend bool operator ==(player lhs, player rhs) {
		if ((lhs.playerNum == rhs.playerNum) &&
			(lhs.fname == rhs.fname) && (lhs.lname == rhs.lname)
			&& (lhs.batAvg == rhs.batAvg))
		{
			return true;
		}
		else {
			return false;
		}
	}

};


