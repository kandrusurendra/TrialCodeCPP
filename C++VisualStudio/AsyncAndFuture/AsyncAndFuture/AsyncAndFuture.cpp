// AsyncAndFuture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <future>

using namespace std;

float divide(int a, int b) {

    cout << "In Divide " << endl;

    if (b == 0) throw invalid_argument("div by zero");

    return (float)a / b;

}
int main()
{
    future<float> result = async(launch::async, divide, 5,4);

    cout << "output " << result.get() << endl;

    //deferred indicates thread will not launch till get()/wait() is called
    future<float> newRes = async(launch::deferred, divide, 5, 0); 

    cout << "did not call get yet" << endl;
    try {
        cout << "calling now \n";
        cout << newRes.get() << endl;
    } 
    catch(exception e) {
        cout << "Caught exception " << e.what() << endl;
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
