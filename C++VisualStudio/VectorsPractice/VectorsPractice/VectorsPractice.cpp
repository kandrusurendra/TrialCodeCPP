// VectorsPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

//reduce function using std::vector
// This function take input vector and add num elements mentioned and output new vector
// If the size of the input vector is less than reduceNumElements, it returns an empty vector.
std::vector<int> reduceFunction(std::vector<int> input, int reduceNumElements) {
	std::vector<int> output; // Declare an output vector
	if (input.size() < reduceNumElements) {
		return output; // Return empty vector if input size is less than reduceNumElements
	}
	int sum = 0;
	for (int i = 0; i < input.size() - reduceNumElements + 1; i++) {
		// Loop through the input vector until reduceNumElements is reached
		sum = 0; // Initialize sum variable
		for (int j = 0; j < reduceNumElements; j++) {
			sum += input[i+j]; // Add elements to sum
		}
		output.push_back(sum); // Add elements to output vector
	}
	return output; // Return the output vector
}
int main()
{
    std::cout << "vectors practice\n";
	std::vector<int> numbers = {1,2,3,4, 5, 6, 7, 8}; // Declare a vector of integers
	// Add elements to the vector
	numbers.push_back(9); // Add 9 to the end of the vector
	numbers.push_back(10); // Add 10 to the end of the vector
	// Print the elements of the vector
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " "; // Access each element using the index
	}
	numbers.pop_back(); // Remove the last element (10)
	numbers.pop_back(); // Remove the last element (9)
	numbers.pop_back(); // Remove the last element (8)
	std::cout << "\nAfter popping back:\n";
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " "; // Print the elements again
	}

	std::cout << "\n size of vector \n" << numbers.size() << std::endl; // Output the size of the vector
	std::cout << "\n capacity of vector \n" << numbers.capacity() << std::endl; // Output the capacity of the vector
	//output contents with range-based for loop
	std::cout << "\nContents of the vector using range-based for loop:\n";
	for (int i : numbers) {
		std::cout << i << " "; // Range-based for loop to print elements
	}

	//add edge elements keep them in new vector
	std::vector<int> edgeNumbers; // Declare a new vector with edge elements
	std::cout << "\nadd Edge elements of the vector:\n";
	for (int i = 0; i < (numbers.size()/2)+1; i++) {
		edgeNumbers.push_back(numbers[i]+numbers[numbers.size()-i-1]); // Add the first half of elements to edgeNumbers
		std::cout << "\n" << edgeNumbers[i] << std::endl; // Print the elements of edgeNumbers
	}
	 //call reduce function
	std::vector<int> reducedVector = reduceFunction(numbers, 3); // Store the result of the reduce function
	std::cout << "\nReduced vector:\n";
	for (int i = 0; i < reducedVector.size(); i++) {
		std::cout << reducedVector[i] << " "; // Print the elements of the reduced vector
	}
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
