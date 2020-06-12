// Baseball Game Lecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "team.h"
#include "stats.h"
#include "player.h"
#include <queue>
#include <array>
#include <random>
using namespace std;
array<team, 2> theTeams;	//2 teams per game
//use array of queue to track the team's at bats
array<queue<int>, 2> battingOrder;
random_device rnd;
uniform_real_distribution<double> swing(0, 0.6);//number between 0 and 1 - inclusive
//uniform_int_distribution<int> die(1, 6);
//over time, the results will be stattistically valid for true random numbers
//harder to predict than the rand() algorithm we used
queue<stats> gameStats;

void interface();
void fillDataStructures();
void playTheGame();
void replayGame();
void searchForPlayer();
int main()
{
	//fillDataStructures();
	//playTheGame();
	//replayGame();
	interface();
}
void searchForPlayer() {
	char choice;
	string lastName = "";
	string firstName = "";
	cout << "<#> search by number\n";
	cout << "<N> search by last name\n";
	cout << "<F> search by full name\n";
	cin >> choice;
	choice = toupper(choice);

	switch (choice) {
	case '#':
		int playerNum;
		cout << "Enter a player number ";
		cin >> playerNum;
		//search both teams at once
		for (int x = 0; x < 2; x++) {
			cout << theTeams[x].getTeamName() << endl;
			cout << theTeams[x].getAPlayer(playerNum) << endl;
			cout << endl;
		}
		break;
	case 'N':
		
		cout << "Enter a player last name ";
		cin >> lastName;
		for (int x = 0; x < 2; x++) {
			cout << theTeams[x].getTeamName() << endl;
			cout << theTeams[x].getAPlayerByLastName(lastName) << endl;
			cout << endl;
		}
		//do we code search by lastname here in the program or in the class?
		break;
	case 'F':

		cout << "Enter a player last name ";
		cin >> lastName;
		cout << "Enter a player first name ";
		cin >> firstName;
		for (int x = 0; x < 2; x++) {
			cout << theTeams[x].getTeamName() << endl;
			cout << theTeams[x].getAPlayerByFullName(firstName, lastName) << endl;
			cout << endl;
		}
		//do we code search by lastname here in the program or in the class?
		break;
	default:
		cout << choice << " is not valid\n";
		break;
	}

}
void replayGame() {
	int pnum, tnum;
	stats lineScore;
	while (!gameStats.empty()) {
		lineScore = gameStats.front();
		gameStats.pop();
		//cout << lineScore << endl;
		tnum = lineScore.getTeam();
		pnum = lineScore.getPlayerNum();
		//lookups into structures
		cout << theTeams[tnum].getTeamName() << " player " << theTeams[tnum].getAPlayer(pnum)
			<< " " << lineScore.getResult() << endl;
	}
}
void fillDataStructures() {
	//hard code arrays
	theTeams[0] = team("Braves", "Bethlehem");
	theTeams[1] = team("Giants", "Jerusalem");

	//players and batting order
	//team 0
	theTeams[0].addPlayer(42, "Lee", "Cottrell", .350);
	theTeams[0].addPlayer(13, "Chris", "Cottrell", .450);
	theTeams[0].addPlayer(2, "Laurie", "Cottrell", .550);
	theTeams[0].addPlayer(8, "Lizzie", "Cottrell", .150);
	theTeams[0].addPlayer(7, "Savannah", "Cottrell", .150);

	battingOrder[0].push(7);	//Savannah
	battingOrder[0].push(13);	//Chris
	battingOrder[0].push(8);	//Lizzie
	battingOrder[0].push(2);	//Laurie
	battingOrder[0].push(42);	//Lee

	//team 1

	theTeams[1].addPlayer(38, "Kate", "Upton", .350);
	theTeams[1].addPlayer(7, "Lance", "Armstrong", .450);
	theTeams[1].addPlayer(2, "Justin", "Timberlake", .550);
	theTeams[1].addPlayer(8, "David", "Hasselhoff", .150);
	theTeams[1].addPlayer(12, "Dirty", "Dozen", .150);
	theTeams[1].addPlayer(player(2001, "HAL", "Computer", .400));

	battingOrder[1].push(7);	//Lance
	battingOrder[1].push(12);	//Dirty
	battingOrder[1].push(8);	//David
	battingOrder[1].push(2);	//Justin
	battingOrder[1].push(38);	//Kate
	battingOrder[1].push(2001);





}
void playTheGame()
{
	int out = 0;
	int inning = 1;	//4 inning game
	int battingTeam = 0;	//or 1
	player atbat;
	int battingNum;
	double hitChance;

	while (out < 3 && inning <= 4) {
		battingNum = battingOrder[battingTeam].front();	//get player number from the queue
		atbat = theTeams[battingTeam].getAPlayer(battingNum);
		cout << atbat << " is batting now\n";
		//manage batting queue


		//swing simulation - if player batAvg ? hitChance, a hit else out
		hitChance = swing(rnd);
		if (atbat.getBatAvg() > hitChance) {
			cout << "Hit!!\n";
			gameStats.push(stats(battingTeam, battingNum, "Hit"));
		}
		else {
			cout << "Out :(\n";
			out++;
			gameStats.push(stats(battingTeam, battingNum, "Out"));

		}

		battingOrder[battingTeam].pop();//remove from the queue
		battingOrder[battingTeam].push(battingNum);
		//out++;	//3 outs per side


		if (out == 3) {
			cout << "Switching teams\n\n";
			out = 0;
			battingTeam++;
			if (battingTeam > 1) {
				battingTeam = 0;
				inning++;
				cout << "Inning change now " << inning << endl;
				//char c;
				//cin >> c;	//stupid pause
			}
		}
	}
}
void interface() {
	//not yet
	bool data = false;
	bool played = false;
	char choice = ' ';

	do {
		cout << "<Q>uit\n";
		if (!data) {
			cout << "<F>ill sample data\n";
			//make the object not visible
		}
		if (data) {
			cout << "<P>rint team rosters\n";
			cout << "<S>earch for a player\n";
		}
		cout << "<A>dd a player\n";

		if (!played) {
			cout << "<G>ame on!<\n";
		}
		else {
			cout << "<R>eview the game\n";
		}


		cin >> choice;
		choice = toupper(choice);
		switch (choice) {
		case 'Q':
			break;
		case 'F':
			//cout << choice << " not implemented yet\n";
			if (!data) {
				fillDataStructures();
				data = true;	//set the flag
				cout << "Sample data used\n";
			}
			break;
		case 'P':
			cout << choice << " not implemented yet\n";
			break;
		case 'S':
			if (data) {
				searchForPlayer();
			}
			break;
		case 'A':
			cout << choice << " not implemented yet\n";
			break;
		case 'G':
			if (!played) {
				if (data) {
					playTheGame();
					played = true;
				}
				else {
					cout << "Fill the teams before playing\n";
				}
			}
			break;
		case 'R':
			if (played) {
				replayGame();
				played = false;
			}
			else {
				cout << "Play the game before playing\n";
			}
			break;
		default:
			cout << choice << " is not a valid response\n";
		};

	} while (choice != 'Q');
	cout << "Thank you for playing\n";
}

