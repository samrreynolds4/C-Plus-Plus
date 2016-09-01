// Sam Reynolds
// 07/22/2016
// An iterator that will allow you to iterate ovr any data structure that
// utilizes the Node implmentation

#pragma once
#include"Node.h"
template<typename E>
class Iterator
{
public:
	// Initialize an iterator at a specefic node
	Iterator(Node<E> &u) { p = &u; }

	// Delete the current node
	bool remove();
	
	// Go to the next node based on current node
	Iterator<E>& operator++();

	// Go to the previous Node based on current node
	Iterator<E>& operator--();

	// go to next node num times
	Iterator<E>& operator+=(const int& num);

	// point the iterator at a new node
	Iterator<E>& operator=(Node<E> &u);

	// dereference the iterator
	E operator*();
private:
	Node<E> *p;

	// This is used for deleting node that dont have a reference to the previous node
	Node<E> *prev;

};

template<typename E>
bool Iterator<E>::remove()
{
	// If p doesn't point to anything return false
	if (p == NULL) { return false; }

	// if node next to p is null and prev is null, then p is the last node
	if (p->next == NULL && prev == NULL) 
	{ 
		delete p; 
		return true;
	}

	if (p->prev != NULL)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	else
	{
		prev->next = p->next;
		delete p;
		p = prev->next;
	}
}

template<typename E>
Iterator<E>& Iterator<E>::operator++()
{
	if (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}

	return *this;
}

template<typename E>
Iterator<E>& Iterator<E>::operator--()
{
	if (p->prev != NULL)
	{
		p = p->prev;
	}

	return *this;
}

template<typename E>
Iterator<E>& Iterator<E>::operator+=(const int& num)
{
	for (int i = 0; i < num; i++)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}
	}

	return *this;
}

template<typename E>
Iterator<E>& Iterator<E>::operator=(Node<E> &u)
{
	*p = u;
	return *this;
}

template<typename E>
E Iterator<E>::operator*()
{
	return p->getElement();
}