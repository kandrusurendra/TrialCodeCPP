#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
void testUnorderedSet()
{   
    unordered_map<long, long> length1, length2, length3;
    vector<long> arr = {1,2,2,4};
    long r = 2;
    for (long x : arr) {
        auto it1 = length1.find(x/r), it2 = length2.find(x/r);
        if (x % r == 0 and it2 != length2.end()) length3[x] = length3[x] + it2->second;
        if (x % r == 0 and it1 != length1.end()) length2[x] = length2[x] + it1->second;
        ++length1[x];
    }
    long triplets = 0;
    for (auto p : length3) triplets = triplets + p.second;

    cout << "triplets : " << triplets << endl;
}

void testUnorderedSet2()
{
    unordered_map<long, long> map1;
    map1[1] = 2;
    map1[2] = 4;
    map1.insert({3,9});

    for(auto i : map1){
        cout << "map item " << i.first << "  " << i.second << endl;
    }

    cout << "accessing via iterator" << endl;

    for(auto it=map1.begin(); it!=map1.end(); it++){
        cout << "map item iterator " << it->first << "  " << it->second << endl;
    }

}

void testUnorderedSet3()
{
    unordered_map<string,int> map2;
    map2["a"] = 1;
    map2["b"] = 2;

    for(auto it=map2.begin(); it!=map2.end();it++){
        cout << "map triple "<< it->first << "  " << it->second << endl;         
    }
}