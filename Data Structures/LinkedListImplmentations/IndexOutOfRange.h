#pragma once
#include"stdafx.h"
#include"ExceptionBase.h"

#ifndef INDEXOUTOFRANGE
#define INDEXOUTOFRANGE

class IndexOutOfRange : public ExceptionBase
{
public:
	IndexOutOfRange(string err) : ExceptionBase(err) {}
};

#endif