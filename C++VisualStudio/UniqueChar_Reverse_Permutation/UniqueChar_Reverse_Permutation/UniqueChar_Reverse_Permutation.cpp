// UniqueChar_Reverse_Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void testWhetherTheStringIsUnique()
{
    string testUnique;
    bool alphabet[26] = { false };
    bool isUnique = true;

    cout << "enter the string to check \n";
    cin >> testUnique;

    for (int i = 0; i < testUnique.length(); i++) {
        
        if (testUnique[i] == ' ') continue;

        int tmp = testUnique[i] - 'a';
        if (alphabet[tmp] == false) {
            alphabet[tmp] = true;
        }
        else {
            isUnique = false;
            cout << "characters are not unique" << endl;
            break;
        }
    }

    if (isUnique) cout << "characters are unique" << endl;

    return;
}

int reverseWord(char* word) {
    int length = 0;
    int i = 0;
    while (word[i] != ' ' && word[i] != 0) {
        i++;
        length++;
    }

    for (i = 0; i < length / 2; i++) {
        char tmp = word[i];
        word[i] = word[length - i - 1];
        word[length - i - 1] = tmp;
    }

    return length;
}

void reverseString() {
    string inputString;
    getline(cin, inputString);
    cout << "enter the string to reverse" << endl;
    //cin >> inputString;
    getline(cin,inputString);
    
    int length = inputString.size();

    cout << inputString << endl << length << endl;

    for (int i = 0; i < length/2; i++) {
        char tmp = inputString[i];
        inputString[i] = inputString[length-i-1];
        inputString[length - i - 1] = tmp;
    }

    cout << inputString << endl << length << endl;
    for (int i = 0; i < length; i++) {
        int idx = reverseWord(&inputString[i]);
        i += idx;
    }

    cout << inputString << endl << length << endl;
}

void StringPermutation()
{
    string FirstString;
    int firstStringChars[26] = {0};
    string SecondString;
    int secondStringChars[26] = {0};
    bool isPermutation = true;
    cout << "enter first string" << endl;
    cin >> FirstString;

    cout << "enter second string" << endl;
    cin >> SecondString;

    cout << FirstString << "  " << SecondString << endl;

    if (FirstString.length() == SecondString.length()) {
        for (int i = 0; i < FirstString.length(); i++) {
            firstStringChars[FirstString[i] - 'a']++;
        }

        for (int i = 0; i < SecondString.length(); i++) {
            secondStringChars[SecondString[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (secondStringChars[i] != firstStringChars[i]) {
                isPermutation = false;
                break;
            }
        }
    }
    else {
        isPermutation = false;
    }

    if (isPermutation) {
        cout << "Both Strings are permutation of each other" << endl;
    }
    else {
        cout << "Not a permutation " << endl;
    }
}
int main()
{
    cout << "1. testWhetherTheStringIsUnique" << endl;
    cout << "2. reverse string" << endl;
    cout << "3. String Permutation" << endl;
    int option = 0;
    cin >> option;
    cout << "  ";

    if (option == 1) testWhetherTheStringIsUnique();
    if (option == 2) reverseString();
    if (option == 3) StringPermutation();

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
