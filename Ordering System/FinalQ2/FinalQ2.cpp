#include "Order.h"
#include <fstream>
#include <iostream>
#define MAX 5000
using namespace std;

//Sam Reynolds
void showMenu()
{
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
	cout << "Search by: " << endl;
	cout << "1. Order ID" << endl;
	cout << "2. Order Date" << endl;
	cout << "Exit" << endl;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
}

int main()
{
	char s1[20], s2[40], s3[10], s4[10], s5[10];
	int cnt = 0;
	bool search = true;
	Order records[MAX];
	ifstream infile("orders.txt", ios::in);

	if (infile.fail())
	{
		cerr << "Cannot open file" << endl;
	}

	while (!infile.eof())
	{
		infile >> s1 >> s2 >> s3 >> s4 >> s5;
		records[cnt++] = Order(s1, s2, s3, s4, s5);
	}
	infile.close();
	while (search)
	{
		char choice[10] = "";
		bool found = false;
		showMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		if (!strcmp(choice, "1"))
		{
			cout << "Enter order ID: ";
			char order[10];
			cin >> order;
			for (int i = 0; i < cnt && !found; i++)
			{
				if (!strcmp(records[i].getID(), order))
				{
					cout << "\\\\\\\\\\" << endl;
					records[i].displayInfo();
					found = true;
					cout << "\\\\\\\\\\" << endl;
				}
			}

		}

		if (!strcmp(choice, "2"))
		{
			
			cout << "Enter order Date: ";
			char order[20];
			cin >> order;
			cout << "\\\\\\\\\\" << endl;
			for (int i = 0; i < cnt; i++)
			{
				if (!strcmp(records[i].getDate(), order))
				{
					records[i].displayInfo();
				}
			}
			cout << "\\\\\\\\\\" << endl;

		}

		if (!strcmp(choice, "Exit"))
		{
			search = false;
		}

	}	
}
