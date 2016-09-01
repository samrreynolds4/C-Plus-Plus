#include"stdafx.h"
#include"StackArray.h"

// Sam Reynolds
// 07/05/16
// Implmentation of a Stack using an array to store the elements 
// it seems common that classes are only declared along with it's functions in .h files then defined later in .cpp files

template<typename E>
void StackArray<E>::pop()
{
	if (head < 0) { throw(StackEmpty("The stack is empty")); }
	else
	{
		head--;
	}
}

// Push a new element on the head of the stack
template<typename E>
void StackArray<E>::push(const E& e)
{
	if (head == cap - 1) { throw StackFull("The stack is full"); }
	else
	{
		head++;
		arr[head] = e;
	}
}

template<typename E>
const E StackArray<E>::top() const
{
	if (head < 0) { throw StackEmpty("The stack is empty"); }
	return (arr[head]);
}

template<typename E>
int StackArray<E>::size() const
{
	return cap;
}

template<typename E>
bool StackArray<E>::empty() const
{
	return (head < 0);
}