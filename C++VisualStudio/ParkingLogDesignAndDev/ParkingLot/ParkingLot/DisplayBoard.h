#pragma once
#include<iostream>

using namespace std;

enum DisplayStatus {
	AVAILABLE = 0,
	FULL = 1
};

class DisplayBoard
{
	static int boardCount = 0;
	int ID;
	DisplayStatus status;

	DisplayBoard() {
		status = AVAILABLE;
		ID = boardCount++;
	}

public:
	void setStatus(enum DisplayStatus aStatus) {
		status = aStatus;
	}

	DisplayStatus getStatus() {
		return status;
	}
};

