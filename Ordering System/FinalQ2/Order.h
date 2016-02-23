#include <string>
#ifndef ORDER
#define ORDER

//Sam Reynolds
class Order
{
protected:
	char ID[20];
	char date[40];
	char name[10];
	char num[10];
	char amount[10];

public:
	Order();
	Order(char[], char[]);
	Order(char[], char[], char[], char[], char[]);
	char * getDate();
	char * getID();
	void displayInfo();
};
#endif