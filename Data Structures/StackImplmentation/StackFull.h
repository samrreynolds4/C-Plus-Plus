#pragma once
#include"RuntimeException.h"


#ifndef STACKFULL
#define STACKFULL

class StackFull : public RuntimeException
{
public:
	StackFull(const std::string msg) : RuntimeException(msg) {}
};

#endif 