//*****************************************************************************************************
//
//		File:					LinkedList.h
//
//		Contributor:			Joseph Rydel
//
//		Description: This program is a header 
//					 file with an implementation 
//					 of a linked list.
//
//      Other files required: Node.h
//							  Employee.h
//							  Employee.cpp
//							  ClassRosterDriver.cpp	
//							  
//*****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include<ostream>

//*****************************************************************************************************

template<typename T>
class LinkedList
{
private:
	Node<T>* front;

public:
	LinkedList();
	~LinkedList();
	bool insert(const T&);
	bool del(T&);
	bool deleteFront();
	bool deleteBack();
	bool deleteAllBut(const T&);
	bool find(T&, std::ostream&) const;
	bool viewFront(std::ostream&) const;
	bool viewBack(std::ostream&) const;
	bool isEmpty() const;
	bool isFull() const;
	bool clearList();
	bool reverse();
	bool display(std::ostream&) const;
	int getSize() const;
};

//*****************************************************************************************************

template<typename T>
LinkedList<T>::LinkedList()
{
	front = nullptr;
}

//*****************************************************************************************************

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* pTemp = nullptr;

	while (front != nullptr)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::insert(const T& dataIn)
{
	bool success = false;
	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < dataIn)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	Node<T>* pNew = new Node<T>(dataIn, pTemp);

	if (pNew != nullptr)
	{
		if (pPrev != nullptr)
			pPrev->next = pNew;
		else
			front = pNew;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::del(T& dataOut)
{
	bool success = false;
	Node<T>* pTemp = front;
	Node<T>* pPrev = nullptr;

	while (pTemp != nullptr && pTemp->data < dataOut)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataOut)
	{
		if (pPrev != nullptr)
			pPrev->next = pTemp->next;

		else
			front = pTemp->next;

		dataOut = pTemp->data;
		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::find(T& desiredData, std::ostream& os) const
{
	bool success = false;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < desiredData)
		pTemp = pTemp->next;

	if (pTemp != nullptr && pTemp->data == desiredData)
	{
		os << pTemp->data << "\n";
		success = true;
	}

	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteAllBut(const T& dataKeep)
{
	bool success = false;
	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < dataKeep)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
		front = pTemp;
		delete pTemp;
	}

	while (pTemp != nullptr && pTemp->data == dataKeep)
	{
		pPrev = pTemp->next;
		pTemp = pTemp->next;
		success = true;
	}

	while (pTemp != nullptr && pTemp->data > dataKeep)
	{
		pPrev->next = pTemp->next;
		delete pTemp;
		pTemp = pPrev->next;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::viewBack(std::ostream& os) const
{
	bool success = false;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->next != nullptr)
		pTemp = pTemp->next;

	if (pTemp != nullptr)
	{
		os << pTemp->data << "\n";
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::viewFront(std::ostream& os) const
{
	bool success = false;

	if (front != nullptr)
	{
		os << front->data << "\n\n";
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
inline bool LinkedList<T>::isEmpty() const
	{	return front == nullptr;	}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::isFull() const
{
	bool success = false;
	Node<T>* pNew;
	pNew = new (std::nothrow) Node<T>;

	if (pNew == nullptr)
	{
		delete pNew;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteFront()
{
	bool success = false;
	Node<T>* pTemp = front;

	if (pTemp != nullptr)
	{
		front = pTemp->next;
		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteBack()
{
	bool success = false;
	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->next != nullptr)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr)
	{
		delete pTemp;
		pPrev->next = nullptr;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::display(std::ostream& os) const
{
	bool success = false;
	Node<T>* pTemp = front;

	while (pTemp != nullptr)
	{
		os << pTemp->data << "\n\n";
		pTemp = pTemp->next;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::clearList()
{
	bool success = false;
	Node<T>* pDel = nullptr;

	while (front != nullptr)
	{
		pDel = front;
		front = front->next;
		delete pDel;
		pDel = pDel->next;
	}

	if (front == nullptr)
		success = true;

	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::reverse()
{
	bool success = false;

	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;
	Node<T>* pNext;

	if (pTemp != nullptr)
		success = true;

	while (pTemp != nullptr)
	{
		pNext = pTemp->next;
		pTemp->next = pPrev;
		pPrev = pTemp;
		pTemp = pNext;
	}

	if (success)
		front = pPrev;

	return success;
}

//*****************************************************************************************************

template<typename T>
int LinkedList<T>::getSize() const
{
	int size = 0;
	Node<T>* pTemp = front;

	while (pTemp != nullptr)
	{
		size++;
		pTemp = pTemp->next;
	}

	return size;
}

//*****************************************************************************************************

#endif