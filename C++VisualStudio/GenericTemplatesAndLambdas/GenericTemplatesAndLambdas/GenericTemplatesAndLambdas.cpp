// GenericTemplatesAndLambdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <typename T>
auto square(T a) {
    return a * a;
}

auto add = [](auto a, auto b) {return a + b; };

int main()
{
    cout << square(5) << endl;
    cout << square(4.5) << endl;
    cout << square(5.1111) << endl;

    cout << add(1, 3) << endl;
    cout << add(1.0, 3.5) << endl;
    cout << add(1.12312312312312313, 3.13131231232131313) << endl;
    //cout << add("Hello ", "World") << endl; //Does not work

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
