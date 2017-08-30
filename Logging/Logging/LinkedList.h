#ifndef LINKED_LIST_HEADER_H
#define LENKED_LIST_HEADER_H

#include "Node.h"

using namespace std;

template<typename T>
class LinkedList
{
public:
	//Constructors and Destructors
	LinkedList()
	{
		first = nullptr;
		last = nullptr;

	}

	~LinkedList()
	{
		delete first;
		delete last;
	}


	//Insert an element on the top of the linked list
	void Insert(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		
		if (first == nullptr)
		{
			first = newNode;
			last = first;
		}
		else
		{
			last->_mNextPtr = newNode;
			newNode->_mNextPtr = nullptr;
			last = newNode;
		}
	}

	//Remove the node from the top of the linked list
	void Remove()
	{
		Node<T> *currentNode = nullptr;
		Node<T> *prevNode = nullptr;

		currentNode = rootNode;

		if (rootNode == nullptr)
		{
			cout << "Your list is empty." << endl;
		}
		else
		{
			while (currentNode->_mNextPtr != nullptr)
			{
				prevNode = currentNode;
				currentNode = prevNode->_mNextPtr;
			}
			currentNode = nullptr;
			prevNode->_mNextPtr = currentNode;
		}

	}


	//Print all the elements on the linked list.
	void Print()
	{
		Node<T> *currNode = nullptr;
		Node<T> *prevNode = nullptr;
		currNode = first;

		if (currNode->_mNextPtr == nullptr)
		{
			cout << "The linked list is Empty." << endl;
		}
		else
		{
			while (currNode != nullptr)
			{
				cout << currNode->_mData << " -> ";
				prevNode = currNode;
				currNode = prevNode->_mNextPtr;
				
			}

			cout << "NULL" << endl;;
		}
	}


	Node<T> *first;
	Node<T> *last;
	
};



#endif // !LINKED_LIST_HEADER_H

