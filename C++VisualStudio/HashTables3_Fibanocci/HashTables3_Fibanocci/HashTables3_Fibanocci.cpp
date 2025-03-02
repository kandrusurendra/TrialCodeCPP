// HashTables3_Fibanocci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    unordered_map<int, int> fib;
    fib[0] = 1;
    fib[1] = 1;

    int num;
    cout << " enter the fibanocci item " << endl;
    cin >> num;

    for (int i = 2; i <= num; i++) {
        if (fib.count(i) == 0) {
            fib[i] = fib[i - 1] + fib[i - 2];
            cout << "Fib " << i << " is : " << fib[i] << endl;
        }
    }

    if (fib.count(num)) {
        cout << "Fib " << num << "is : " << fib[num];
    }
    else {
        cout << " cannot get it" << endl;
    }

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
