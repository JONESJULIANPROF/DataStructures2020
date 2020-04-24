//// Lecture1Rotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//    string line;
//    string encrypted;
//    ifstream fin;
//    ofstream fout;
//    int rotation = 5;
//    fin.open("frost.txt");//open the file
//    fout.open("frost.enc");
//    if (fin.fail()) {//ensure file is opened
//        cout << "Could not open the file. Quitting. Have a nice day:)";
//        return 1;//error
//        //fix or die
//    }//file fails
//
//    if (fout.fail()) {//ensure file is opened
//        cout << "Could not open the output file. Quitting. Have a nice day:)";
//        return 2;//error
//        //fix or die
//    }//file fails
//
//    //process the file
//
//    while (getline(fin, line)) {
//        //cout << line << endl;
//        //encrypt each char in the line
//        encrypted = ""; //reset the string to empty
//        for (int c = 0; c < line.length(); c++) {
//            encrypted += line.at(c) + rotation;
//        }
//        fout << encrypted << endl;
//        //cout << encrypted << endl;
//    }
//
//   // cout << "File is opened" << endl;
//    fin.close();//close the file
//    fout.close();
//
//}
//
