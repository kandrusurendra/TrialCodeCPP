// MineSweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int updateNeighbourCellValue(int** mineField, int nRow, int nColumn, int minFieldRows, int mineFieldColumns) {
	
	if (nRow < 0 || nRow >= minFieldRows || nColumn < 0 || nColumn >= mineFieldColumns) {
		return -1; // Invalid cell position
	}

	if (mineField[nRow][nColumn] == -1)
	{
		std::cout << "Mine is present at (" << nRow << ", " << nColumn << "). Cannot update value.\n";
		return -1; // Cannot update a mine cell
	}



	mineField[nRow][nColumn]++; // Increment the count of mines around this cell

	return 0;
}
int setMineNeibhbourCount(int** mineField, int mineRow, int mineColumn, int mineFieldRows, int mineFieldColumns) {
	// This function is intended to set the count of mines in the neighboring cells.
	// However, it is not implemented in this code snippet.
	// You can implement the logic to count mines around each cell here.
	if (mineField == nullptr)
	{
		std::cout << "Minefield is not initialized.\n";
		return -1;
	}

	if (mineRow < 0 || mineColumn < 0 || mineFieldRows <= 0 || mineFieldColumns <= 0) {
		std::cout << "Invalid mine position or minefield dimensions.\n";
		return -1;
	}

	if (mineRow >= mineFieldRows || mineColumn >= mineFieldColumns) {
		std::cout << "Mine position out of bounds.\n";
		return -1;
	}

	// Check all 8 possible directions around the mine
	int directions[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1},          {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};
	for (int i = 0; i < 8; ++i) {
		int newRow = mineRow + directions[i][0];
		int newCol = mineColumn + directions[i][1];
		updateNeighbourCellValue(mineField, newRow, newCol, mineFieldRows, mineFieldColumns);
	}

	return 0; // Placeholder return value
}

int main()
{
	int rows, columns;
    std::cout << "MineSweeper\n";
	std::cout << "Welcome to the MineSweeper game!\n";
	std::cout << "Enter the number of rows and columns for the minefield:\n";
	std::cout << "Rows: ";
	std::cin >> rows;
	std::cout << "Columns: ";
	std::cin >> columns;

	if (rows <= 0 || columns <= 0) {
		std::cout << "Invalid input. Rows and columns must be positive integers.\n";
		return 1;
	}
	// Initialize the minefield with zeros
	int** minefield = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		minefield[i] = new int[columns]();
	}
	// Display the initialized minefield
	std::cout << "Initialized Minefield:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << minefield[i][j] << " ";
		}
		std::cout << "\n";
	}

	//Enter mines in the minefield
	std::cout << "Enter the mine positions (row and column) as pairs of integers, separated by spaces. Enter -1 -1 to stop:\n";
	int mineRow, mineCol;
	while (true) {
		std::cin >> mineRow >> mineCol;
		if (mineRow == -1 && mineCol == -1) {
			break; // Stop input when -1 -1 is entered
		}
		if (mineRow < 0 || mineRow >= rows || mineCol < 0 || mineCol >= columns) {
			std::cout << "Invalid position. Please enter valid row and column indices.\n";
			continue;
		}
		minefield[mineRow][mineCol] = -1; // Place a mine
	}

	// Display the minefield with mines
	std::cout << "mined Minefield:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << minefield[i][j] << " ";
		}
		std::cout << "\n";
	}

	//Count mines
	int mineCount = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (minefield[i][j] == -1) {
				mineCount++;
				setMineNeibhbourCount(minefield, i, j, rows, columns);
			}
		}
	}

	// Display the minefield with mines
	std::cout << "Neighbours updated in Minefield:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << minefield[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "Total number of mines: " << mineCount << "\n";
	
	// Clean up memory
	for (int i = 0; i < rows; ++i) {
		delete[] minefield[i];
	}
	delete[] minefield;
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
