// VectorOfVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "enter the size of the array \n";
    int sizeOfMatrix = 0;
    cin >> sizeOfMatrix;

    vector<vector<int>> arr(sizeOfMatrix);

    for (int i = 0; i < sizeOfMatrix; i++) {
        cout << endl;
        arr[i].resize(sizeOfMatrix);
        for (int j = 0; j < sizeOfMatrix; j++) {
            arr[i][j] = i * sizeOfMatrix + j;
            cout << arr[i][j] << "  ";
        }
    }

    cout << "\n create new array, enter the size \n";
    int newSizeOfMatrix = 0;
    cin >> newSizeOfMatrix;
    arr.resize(newSizeOfMatrix);
    for (int i = 0; i < newSizeOfMatrix; i++) {
        cout << endl;
        arr[i].resize(newSizeOfMatrix);
        for (int j = 0; j < newSizeOfMatrix; j++) {
            //arr[i][j] = i * newSizeOfMatrix + j;
            cout << arr[i][j] << "  ";
        }
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
