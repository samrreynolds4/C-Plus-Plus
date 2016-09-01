#include"stdafx.h"
#include<string>
using std::string;

#ifndef EXCEPTIONBASE
#define EXCEPTIONBASE

class ExceptionBase
{
public:
	ExceptionBase(string err) : errMsg(err) {}
	string getErr() { return errMsg; }

protected:
	string errMsg;
};

class IndexOutOfRange : public ExceptionBase
{
public:
	IndexOutOfRange(string err) : ExceptionBase(err) {}
};


#endif