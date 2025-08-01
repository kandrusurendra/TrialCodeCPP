// ThreeWayComparison.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct point {
    int a, b;
    strong_ordering operator<=>(const point& other) const = default;
};

auto compare(point& x, point &y){
    auto result = true;
    if (result = x < y) {
        cout << "x < y \n";
    }
    else if (result = x == y) {
        cout << "x==y \n";
    }
    else if(result = x > y) {
        cout << " x > y \n";
    }
    else {
        cout << "others" << endl;
    }

    cout << result << endl;

    return result;
}
int main()
{
    point x{1,2};
    point y{1,2};
    point z{3,4};
    point p{ 0,0 };
    point q{0,4};

    compare(x,y);
    compare(x,z);
    compare(x,p);
    compare(x,q);

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
