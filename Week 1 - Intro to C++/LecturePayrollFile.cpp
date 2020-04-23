/*
read a input file with multiple lines
write out a file with multiple line
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double hours, hourly, pay;
    string name;
    ifstream fin;   //input
    ofstream fout;  //output

    fin.open("payroll.txt");
    fout.open("payrollOutput.txt");//file is created

    //check that file opened
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Cannot open a file " << endl;
        cerr << "weasel" << endl;
  

        fin.close();
        fout.close();
        return 1;
    }

    while (!fin.eof()) {
        //run 0 to infinite times
        //test before reading to check for empty file
        fin >> name >> hours >> hourly;
        pay = hours * hourly;
        fout << name << " " << pay << endl;
    }

    fin.close();
    fout.close();//file is written to disk and conmtent are saved
    return 0;   //c++ will eventually yell at you for not returning everywhere
}

