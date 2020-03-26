#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
#include "Header.h"

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);



int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	init();

	int action;
	do {
		SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "1.Add" << endl;
		cout << "2.Show all" << endl;
		cout << "3.Search by age" << endl;
		cout << "4.Search by last name" << endl;
		cout << "5.Search by first letter of last name" << endl;
		cout << "6.Editing" << endl;
		cout << "7.Delete" << endl;
		cout << "8.Saving" << endl;
		cout << "9.Exit" << endl;
		cout << endl;
		SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

		cout << "Select action:";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			add();
			break;
		case 2:
			show();
			break;
		case 3:
			search_age();
			break;
		case 4:
			search_lastName();
			break;
		case 5:
			search_letter_lastName();
			break;
		case 6:
			editing();
			break;
		case 7:
			del();
			break;
		case 8:
			saving();
			break;
		case 9:
			cout << "Bye" << endl;
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	} while (action != 9);

	system("pause");
	return 0;
}