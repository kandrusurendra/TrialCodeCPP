// TestBigEndianLittleEndian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int i = 0x1;
    char* ch = (char*) & i;
    if (*ch == 1) {
        cout << "little endian" << endl;
    }
    else {
        cout << "big Endian" << endl;
    }

    for (int j = 0; j < 4; j++) {
        cout << static_cast<void*>(ch) << "  " << (int)*ch << endl;
        ch++;
    }

    int a[2][2];
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            cout << &a[p][q] << endl;
        }
    }

    int x = 0b1100;
    int y = 0b1010;
    cout << "XOR operation : 0b1100 ^ 0b1010  =  " << (x ^ y) << endl;
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
