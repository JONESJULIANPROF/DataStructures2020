#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "team.h"
using namespace std;
class stats
{
protected:
	int teamNum;	//keys
	int playerNum;	//keys
	string result;
public:
	stats() {
		playerNum = 0;
		result = "";
	}
	stats(int PlayerNum, string Result) {
		playerNum = PlayerNum;
		result = Result;
	}

	stats(int Team, int PlayerNum, string Result) {
		this->teamNum = Team;
		playerNum = PlayerNum;
		result = Result;
	}

	friend ostream& operator<<(ostream& out, const stats item) {
		out << item.teamNum << " " << item.playerNum << " " << item.result;
		return out;
	}

	void setPlayerNum(int num) {
		playerNum = num;
	}

	void setResult(string Result) {
		result = result ;
	}

	int getPlayerNum() {
		return playerNum;
	}

	string getResult() {
		return result;
	}

	int getTeam() {
		return teamNum;
	}

	void setTeam(int ATeam) {
		teamNum = ATeam;
	}

	
};

