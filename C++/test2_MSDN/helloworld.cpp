#include <iostream>
#include <vector>
#include <string>
#include "templateTest.h"
using namespace std;

extern void testVector();
extern void testList();
extern void testUnorderedSet();
extern void testUnorderedSet2();
extern void testUnorderedSet3();

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

   // cout << "sum of all " << sum<int>(10, 20) << endl;
   // cout << "sum of Folding " << sumN(10, 20, 30, 40, 50) << endl;
   // cout << "All true : " << allTrue(true, false, true) << endl;
   // cout << "All true 2: " << allTrue(true, true, true) << endl;

    //testVector();
    //testList();
    testUnorderedSet();
    //testUnorderedSet2();
    //testUnorderedSet3();
}


