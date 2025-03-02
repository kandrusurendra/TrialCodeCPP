// MutexAndLock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>
using namespace std;

mutex mtx;
mutex mtx2;
void thread1() {
    Sleep(1000);
    lock_guard<mutex> lock(mtx);
    cout << "in Thread 1" << endl;
}
void thread2() {

    lock_guard<mutex> lock(mtx);
    cout << "in Thread 2" << endl;
}
void thread3(){
    //lock 2 thread simultaneously
    lock(mtx, mtx2);
    lock_guard<mutex> lg1(mtx, adopt_lock);
    lock_guard<mutex> lg2(mtx2, adopt_lock);
    cout << "thread 3, multiple mtx locks" << endl;
}

void thread4() {
    lock(mtx, mtx2);
    cout << "thread 4, multiple mtx locks" << endl;
    mtx.unlock();
    mtx2.unlock();
}
int main()
{
    thread t1(thread1);
    thread t2(thread2);
    thread t3(thread3);
    thread t4(thread4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << "exiting from main " << endl;

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
