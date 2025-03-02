// MaxNumberWithoutComparisonOrIfElse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
using namespace std;

int max(int a, int b) {
    cout << "((a - b) >> (sizeof(int) * 8 - 1)) = " << bitset<32>(((a - b) >> (sizeof(int) * 8 - 1))) << endl;
    cout << "((a - b) & ((a - b) >> (sizeof(int) * 8 - 1))) = " << bitset<32>((a - b) & ((a - b) >> (sizeof(int) * 8 - 1))) << endl;

    return a - ((a - b) & ((a - b) >> (sizeof(int) * 8 - 1)));
}

int main() {
    int num1 = 3;
    int num2 = 6;
    int result = max(num1, num2);
    cout << "The maximum of " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
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
