/*Sam Reynolds
7/05/2016
Description: A base exception class for other exceptions to derive*/
#pragma once
#include<string>
#include"stdafx.h"
#ifndef RUNTIMEEXCEPTION
#define RUNTIMEEXCEPTION

class RuntimeException
{
public:
	RuntimeException(const std::string &msg) : errMsg(msg) {}
	std::string getMsg() { return errMsg; }
protected:
	std::string errMsg;
};


#endif