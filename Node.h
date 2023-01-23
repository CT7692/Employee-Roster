//*****************************************************************************************************
//
//		File:				ClassRosterDriver.cpp
//
//		Contributor:			Joseph Rydel
//
//		Description: This program is the driver file
//					 for a linked list to demonstrate
//					 the reversal of a linked list.
//
//      Other files required: Node.h
//							  Employee.h
//							  Employee.cpp
//							  LinkedList.h	
//							  
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node();
	Node(const T&, Node<T>*);
};

//*****************************************************************************************************

template<typename T>
Node<T>::Node()
{
	next = nullptr;
}

//*****************************************************************************************************

template<typename T>
Node<T>::Node(const T& d, Node<T>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif