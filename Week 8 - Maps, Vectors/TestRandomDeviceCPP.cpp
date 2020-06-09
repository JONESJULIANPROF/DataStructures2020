// TestRandomDeviceCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <map>
//https://en.cppreference.com/w/cpp/numeric/random/random_device

using namespace std;

int main()
{
    random_device rnd;
    uniform_int_distribution<int> distro(1, 6);
    map <int, int> counter;
    cout << "Entropy " << rnd.entropy() << endl;
    for (int x = 0; x < 100000; x++) {
        //cout << distro(rnd) << endl;
        counter[distro(rnd)] ++;
    }
    int perfect = 100000 / 6;
    int totError = 0;
    cout << "Perfect is " << perfect << endl;
    for (int x = 1; x <= 6; x++) {
        totError += abs(counter[x] - perfect);
        cout << x << " rolled " << counter[x] << " error " << abs(counter[x] - perfect) << endl;
    }
    cout << "avg error " << totError / 6;
    cout << "\nError percent " << (totError / 6.0) / perfect;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
