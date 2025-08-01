// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    
public:
    TreeNode(int arg = 0) {
        pLeft = nullptr;
        pRight = nullptr;
        depth = 0;
        data = arg;
        cout << "Constructor called for node : " << data << endl;
    }

    ~TreeNode() {
        pLeft = nullptr;
        pRight = nullptr;
        cout << "destructor called for node : " << data << endl;
    }

    void AddToRight(TreeNode* rightNode) {
        if (rightNode == nullptr) return;

        pRight = rightNode;
        updateDepth();
    }

    void AddToLeft(TreeNode* leftNode) {
        if (leftNode == nullptr) return;
        pLeft = leftNode;
        updateDepth();
    }

    void updateDepth() {
        int leftDepth = 0;
        int rightDepth = 0;

        if (pLeft != nullptr) leftDepth = pLeft->depth;
        if (pRight != nullptr) rightDepth = pRight->depth;
        int biggestDepth = ((leftDepth > rightDepth) ? leftDepth : rightDepth);
        if (leftDepth == 0 && rightDepth == 0) {
            depth = biggestDepth + 1;
        }
        else {
            depth = biggestDepth;
        }
    }

    TreeNode* pLeft;
    TreeNode* pRight;
    int depth;
    int data;
};

TreeNode* root = nullptr;


void addToTree() {
    cout << "Input data to add \n";
    int DataToAdd = 0;
    cin >> DataToAdd;

    TreeNode* newNode = new TreeNode(DataToAdd);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    TreeNode* tmpPtr = root;
    while (tmpPtr != nullptr) {
        if (DataToAdd < tmpPtr->data) {
            if (tmpPtr->pLeft == nullptr) {
                tmpPtr->AddToLeft(newNode);
                break;
            }
            else {
                tmpPtr = tmpPtr->pLeft;
            }
        }
        else {
            if (tmpPtr->pRight == nullptr) {
                tmpPtr->AddToRight(newNode);
                break;
            }
            else {
                tmpPtr = tmpPtr->pRight;
            }
        }
    }
}

void deleteFromTree() {
    cout << "Data to delete \n";
    int dataToDelete = 0;
    cin >> dataToDelete;

    cout << "Data to delete : " << dataToDelete << endl;
    return;
}

void DepthFirstTraversal(TreeNode* pNode) {
    if (pNode == nullptr) return;

    cout << " " << pNode->data << " " << pNode->depth <<endl;
    DepthFirstTraversal(pNode->pLeft);
    DepthFirstTraversal(pNode->pRight);

    return;

}
void PrintTree() {
    cout << "\n Printing Tree " << endl;
    queue<TreeNode*> qTree;
    if (root == nullptr) {
        cout << "nothing to print \n";
        return;
    }

    qTree.push(root);
    while (!qTree.empty()) {
        TreeNode* item = qTree.front();
        cout << item->data << endl;
        qTree.pop();
        if (item->pLeft) qTree.push(item->pLeft);
        if (item->pRight) qTree.push(item->pRight);
    }

    cout << "Printing Done" << endl;
}

void findInTree() {
    cout << "Enter element to find" << endl;
    int element;
    cin >> element;
    bool isFound = false;
    TreeNode* tmp = root;
    while (tmp != nullptr) {
        if (tmp->data == element) {
            isFound = true;
            break;
        }
        else if (tmp->data < element) {
            tmp = tmp->pRight;
        }
        else {
            tmp = tmp->pLeft;
        }
    }

    if (isFound) {
        cout << " Found it" << endl;
    }
    else {
        cout << " Can not found the element" << endl;
    }

    return;
}

int main()
{
    cout << "Tree Program \n";
    int option = 0;
    
    while (option != 9) {
        cout << "\n Select Option \n";
        cout << "1. Add \n 2. Delete \n 3. Print \n 4. Find \n 9. Exit\n ";
        cin >> option;

        if (option == 1) {
            addToTree();
        }

        if (option == 2) {
            deleteFromTree();
        }
    
        if (option == 3) {
            PrintTree();
        }

        if (option == 4) {
            findInTree();
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
