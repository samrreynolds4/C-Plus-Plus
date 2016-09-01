#pragma once
#include"Node.h"
#include<ios>
#include"ExceptionBase.h"
#include"AbstractList.h"

#ifndef SLINKEDLIST
#define SLINKEDLIST

template<typename E>
class SlinkedList : public AbstractList
{
public:
	// Initializers
	SlinkedList() {};

	//Destructor
	~SlinkedList();

	// Returns True if the list is empty
	bool empty() const;

	// Adds an element to the head of the list;
	void add(E e);

	//gets the element at the index
	E get(int index) throw(IndexOutOfRange);

	// Deletes the element at the index, returns False if the index is too large
	bool deleteIndex(int index);

	// Deletes the object if it is in the list
	bool deleteObject(E e);

	// Print the list to the given oStream
	void printList(std::ostream &Ostream);

	// Size of the list
	int size = 0;

protected:
	Node<E> *head;
	Node<E> *temp;
	Node<E> *tail;
};


#endif