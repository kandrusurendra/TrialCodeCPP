// RangeCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <thread>
#include <Windows.h>
using namespace std;

int loop()
{
	for (int i = 0; i < 100; i++)
	{
		Sleep(1000);
		cout << i << endl;
	}
	return 0;
}
int main()
{
	unordered_map<string, int> mymap = { {"Suri", 1}, {"Neelima", 2}};
	for (auto& pair : mymap)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	//Checking thread functionality
	thread t(loop);

	t.detach();

	Sleep(5000); // Main thread sleeps for 5 seconds
	cout << "Main thread exiting" << endl;
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
