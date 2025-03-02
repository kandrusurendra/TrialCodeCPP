#pragma once
#include<iostream>

using namespace std;

class Node
{

public:
	Node (int aData=0) {
		data = aData;
		pNext = nullptr;
	}

	int data;
	Node* pNext;


	int getData() {
		return data;
	}

	void setData(int aData) {
		data = aData;
	}

	Node* getNext() {
		return pNext;
	}

	void setNext(Node* aNext) {
		pNext = aNext;
	}
};

class DoubleLinkedListNode
{

public:
	int data;
	DoubleLinkedListNode* pPrev;
	DoubleLinkedListNode* pNext;

	DoubleLinkedListNode(int aData = 0)
	{
		data = aData;
		pPrev = nullptr;
		pNext = nullptr;
	}
};




