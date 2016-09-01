#pragma once
#include"Stack.h"
#include"StackEmpty.h"
#include"StackFull.h"

#ifndef STACKARRAY
#define STACKARRAY


template<typename E>
class StackArray : public Stack<E>
{
	const int DEF_CAPACITY = 100;
public:
	StackArray(const int cap) : cap(cap), arr(new E[size]) {};
	StackArray() { arr = new E[DEF_CAPACITY]; }
	void virtual push(const E& e);
	void virtual pop();

	int virtual size() const;
	bool virtual empty() const;
	const E virtual top() const;
protected:
	int cap = DEF_CAPACITY;
	E *arr;
	int head = -1;

};

#endif