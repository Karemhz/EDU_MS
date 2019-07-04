#include<iostream>
#include"Student.h"
#include"Doctor.h"
#include<stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
	time_t now = time(0);
	Student S1;
	Doctor D1;
	char* dt = ctime(&now);
	short choice;

input: cout << "--------------------------------------------------------\n";
	   cout << "        Educational Management System \n";
	   cout << "--------------------------------------------------------\n";
	   cout << "\t  " << dt                                    << "\n";
	   cout << "--------------------------------------------------------\n";
	   cout << "(1) Doctor\n";
	   cout << "(2) Student\n";
	   cout << "(3) Exit\n";
	   cin >> setw(1) >> choice;
	   cin.ignore();
	   system("clear");
	if (cin.fail())
	{
		cout << "# Wrong Input Data Please Try again #!\n\n";
		cin.clear();
		cin.ignore(32767, '\n');
		goto input;
	}

	switch (choice)
	{
	case 1:
        D1.mainMenu();
		goto input;
		break;
	case 2:
		S1.mainMenu();
		goto input;
		break;
	case 3:
		return 0;
	default:
		cout << "==> Wrong Input Data Please Try again !\n\n";
		goto input;
		break;
	}
	return 0;
}
