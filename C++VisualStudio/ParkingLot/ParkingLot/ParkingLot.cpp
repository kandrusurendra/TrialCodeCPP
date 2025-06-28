// ParkingLot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class ParkingLot
{
public:
	ParkingLot(int capacity) : capacity(capacity), currentCount(0) {}
	bool parkCar() {
		if (currentCount < capacity) {
			currentCount++;
			return true; // Car parked successfully
		}
		return false; // Parking lot is full
	}
	bool removeCar() {
		if (currentCount > 0) {
			currentCount--;
			return true; // Car removed successfully
		}
		return false; // No cars to remove
	}
private:
	int capacity;        // Maximum number of cars that can be parked
	int currentCount;    // Current number of cars parked
};

int main()
{
	int capacity = 0;
    std::cout << "Parking Lot Program\n";
	std::cout << "Enter parking lot capacity: ";
	std::cin >> capacity;
	ParkingLot lot(capacity);

	while (true) {
		int choice;
		std::cout << "1. Park a car\n";
		std::cout << "2. Remove a car\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice == 1) {
			if (lot.parkCar()) {
				std::cout << "Car parked successfully.\n";
			}
			else {
				std::cout << "Parking lot is full.\n";
			}
		}
		else if (choice == 2) {
			if (lot.removeCar()) {
				std::cout << "Car removed successfully.\n";
			}
			else {
				std::cout << "No cars to remove.\n";
			}
		}
		else if (choice == 3) {
			break; // Exit the loop
		}
		else {
			std::cout << "Invalid choice, please try again.\n";
		}
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
