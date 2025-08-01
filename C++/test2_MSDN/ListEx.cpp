#include <iostream>
#include <list>

using namespace std;

void testList(){
    std::list<int> list1 = {100, 200, 300};
    list1.push_front(500);
    cout << "printing list" << endl;
    for(auto at = list1.begin(); at != list1.end(); at++){
        cout << *at << endl;
    }
}
