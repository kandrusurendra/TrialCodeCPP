// FindNegativeNumbersSorted2DArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int array1[4][4] = { {-3,-1,-4,3},
                    {-2,0,6,7},
                    {-1,9,10,11},
                    {12,13,14,15}};
int main()
{
    std::cout << "Check array\n" <<std::endl;
    for (int i = 0; i < 16; i++) {
        cout << array1[i / 4][i % 4] << endl;
    }

    std::cout << "check num negative numbers" << endl;
    unsigned int count = 0;
    for (int i = 3, j=0; i >= 0 && j < 4; i--) {
        if (array1[j][i] < 0) {
            count = count + i + 1;
            j++;
            i++;
        }
    }

    cout << "Num Neg = " << count << endl;
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
