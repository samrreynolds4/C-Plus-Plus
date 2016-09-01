#pragma once
#include"RuntimeException.h"

#ifndef STACKEMPTY
#define STACKEMPTY

class StackEmpty : public RuntimeException
{
public:
	StackEmpty(const std::string msg) : RuntimeException(msg) {}
};

#endif