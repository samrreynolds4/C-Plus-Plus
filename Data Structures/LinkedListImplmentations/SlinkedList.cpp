#include"stdafx.h"
#include"SlinkedList_header.h"
#include<iostream>
#include"ExceptionBase.h"


template<typename E>
SlinkedList<E>::~SlinkedList()
{
	Node<E> *D_node = tail;

	for (int i = 0; i < size; i++)
	{
		temp = D_node->next;
		delete D_node;
		D_node = temp;
	}
	delete temp;
}

template<typename E>
bool SlinkedList<E>::empty() const
{
	return (size == 0)
}

// Adds an element to the head of the list
template<typename E>
void SlinkedList<E>::add(E e)
{
	// If the list is empty, initialize the head and tail node
	if (size == 0)
	{
		head = tail = new Node<E>(e);
		tail->next = head;
	}
	else
	{
		temp = new Node<E>(e);
		head->next = temp;
		head = temp;
	}

	size++;
}

template<typename E>
E SlinkedList<E>::get(int index) throw( IndexOutOfRange )
{
	try
	{
		if (index > size - 1 || index < 0)
		{
			throw IndexOutOfRange("Index Out Of Range");
		}
	}



	temp = tail;
	try
	{
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
			if (temp == nullptr) { throw IndexOutOfRange("Broken List") }
		}
	}

	catch (IndexOutOfRange ior)
	{
		std::cout << ior.getErr();
	}

	return temp->getElement();
}

template<typename E>
bool SlinkedList<E>::deleteIndex(int index)
{
	// the node to delete;
	Node<E> *D_node;

	// the node to reconnect the other nodes
	temp = tail;

	// If the index is not in ht elist return false
	if (index > (size - 1)) { return false; }

	// Check if we are removing the tail
	if (index == 0)
	{
		D_node = tail;
		tail = tail->next;
		delete D_node;
		size--;
		return true;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}

		D_node = temp->next;
		temp->next = temp->next->next;
		delete D_node;
		size--;
	}

	return true;
}

template<typename E>
bool SlinkedList<E>::deleteObject(E e)
{
	temp = tail;

	// Check if the object is at the tail
	if (temp->equalElement(e))
	{
		tail = tail->next;
		delete temp;
		size--;
		return true;

	}
	else
	{
		// Object was not in the tail, check everywhere else
		for (int i = 0; i < size - 1; i++)
		{
			// In order to easily reconnect the nodes after deleting the object, we must check the node next to the current one
			if (temp->next->equalElement(e))
			{
				Node<E> *D_node = temp->next;
				temp->next = temp->next->next;
				delete D_node;
				size--;
				return true;
			}
			temp = temp->next;
		}
	}

	// Element is not in the list
	return false;
}

// Print the list to the given Ostream
template<typename E>
void SlinkedList<E>::printList(std::ostream &Ostream)
{
	temp = tail;
	int num = 1;
	for (int i = 0; i < size; i++)
	{
		Ostream << num << " " << temp->getElement() << "\n";
		num++;
		temp = temp->next;
	}

}