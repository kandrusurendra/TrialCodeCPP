// HashTables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>

// Function to clean and convert a word to lowercase
std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char ch : word) {
        if (std::isalnum(ch)) {
            cleaned += std::tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    std::ifstream file("sample.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> wordCount;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordCount[word]++;
            }
        }
    }

    file.close();

    // Display word frequencies
    for (const auto& entry : wordCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
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
