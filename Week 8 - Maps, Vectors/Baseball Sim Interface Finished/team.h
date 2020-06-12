#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include "player.h"

using namespace std;

class team {
protected:
	string teamName;
	string homeField;
	map<int, player> roster;
public:
	team() {
		teamName = "No name";
		homeField = "left of nowhere";
	}
	team(string name, string home, map<int, player> list) {
		teamName = name;
		homeField = home;
		roster = list;
	}

	team(string name, string home) {
		teamName = name;
		homeField = home;
	}

	void setTeamName(string name) {
		teamName = name;
	}

	void setHomeField(string name) {
		homeField = name;
	}

	string getTeamName() {
		return teamName;
	}

	string getHomeField() {
		return homeField;
	}
	//interface to roster
	string to_string() {
		return homeField + " " + teamName;
	}
	map<int, player> getRoster() {
		return roster;
	}

	void setRoster(map<int, player> list) {
		roster = list;
	}

	//interface to the structure
	//add a player
	void addPlayer(player newPlayer) {
		roster[newPlayer.getPlayerNum()] = newPlayer;
		
	}

	void addPlayer(int playerNum, string fname, string lname, double batAvg) {
		roster[playerNum] = player(playerNum, fname, lname, batAvg);
		
		//constructor call
	}

	player getAPlayer(int playerNum) {
		return roster[playerNum];
	}
	
	string getAPlayerByLastName(string lastName) {
		string output = "";
		map<int, player>::iterator itr;
		player aPlayer;
		for (itr = roster.begin(); itr != roster.end(); itr++) {
			//cout << itr->second.getLname() << endl;
			if (lastName == itr->second.getLname()) {
				output += itr->second.to_string() + ", ";
			}
		}
		return output;
	}

	player getAPlayerByFullName(string firstName, string lastName) {
		player output;
		map<int, player>::iterator itr;
		player aPlayer;
		for (itr = roster.begin(); itr != roster.end(); itr++) {
			//cout << itr->second.getLname() << endl;
			if (lastName == itr->second.getLname() && firstName == itr->second.getFname()) {
				return itr->second;
			}
		}

		return output;//not found
	}


	friend ostream& operator<<(ostream& out, const team item) {
		out << item.homeField << " " << item.teamName;
		return out;
	}
};



