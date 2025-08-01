// GraphAdjList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph {
public:
    int numVertices;
    list<int>* adjLists;

    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjLists = new list<int>[numVertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int vertex : adjLists[i])
                cout << vertex << " ";
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adjLists;
    }
};

int main() {
    Graph g(10);
    vector<pair<int, int>> friends = {{0,1}, {2,3}, {3,4}, {5,6} };

    for (int i = 0; i < friends.size(); i++) {
        g.addEdge(friends[i].first, friends[i].second);
    }

    set<int> groups[10];
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < 10; i++) {
            if (groups[j].size() !=0 &&  
                (groups[j].find(friends[i].first) != groups[i].end() ||
                 groups[j].find(friends[i].second) != groups[i].end())
                ) 
            {
                groups[j].insert(friends[i].first);
                groups[j].insert(friends[i].second);
                break;
            }
            else if (groups[j].size() == 0) {
                groups[j].insert(friends[i].first);
                groups[j].insert(friends[i].second);
                break;
            }
        }
    }



    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);*/

    g.printGraph();

    for (int i = 0; i < 10; i++) {
        cout << endl;
        for (auto j = groups[i].begin(); j != groups[i].end(); j++) {
            cout << *j << " ";
        }
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
