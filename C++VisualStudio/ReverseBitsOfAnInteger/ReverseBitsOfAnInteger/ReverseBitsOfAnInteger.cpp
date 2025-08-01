// ReverseBitsOfAnInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int inputNum = 0;
    cout << "enter input number \n";
    cin >> inputNum;
    cout << bitset<32>(inputNum) << endl;
    int finalOutput = 0;
    for (int i = 0; i < sizeof(int)*8; i++) {
        int mask = 1 << i;
        int numBit = (inputNum & mask) >> i;
        finalOutput |= numBit << (sizeof(int)*8 - 1 - i);
    }

    cout << "final output \n" << bitset<32>(finalOutput) << endl;
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
