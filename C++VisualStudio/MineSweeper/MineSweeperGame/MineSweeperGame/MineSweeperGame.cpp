// MineSweeperGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    srand(time(0));
    //for (int i = 0; i < 10; i++) {
    //    cout << "Random number " << i << ": " << rand() <<endl;
    //}

    const int Rows = 4;
    const int Columns = 4;

    int Mine[Rows][Columns] = { 0 };
    //For 4x4 
    int bombPlacement[4][2] = 
            {   0,0,
                1,0,
                2,2,
                0,3
            };
    
    
    int numBombs = sizeof(bombPlacement) / sizeof(bombPlacement[0]);
    cout << "numBombs : " << numBombs << endl;
    
    for (int i = 0; i < numBombs; i++) {
        int Xindex = bombPlacement[i][0];
        int Yindex = bombPlacement[i][1];

        //Update the blocks on the corners

        if (Xindex == 0) {
            if (Yindex == 0) {
                //Top left
                Mine[Xindex + 1][Yindex + 1] += 1;
                Mine[Xindex][Yindex + 1] += 1;
                Mine[Xindex + 1][Yindex] += 1;
            }
            else if (Yindex == Columns-1){
                //bottom left
                Mine[Xindex + 1][Yindex - 1] += 1;
                Mine[Xindex][Yindex - 1] += 1;
                Mine[Xindex + 1][Yindex] += 1;
            }
            else {
                Mine[Xindex + 1][Yindex + 1] += 1;
                Mine[Xindex + 1][Yindex - 1] += 1;
                Mine[Xindex][Yindex - 1] += 1;
                Mine[Xindex][Yindex + 1] += 1;
                Mine[Xindex + 1][Yindex] += 1;
            }
        }
        else if (Xindex == Rows-1) {
            if (Yindex == 0) {
                //Top right
                Mine[Xindex - 1][Yindex + 1] += 1;
                Mine[Xindex][Yindex + 1] += 1;
                Mine[Xindex - 1][Yindex] += 1;
            }
            else if (Yindex == Columns-1) {
                //bottom right
                Mine[Xindex - 1][Yindex - 1] += 1;
                Mine[Xindex][Yindex - 1] += 1;
                Mine[Xindex - 1][Yindex] += 1;
            }
            else {
                Mine[Xindex - 1][Yindex - 1] += 1;
                Mine[Xindex - 1][Yindex + 1] += 1;
                Mine[Xindex][Yindex - 1] += 1;
                Mine[Xindex][Yindex + 1] += 1;
                Mine[Xindex - 1][Yindex] += 1;
            }
        }
        else {
            // Old update =======================    
            Mine[Xindex - 1][Yindex - 1] += 1;
            Mine[Xindex - 1][Yindex + 1] += 1;
            Mine[Xindex + 1][Yindex + 1] += 1;
            Mine[Xindex + 1][Yindex - 1] += 1;


            Mine[Xindex][Yindex - 1] += 1;
            Mine[Xindex][Yindex + 1] += 1;
            Mine[Xindex - 1][Yindex] += 1;
            Mine[Xindex + 1][Yindex] += 1;
        }
    }

    for (int i = 0; i < numBombs; i++) {
        int Xindex = bombPlacement[i][0];
        int Yindex = bombPlacement[i][1];
        Mine[Xindex][Yindex] = 9;
    }

    //Print the array
    for (int j = 0; j < 4; j++) {
        cout << endl;
        for (int i = 0; i < 4; i++) {
            cout << Mine[j][i] << "  ";
        }
    }
    cout << endl;
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
