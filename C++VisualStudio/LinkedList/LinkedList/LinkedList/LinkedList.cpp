// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {

public:
    Node* pHead;

    LinkedList() {
        pHead = NULL;
    }

    ~LinkedList() {
        Node* tmpPtr = nullptr;
        while (pHead != nullptr) {
            tmpPtr = pHead;
            pHead = pHead->pNext;
            delete tmpPtr;
        }
    }

    void insertData(int data) {
        if (pHead == nullptr) {
            Node* ptr = new Node(data);
            pHead = ptr;
            return;
        }

        Node* tmpPtr = pHead;
        while (tmpPtr->pNext != nullptr) {
            tmpPtr = tmpPtr->pNext;
        }

        tmpPtr->pNext = new Node(data);
    }

    int deleteData(int data) {
        if (pHead == nullptr) return -1;
        
        if (pHead->data == data) {
            if (pHead->pNext == nullptr) {
                delete pHead;
                pHead = nullptr;
                return 0;
            }

            Node* tmpPtr = pHead;
            pHead = pHead->pNext;
            delete tmpPtr;

            return 0;
        }

        Node* tmpPtr = pHead->pNext;
        Node* prevPtr = pHead;
        while (tmpPtr != nullptr) {
            if (tmpPtr->data == data) {
                Node* bkp = tmpPtr;
                prevPtr->pNext = tmpPtr->pNext;
                delete bkp;
                return 0;
            }
            else {
                prevPtr = tmpPtr;
                tmpPtr = tmpPtr->pNext;
            }
        }

        return -1;
    }

    int findData(int data) {
        if (pHead == nullptr) return -1;
        Node* tmpPtr = pHead;
        while (tmpPtr != nullptr) {
            if (data == tmpPtr->data) return 0;
            tmpPtr = tmpPtr->pNext;
        }

        return -1;
    }

    void PrintLinkedList() {
        cout << "printing linked list" << endl;
        if (pHead == nullptr) {
            cout << "nothing to print" << endl;
        }

        Node* tmpPrintPtr = pHead;
        while (tmpPrintPtr != nullptr) {
            cout << tmpPrintPtr->data << endl;
            tmpPrintPtr = tmpPrintPtr->pNext;
        }
    }

};

void RunSinglyLinkedListProgram() {

    std::cout << "Linked List Program\n";
    unsigned int option = 0;
    bool exit = false;

    LinkedList myLL;// = new LinkedList();

    while (1) {
        cout << "Insert Data : 1" << endl;
        cout << "Delete Data: 2" << endl;
        cout << "Find data: 3" << endl;
        cout << "Print Linked List: 4" << endl;
        cout << "enter option : ";
        cin >> option;

        int dataToInsert = 0;
        int dataToDelete = 0;
        int dataToFind = 0;
        switch (option) {
        case 1:
            cout << endl << "Give data to insert " << endl;
            cin >> dataToInsert;
            myLL.insertData(dataToInsert);
            break;
        case 2:
            cout << endl << "Give data to delete" << endl;
            cin >> dataToDelete;
            if (-1 == myLL.deleteData(dataToDelete)) {
                cout << "could not find data" << endl;
            }
            break;
        case 3:
            cout << endl << "Give data to find " << endl;
            cin >> dataToFind;
            if (-1 == myLL.findData(dataToFind)) {
                cout << "Data not present" << endl;
            }
            else {
                cout << "Found the data" << endl;
            }
            break;
        case 4:
            myLL.PrintLinkedList();
            break;
        default:
            cout << "exiting" <<endl;
            exit = true;
        }

        if (exit) break;
    }
    return;
}

//Double Linked List implementation
class DoublyLinkedList
{
    DoubleLinkedListNode* pHead;
public:
    DoublyLinkedList()
    {
        pHead = nullptr;
    }

    ~DoublyLinkedList()
    {
        while (pHead != nullptr) {
            DoubleLinkedListNode* tmpPtr = pHead;
            pHead = tmpPtr->pNext;
            if (pHead != nullptr) {
                pHead->pPrev = nullptr;
            }            

            delete tmpPtr;
            tmpPtr = nullptr;
        }
    }

    void insertData(int aData) {
        DoubleLinkedListNode* tmpPtr = new DoubleLinkedListNode(aData);
        if (tmpPtr == nullptr) {
            cout << "Unable to insert , no Memory" << endl;
            return;
        }

        if (pHead == nullptr) {
            pHead = tmpPtr;
        }
        else {
            tmpPtr->pNext = pHead;
            pHead->pPrev = tmpPtr;
            pHead = tmpPtr;
        }
    }

    void deleteData(int aData) {
        if (pHead == nullptr) {
            cout << "Nothing to delete" << endl;
            return;
        }

        if (pHead->data == aData) {
            if (pHead->pNext == nullptr) {
                delete pHead;
                pHead = nullptr;
                cout << "deleted" << endl;
                return;
            }

            DoubleLinkedListNode* tmpPtr = pHead;
            pHead = pHead->pNext;
            pHead->pPrev = nullptr;
            delete tmpPtr;
            cout << "deleted" << endl;
            return;
        }

        DoubleLinkedListNode* tmpPtr = pHead->pNext;

        while (tmpPtr != nullptr) {
            if (tmpPtr->data == aData) {
                if (tmpPtr->pNext == nullptr) {
                    tmpPtr->pPrev->pNext = nullptr;
                }
                else {
                    tmpPtr->pPrev->pNext = tmpPtr->pNext;
                    tmpPtr->pNext->pPrev = tmpPtr->pPrev;

                }
                delete tmpPtr;
                cout << "deleted" << endl;
                return;                
            }
            else {
                tmpPtr = tmpPtr->pNext;
            }
        }

        cout << "data not found. Could not delete" << endl;
        return;
    }

    void findData(int aData) {
        DoubleLinkedListNode* tmpPtr = pHead;
        while (tmpPtr != nullptr) {
            if (aData == tmpPtr->data) {
                cout << "data present" << endl;
                return;
            }
        }
        cout << "could not find the data" << endl;
    }

    void PrintData() {
        if (pHead == nullptr) {
            cout << "Nothing to Print" << endl;
        }

        cout << "Data of Double Linked list below" << endl;

        DoubleLinkedListNode* pTmp = pHead;
        while (pTmp != nullptr) {
            cout << pTmp->data << endl;
            pTmp = pTmp->pNext;
        }

        return;
    }

};
void RunDoublyLinkedListProgram() {
    int option = 0;
    DoublyLinkedList myDLL;

    while(1)
    {
        cout << "running Dobule Linked list program" << endl;
        cout << "1. Insert data " << endl;
        cout << "2. Delete data " << endl;
        cout << "3. Find data " << endl;
        cout << "4. Print data" << endl;
        cin >> option;
        int data = 0;
        int exit = 0;
        switch (option) {
        case 1:
            cout << "Enter data to insert: " << endl;
            cin >> data;
            myDLL.insertData(data);
            break;
        case 2:
            cout << "Enter data to delete: " << endl;
            cin >> data;
            myDLL.deleteData(data);
            break;
        case 3:
            cout << "Enter data to find: " << endl;
            cin >> data;
            myDLL.findData(data);
            break;
        case 4: 
            myDLL.PrintData();
            break;
        default:
            cout << "invalid option ..exiting" << endl;
            exit = 1;
            break;
        }

        if (exit == 1) break;

    }

    return;
}

int main()
{
    cout << "Select algo to run" << endl;

    cout << "1. Single linked List" << endl;
    cout << "2. Doubly linked list" << endl;
    int i = 0;

    cin >> i;

    if (i == 1) {
        RunSinglyLinkedListProgram();
    }
    else if (i == 2) {
        RunDoublyLinkedListProgram();
    }
    else {
        cout << "invalid option.. exiting" << endl;
        
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
