// Rotate2DArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum rotation {
    R_0,
    R_90,
    R_180,
    R_270
};

enum result {
    E_SUCCESS = 1,
    E_FAIL = 0,
    E_INVALID_BUFFER = -1,
    E_INVALID_PARAM = -2
};

int rotate(int* FrameBuffer, int width, int height, int* outputBuffer, enum rotation rotate)
{
    if (FrameBuffer == NULL) return E_INVALID_BUFFER;
    if (outputBuffer == NULL) return E_INVALID_BUFFER;
    if (width == 0 && height == 0) return E_INVALID_PARAM;
    if (rotate < R_0 || rotate > R_270) return E_INVALID_PARAM;

    if (rotate == R_0) memcpy(outputBuffer, FrameBuffer, width * height * sizeof(int));

    if (rotate == R_90) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                //output[j][height-1-i] = FrameBuffer[i][j];
                outputBuffer[j * height + (height - 1 - i)] = FrameBuffer[i * width + j];
            }
        }
    }

    return E_SUCCESS;
}

void print2DArray(int* test, int width, int height) {
    for (int i = 0; i < height; i++) {
        cout << endl;
        for (int j = 0; j < width; j++) {
            cout << test[i*width+j] << "  ";
        }
    }
}
int main()
{
    int a[3][2] = { {1,2},
                    {3,4},
                    {5,6} };

    int b[3][2] = { 0 };

    print2DArray((int*)a,3,2);

    rotate((int*)a,3,2,(int*)b, R_90);

    print2DArray((int*)b, 2, 3);
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
