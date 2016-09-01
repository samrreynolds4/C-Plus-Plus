#pragma once

#ifndef NODE
#define NODE

template<typename E>
class Node
{
public:
	Node() {};
	Node(E e) : element(e) {}

	bool equalElement(E e) { return (e == element); }
	E getElement() { return element; }

	Node<E> next;
	Node<E> prev;
protected:
	E element;

};


#endif