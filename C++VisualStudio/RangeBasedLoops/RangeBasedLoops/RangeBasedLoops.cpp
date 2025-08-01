// RangeBasedLoops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    vector<int> values = {1,2,3,4,5};

    for (auto num : values) { //access by value
        cout << num << endl;
    }

    vector<int> squares;
    int i = 0;
    for (auto& num : values) { //access by reference
        num = num * num; //modifies local element
        squares.push_back(num);
     }

    for (auto num : squares) {
        cout << num << endl;
    }
    
    map<int, string> table = { {1, "one"}, {2, "two"}, {3,"three"} };

    for (auto& pair : table) { //access by complex data structure
        cout << pair.first << "   " << pair.second << endl;
    }


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
