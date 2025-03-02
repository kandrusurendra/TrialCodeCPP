// LambaExpCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;

	auto add = [](int a, int b) {
		return a + b;
		};
	auto subtract = [=]() {
		return a - b;
		};
	auto multiply = [&]() {
		return a * b;
		};
	auto divide = [&a, b]() -> float {
		return (float)a / b;
		};

	float c = 0.0;
	cout << add(a, b) << endl;
	cout << subtract() << endl;
	cout << multiply() << endl;
	cout << (c=divide()) << endl;

	auto addRef = [&]() {
		return c *= a + b;
		};

	cout << "AddRef" << addRef() << endl;

	auto multiplyRef = [=, &b]() {
		return b = b * a * c;
		};

	cout << "MultiplyREf" << multiplyRef() << endl;

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
