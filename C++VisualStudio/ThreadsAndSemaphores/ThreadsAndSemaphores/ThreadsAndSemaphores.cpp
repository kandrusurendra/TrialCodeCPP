// ThreadsAndSemaphores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <windows.h>
#include <chrono>

using namespace std;

mutex mtx;
int shared_memory = 1;
void thread1_function() {
    int count = 5;

    while (count--) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            shared_memory++;
        }
        cout << "sleep for 1 sec - thread1\n";
        Sleep(1);
    }
    cout << "exiting thread1\n";
}

void thread2_function() {
    int count = 5;
    while (count--) {
        
        { 
            std::lock_guard<std::mutex> lock(mtx);
            shared_memory *= 2;
        }
        cout << "sleep for 1 sec - thread 2\n";
        Sleep(1);
    }
    cout << "exiting thread2\n";
}

int main()
{
    std::thread t1(thread1_function);
    std::thread t2(thread2_function);

    t1.join(); 
    cout << "thread 1 joined" << endl;
    t2.join();
    cout << "thread 2 joined" << endl;

    cout << "Shared memory : " << shared_memory << endl;
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
