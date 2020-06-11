// Baseball Game Lecture 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <array>
#include <random>
#include "team.h"
#include "player.h"
#include "stats.h"
#include <iomanip>

using namespace std;
array<team, 2> theTeams;
array<queue<int>, 2> battingOrder;
random_device rnd;
uniform_real_distribution<double> swing(0, 0.6);//inclusive range of values
//uniform_int_distribution<int> die(1, 6);
//over time, the results will be statistically accurate
//harder to predict than srand and rand

queue<stats> gameStats;


void interface();
void fillDataStructures();
void playTheGame();
void replayGame();

int main()
{
    fillDataStructures();
    playTheGame();
    replayGame();
}
void replayGame() {
    int tnum, pnum;
    stats lineScore;
    while (!gameStats.empty()) {
        lineScore = gameStats.front();
        gameStats.pop();
        //cout << lineScore << endl;
        //use lookups to find team names and player names
        tnum = lineScore.getTeam();
        pnum = lineScore.getPlayerNum();
        cout << theTeams[tnum].getTeamName() << " player " << theTeams[tnum].getAPlayer(pnum)
            << " " << lineScore.getResult() << endl;
    }
}
void playTheGame() {
    int out = 0;
    int inning = 1;
    int battingTeam = 0;
    int battingNum = 0;//player number at bat
    double hitChance;
    player atbat;
    //3 inning game for demonstration
    while (inning <= 3) {
        //change batter here - interface to ask, then replace the player number

        battingNum = battingOrder[battingTeam].front();//player number from queue
        atbat = theTeams[battingTeam].getAPlayer(battingNum);
        cout << atbat << " batting now\n";

        //manage the queue
        battingOrder[battingTeam].pop();//take out of queue
        battingOrder[battingTeam].push(battingNum);

        hitChance = swing(rnd);
     //   cout << hitChance << " batavg " << atbat.getBatAvg() << endl;
        if (atbat.getBatAvg() > hitChance) {
            cout << "Hit!!\n";
            gameStats.push(stats(battingTeam, battingNum, "Hit"));
        }
        else {
            cout << "Out!\n";
            gameStats.push(stats(battingTeam, battingNum, "Out"));
            out++;
        }
        //Lehman
       // out++;
        if (out == 3) {
            cout << "Switching teams \n\n";
            out = 0;
            battingTeam++;
            if (battingTeam > 1) {
                battingTeam = 0;
                inning++;
                cout << "Inning change now " << inning << endl << endl;
             
            }
        }

    }

}
void fillDataStructures()
{
    theTeams[0] = team("Braves", "Bethlehem");
    theTeams[1] = team("Giants", "Jerusalem");

    //team 0
    //players 
    theTeams[0].addPlayer(42, "Lee", "Cottrell", .350);
    theTeams[0].addPlayer(13, "Chris", "Cottrell", .450);
    theTeams[0].addPlayer(2, "Laurie", "Cottrell", .550);
    theTeams[0].addPlayer(8, "Lizzie", "Cottrell", .150);
    theTeams[0].addPlayer(7, "Savannah", "Cottrell", .250);

  //  cout << theTeams[0].getAPlayer(42).getBatAvg() << " " <<  " BAT AVG FILL\N";;
    
    battingOrder[0].push(7);//savannah
    battingOrder[0].push(13);
    battingOrder[0].push(8);
    battingOrder[0].push(2);
    battingOrder[0].push(42);

    //team 1
    theTeams[1].addPlayer(38, "Kate", "Cottrell", .350);
    theTeams[1].addPlayer(7, "Lance", "Armstrong", .450);
    theTeams[1].addPlayer(2, "Justin", "Timberlake", .550);
    theTeams[1].addPlayer(8, "David", "Hasselhoff", .150);
    theTeams[1].addPlayer(12, "Dirty", "Dozen", .250);
    theTeams[1].addPlayer(player(2001, "HAL", "Computer", .400));

    battingOrder[1].push(7);    //lance
    battingOrder[1].push(12);   //dirty
    battingOrder[1].push(8);    //david
    battingOrder[1].push(2001); //hal
    battingOrder[1].push(38);   //kate
    battingOrder[1].push(2);    //justin

    //jeremy b
   /* for (std::map<int, player>::iterator it = teams[0].getRoster().end(); it != teams[0].getRoster().begin(); it--) {
        order[0].push((*it).second.getPlayerNum());
    }*/

}
