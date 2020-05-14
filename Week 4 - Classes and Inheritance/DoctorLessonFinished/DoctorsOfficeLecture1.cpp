// DoctorsOfficeLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Schedule.h"
#define SIZE 10
using namespace std;
Schedule appointments[SIZE];//default constructor called for all variables in the array
Doctor house("Gregory", "House", "Diagnosis");
Patient aPatient("Kate", "Upton", "bad back");
int hour = 8;
int numSched = 0;

void printSchedule();
void fillArray();
void menu();
void addToSchedule();
void searchByLastName(string lname);
int searchByHour(int hour);
int main()
{
    fillArray();
    menu();
   // fillArray();
   // printSchedule();
    /*cout << "Doctors office\n";
    Doctor lee("Lee", "Cottrell", "Programming");
    cout << lee.to_string() << endl;
    cout << lee.getId() << endl;

    Patient laurie("Laurie", "Cottrell", "Foot Hurts");
    cout << laurie.to_string() << endl;
    cout << laurie.getComplaint() << endl;

    Schedule appt(laurie, lee, 10);
    cout << appt.to_string() << endl;*/
}

void menu() {
    //1 = print schedule
    //2 = add to schedule
    //3 = search by hour
    //4 = search by last name
    //9 = quit
    char choice;
    int hourToFind;
    string lname;
    int pos;
    do {
        cout << "Enter 1 to print schedule\n";
        cout << "Enter 2 to add to the schedule\n";
        cout << "Enter 3 to search by hour\n";
        cout << "Enter 4 to search by patient lastname\n";
        cout << "Enter 9 to quit\n";
        cin >> choice;
        switch (choice) {  
        case '2':
            if (numSched < SIZE) {
                addToSchedule();
            }
            else {
                cout << house.to_string() << " has no open appointments\n";
            }
            
            //break;
            //pass through to the next case
        case '1':
            printSchedule();
            break;
        case '3':
            cout << "Enter the hour you wish to find ";
            cin >> hourToFind;
            pos = searchByHour(hourToFind);
            if (pos < 0) {
                cout << "hour not found\n";
            }
            else {
                cout << appointments[pos].to_string() << endl;
            }
            break;
        case '4':
            cout << "Enter the last name (one word) ";
            cin >> lname;
            searchByLastName(lname);
            break;
        case '9':
            cout << "Bye Bye\n";
            break;
        default:
            cout << choice << " is invalid, enter 1, 2, or 9\n";
            break;
        }

    } while (choice != '9');
}

void addToSchedule() {
    string fname, lname, complaint;
    cout << "Enter first and last name ";
    cin >> fname >> lname;

    cout << "What is " << fname << "'s complaint? ";
    cin.ignore(100, '\n');
    getline(cin, complaint);

    aPatient = Patient(fname, lname, complaint);
    appointments[numSched] = Schedule(aPatient, house, hour);
    hour++;
    numSched++;
}

void searchByLastName(string lname)
{
    //print matching records in the method
    //when there are multiple possiblities of mathcing
    for (int x = 0; x < numSched; x++) {
        if (appointments[x].getPatient().getLastName() == lname) {
            //chain the gets
            cout << appointments[x].to_string() << endl;
        }
    }
}

int searchByHour(int hour)
{
    //when there is ONE possible match
    //for (int x = 0; x < SIZE; x++) {//this is the traditional algorithm
    for (int x = 0; x < numSched; x++) {    //this is slighly faster in our case
        if (appointments[x].getHour() == hour) {
            return x;   //location in the array of desired element
        }
    }
    //not found
    return -1;  //not in array, -1 is not a valid array position
}

void printSchedule() {
    for (int x = 0; x < numSched; x++) {
        cout << appointments[x].to_string() << endl;
    }
}
void fillArray() {
    appointments[0] = Schedule(aPatient, house, 8);

    aPatient.setFirstName("Tiffany");
    
    appointments[1].setDoctor(house);
    appointments[1].setPatient(aPatient);
    appointments[1].setHour(9);

    aPatient.setFirstName("Bill");
    aPatient.setLastname("Pullman");
    aPatient.setComplaint("angry AT THE world");

    appointments[2].setDoctor(house);
    appointments[2].setPatient(aPatient);
    appointments[2].setHour(10);
    
    numSched = 3;
    hour = 11;


}

