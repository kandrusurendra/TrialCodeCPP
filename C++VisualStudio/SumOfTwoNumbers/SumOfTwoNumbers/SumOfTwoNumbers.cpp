// SumOfTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using namespace std;

int numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

int main()
{
    size_t size = sizeof(numbers)/sizeof(numbers[0]);
    cout << "size of array : " << size << endl;

    int sum = 0;
    cout << "sum to check: " << endl;
    cin >> sum;

    bool found = false;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        int valueToCheck = sum - numbers[i];
        for (int j = i + 1; j < size; j++) {
            if (valueToCheck == numbers[j]) {
            //if (sum == numbers[i] + numbers[j]) {
                found = true;
                cout << "indexs: " << i << "  " << j << endl;
                cout << "Values: " << numbers[i] << "  " << numbers[j] << endl;
                //break;
            }
        }
        //if (found == true) break;
    }
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << "timetaken : "<< microseconds << endl;

    if (found == false) cout << " pair of number for numbers is not found" << endl;

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
