// TrianglePrinting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void printTriangle(int depth)
{
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < depth-i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

template <typename T>
requires is_arithmetic_v<T>
T sum(T a, T b)
{
	return a + b;
}


int main()
{
	int depth;
    cout << "enter Depth of triangle\n";
	cin >> depth;

	printTriangle(depth);

	cout << sum(1, 2) << endl;
	cout << sum(1.1, 2.2) << endl;
	cout << sum(1.1f, 2.2f) << endl;
	//count << sum(1.1, 2) << endl;

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
