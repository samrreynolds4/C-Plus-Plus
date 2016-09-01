// Sam Reynolds
// 07/22/2016
// Doubley linked List implementation, allows back and fourth iteration

#pragma once
#include"List.h"
#include"Node.h"
#include"Iterator.h"
template<typename E>
class DoubleyLinkedList : List<E>
{
public:
	// Default constructor
	DoubleyLinkedList() : head(NULL), tail(NULL), size(0) { }
	
	// Will add something to the top of the list
	void add(E e);

	// remove something at an index
	bool removeIndex(int i);

	// Gets the size of the list
	int getSize() const;

	// Returns true if the list is empty
	bool empty() const;
	
	// Returns the iterator for this list
	Iterator<E>& GetIterator() const { return *iter; }

private:
	Node<E> *head;
	Node<E> *tail;
	Iterator<E> *iter;
	int size;
};

template<typename E>
void DoubleyLinkedList<E>::add(E e)
{
	if (size == 0)
	{
		head = tail = new Node<E>(e);
		head->prev = tail;
		tail->next = head;
		iter = new Iterator<E>(*tail);
	}
	else
	{
		Node<E> *temp = new Node<E>(e);
		head->next = temp;
		temp->prev = head;
		head = temp;
	}

	size++;
}

template<typename E>
bool DoubleyLinkedList<E>::removeIndex(int i)
{
	if (i < 0 || i > size) { return false; }
	*iter = *tail;
	 
	for (int n = 0; n < i; n++)
	{
		iter++;
	}

	return true;
}

template<typename E>
bool DoubleyLinkedList<E>::empty() const
{
	return (size == 0);
}

template<typename E>
int DoubleyLinkedList<E>::getSize() const
{
	return size;
}