// LambdaImprovements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class testLambda {
public:
    int Value = 10;

    int getValue()
    {
        auto LBD = [this]() -> int {
            return Value;
            };

        return LBD();
    }
};
int main()
{
    vector<int> x = {1,2,3, 5, 5};
    auto lambda = [v = move(x)]() -> float {
        return v.size();
        };

    cout << lambda() << endl;

    auto lambda1 = [&]() -> float {
        return x.size();
        };

    cout << lambda1() << endl;

    testLambda tmp;
    cout << "TestLambda getValue " << tmp.getValue() << endl;

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
