/*Sam Reynolds
7/05/2016
Description: An abstract class for a stack data structure */

#pragma once
#include"stdafx.h"
#ifndef STACK
#define STACK

template<typename E>
class Stack
{
public:
	//Return the size of the stack
	int virtual size() const	= 0;

	// return True if the stack is empty
	bool virtual empty() const  = 0;

	// Push a new element to the top of the stack
	void virtual push(const E& e)	= 0;

	// remove the top of the stack, but will not return it
	void virtual pop() = 0;

	// Return the top of the stack and throw the StackEmpty exception if empty, will not remove top
	const E virtual top() const = 0;
};

#endif