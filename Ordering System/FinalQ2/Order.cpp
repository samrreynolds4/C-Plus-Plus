#include "Order.h"
#include <iostream>
using namespace std;

//Sam Reynolds
Order::Order(char id[], char d[], char nam[], char n[], char am[] )
{
	strcpy(date, d);
	strcpy(ID, id);
	strcpy(name, nam);
	strcpy(num, n);
	strcpy(amount, am);
}

Order::Order()
{

}

char * Order::getDate()
{
	return date;
}

char * Order::getID()
{
	return ID;
}

void Order::displayInfo()
{
	cout << "Order: " << endl;
	cout << ID << " " << date << " " << name << " " << num << " " << amount << endl;
}