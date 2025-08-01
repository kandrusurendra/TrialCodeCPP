// Vector1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeIntoNewVector(vector<int>, vector<int>);

int main()
{
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = { 0,3,5,6 };

    //vec1.at(0) = 0;
    //vec1.push_back(10);
    //vec1.push_back(11);

    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << endl;
    }
    
    cout << "printing vec 2 data via iterator" << endl;

    auto it = vec2.begin();

    while (it != vec2.end()) {
        cout << it[0] << endl;
        it++;
    }
    std::cout << "Merge 2 vectors\n";

    //merge everything into one new vector
    vector<int> MergeResult = mergeIntoNewVector(vec1, vec2);

    for (int i = 0; i < MergeResult.size(); i++) {
        cout << MergeResult[i] << endl;
    }

    return 0;
}

vector<int> mergeIntoNewVector(vector<int> firstVector, vector<int> secondVector) {
   
    int firstVectorSize = firstVector.size();
    int secondVectorSize = secondVector.size();
    vector<int> finalVector;

    if (firstVectorSize == 0) return secondVector;
    if (secondVectorSize == 0) return firstVector;
    auto FirstIt = firstVector.begin();
    auto SecondIt = secondVector.begin();
    while (FirstIt != firstVector.end() && SecondIt != secondVector.end()) {
        if (FirstIt[0] == SecondIt[0]) {
            //If we want to discard the duplicates
            finalVector.push_back(FirstIt[0]);
            FirstIt++;
            SecondIt++;
        }else if (FirstIt[0] < SecondIt[0]) {
            finalVector.push_back(FirstIt[0]);
            FirstIt++;
        }
        else {
            finalVector.push_back(SecondIt[0]);
            SecondIt++;
        }
    }

    if (FirstIt == firstVector.end()) {
        //which means first Vector ended. There could be some more values in Second
        while (SecondIt != secondVector.end()) {
            finalVector.push_back(*SecondIt);
            SecondIt++;
        }
    }
    else {
        //similarly for second vector
        while (FirstIt != firstVector.end()) {
            finalVector.push_back(*FirstIt);
            FirstIt++;
        }
    }

    return finalVector;
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
