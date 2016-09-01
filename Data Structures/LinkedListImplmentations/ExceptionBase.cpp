#include"stdafx.h"
#include<string>
using std::string;

class ExceptionBase
{
public:
	ExceptionBase(string err) : errMsg(err) {}
	string getErr() { return errMsg; }

protected:
	string errMsg;
};