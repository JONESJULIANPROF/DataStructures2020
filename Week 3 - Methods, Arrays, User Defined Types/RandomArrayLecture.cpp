// RandomArrayLecture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>    //need to randomize the list
#define SIZE 1000
using namespace std;

//global variables - read by entire project
int x;  //used in the for loops
int numbers[SIZE];
double zscore[SIZE];

//prototypes
void fillArrayRand();
void headArray(int howMany = 10);
void fillArrayFile(string path);
void stats(int& mean, double& std);
void bins(int mean, double std);
void calcZscores(int mean, double std);

int main()
{
    //seed random number generator
    srand(time(0));
    int average;
    double std;

  //  fillArrayRand();
    fillArrayFile("c:\\data\\MOCK_DATA.csv");
   // int num = 20;
    
   // cout << "num = " << num << endl;
    stats(average, std);
    cout << "Average is " << average << endl;
    cout << "Std is " << std << endl;
   
    calcZscores(average, std);
    headArray();
    
    bins(average, std);
}

void calcZscores(int mean, double std) {
    for (x = 0; x < 1000; x++) {
        zscore[x] = (numbers[x] - mean) / std;
    }
}

void bins(int mean, double std) {
    int bincounts[5] = { 0,0,0,0,0 };   //accumulator array - use to count the bins
    double ranges[7];

    ranges[0] = mean - 3 * std;
    ranges[1] = mean - 2 * std;
    ranges[2] = mean - 1 * std;
    ranges[3] = mean;
    ranges[4] = mean + std;
    ranges[5] = mean + 2 * std;
    ranges[6] = mean + 3 * std;

    for (x = 0; x < SIZE; x++) {
        if (numbers[x] >= ranges[0] && numbers[x] < ranges[1]) {
            bincounts[0] ++;
        }
        else if (numbers[x] >= ranges[1] && numbers[x] < ranges[2]) {
            bincounts[1] ++;
        }
        else if (numbers[x] >= ranges[2] && numbers[x] < ranges[4]) {
            bincounts[2] ++;
        }
        else if (numbers[x] >= ranges[4] && numbers[x] < ranges[5]) {
            bincounts[3] ++;
        }
        else if (numbers[x] >= ranges[5] && numbers[x] < ranges[6]) {
            bincounts[4] ++;
        }
        else {
            //do nothing
        }   
    }//end of for loop
    for (x = 0; x < 7; x++) {
        cout << "Range value " << ranges[x] << endl;
    }
    cout << "-----------" << endl;
    for (x = 0; x < 5; x++) {
        cout << "Bin " << x << " has " << bincounts[x] << endl;
    }
}

void stats(int& mean, double& std) {
    int total = 0;
    //average
    for (x = 0; x < SIZE; x++) {
        total += numbers[x];
    }
    mean = total / SIZE;

    //standard deviation
    total = 0;
    for (x = 0; x < SIZE; x++) {
        total += pow(numbers[x] - mean, 2);
    }
    std = sqrt(total / (SIZE - 1.0));


}

void fillArrayFile(string path) {
    int index = 0;
    ifstream fin;
    fin.open(path);
    if (fin.fail()) {
        cout << path << " did not open, quitting\n";
        exit(1);
    }
    while (!fin.eof()) {
        fin >> numbers[index];
        index++;
    }
    fin.close();
}

void headArray(int howMany) {
    for (x = 0; x < howMany; x++) {
        cout << x << " : " << numbers[x] << " z-score " << zscore[x] << endl;
    }
   
}

void fillArrayRand() {
    //rand() - returns a number between 1 and 65,535
    //var = rand() % yourLimit + 1
    for (x = 0; x < SIZE; x++) {
        numbers[x] = rand() % 100 + 1;
    }
}