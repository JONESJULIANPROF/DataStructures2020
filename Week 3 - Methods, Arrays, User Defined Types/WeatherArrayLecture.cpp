// WeatherArrayLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//fill array from file
//store stats for the array in the array
//high and low for each column

#include <iostream>
#include <fstream>
#include <iomanip>
#define HI 1
#define LOW 0
#define RECORDHI 365
#define RECORDLOW 366

using namespace std;
int readFile(string path);
void processArray();

//365 = high values for each column
//366 = low value for each column
int temps[367][2];
int records = -1;

int main()
{
    cout << readFile("temps.txt") << " records read\n";
    processArray();

    cout << "Low Temps" << setw(9) << temps[RECORDLOW][LOW] << setw(9) << temps[RECORDLOW][HI] << endl;
    cout << "Hi Temps " << setw(9) << temps[RECORDHI][LOW] << setw(9) << temps[RECORDHI][HI] << endl;


}
void processArray() {
    temps[RECORDHI][LOW] = temps[0][LOW];
    temps[RECORDHI][HI] = temps[0][HI];
    /*
    temps[365][0] = temps[0][0];
    temps[365][1] = temps[0][1];
    */
    temps[RECORDLOW][LOW] = temps[0][LOW];
    temps[RECORDLOW][HI] = temps[0][HI];
    
    for (int x = 1; x < records; x++) {
        //find highest in the array
        if (temps[x][LOW] > temps[RECORDHI][LOW]) {
            temps[RECORDHI][LOW] = temps[x][LOW];
        }

        if (temps[x][HI] > temps[RECORDHI][HI]) {
            temps[RECORDHI][HI] = temps[x][HI];
        }
        //find lowest in array
        if (temps[x][LOW] < temps[RECORDLOW][LOW]) {
            temps[RECORDLOW][LOW] = temps[x][LOW];
        }

        if (temps[x][HI] < temps[RECORDLOW][HI]) {
            temps[RECORDLOW][HI] = temps[x][HI];
        }

    }
}
int readFile(string path) {
    ifstream fin;
    int day;
    fin.open(path);

    if (fin.fail()) {
        cout << path << " did not open, quitting" << endl;
        exit(1);
    }

    while (!fin.eof()) {
        records++;//eliminate the extra record 
        fin >> day >> temps[records][LOW] >> temps[records][HI];
    }

    fin.close();
    return records;
}