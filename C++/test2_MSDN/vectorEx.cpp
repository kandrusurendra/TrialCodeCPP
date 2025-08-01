#include <iostream>
#include <string>
#include <vector>

using namespace std;

void testVector(){
    std::vector<int> vec1 = {1,2,3,4,5};
    vec1.push_back(6);
    cout << "printing vectors" << endl;
    for(auto it=vec1.begin(); it!=vec1.end();it++){
        cout << *it << endl;
    }
}
