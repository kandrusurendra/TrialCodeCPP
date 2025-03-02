#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
	string registrationNumber;

public:
	void setRegistrationNumber(string str) {
		registrationNumber = str;
	}

	string getRegistrationNumber() {
		return registrationNumber;
	}
};



