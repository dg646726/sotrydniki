#include "Header.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
using namespace std;

HANDLE color1 = GetStdHandle(STD_OUTPUT_HANDLE);

#define ENDL cout<<endl
#define PAUSE system("pause")
#define CLEAR system("cls")

Sotrydniki* sotrydniki;
int countSotrydnikiv = 0;
list<Sotrydniki> list_sotrydnikiv;
void init()
{
	ifstream fin;
	fin.open("Sotrydniki.txt");
	bool isOpen = fin.is_open();

	if (isOpen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		int data1;
		Sotrydniki oldNote;
		while (!fin.eof()) {
			currentString++;
			if (currentString == 1) {
				getline(fin, data);

				oldNote.first_name = data;
			}
			else if (currentString == 2) {
				getline(fin, data);

				oldNote.last_name = data;
			}
			else {
				getline(fin, data);

				data1 = stoi(data);
				oldNote.age = data1;

				currentString = 0;
				list_sotrydnikiv.push_back(oldNote);
				oldNote = Sotrydniki();

			}
		}
		countSotrydnikiv = list_sotrydnikiv.size();
		Sotrydniki* temp = new Sotrydniki[countSotrydnikiv];
		int index_array = 0;
		for (Sotrydniki item : list_sotrydnikiv)
		{
			temp[index_array] = item;
			index_array++;
		}

		sotrydniki = temp;
	}
}

void add()
{
	CLEAR;
	Sotrydniki* temp = new Sotrydniki[countSotrydnikiv + 1];
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		temp[i] = sotrydniki[i];
	}
	cout << "Enter first name:";
	cin >> temp[countSotrydnikiv].first_name;
	cout << "Enter last name:";
	cin >> temp[countSotrydnikiv].last_name;
	cout << "Enter age:";
	cin >> temp[countSotrydnikiv].age;

	delete sotrydniki;
	sotrydniki = temp;
	countSotrydnikiv++;

	ENDL;
	PAUSE;
	CLEAR;
}

void show()
{
	CLEAR;
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "#" << i + 1 << endl;
		SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "First name:" << sotrydniki[i].first_name << endl;
		cout << "Last name:" << sotrydniki[i].last_name << endl;
		cout << "Age:" << sotrydniki[i].age << endl;
		ENDL;

	}
	ENDL;
	PAUSE;
	CLEAR;
}

void search_age()
{
	CLEAR;
	int k = 1;
	int age = 0;
	cout << "Enter age:";
	cin >> age;
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		if (age == sotrydniki[i].age) {
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "#" << i + 1 << endl;
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "First name:" << sotrydniki[i].first_name << endl;
			cout << "Last name:" << sotrydniki[i].last_name << endl;
			cout << "Age:" << sotrydniki[i].age << endl;
			k++;
			ENDL;
		}
	}
	ENDL;
	PAUSE;
	CLEAR;
}

void search_lastName()
{
	CLEAR;
	int k = 1;
	string lastName;
	cout << "Enter last name:";
	cin >> lastName;
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		if (lastName == sotrydniki[i].last_name) {
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "#" << i + 1 << endl;
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "First name:" << sotrydniki[i].first_name << endl;
			cout << "Last name:" << sotrydniki[i].last_name << endl;
			cout << "Age:" << sotrydniki[i].age << endl;
			k++;
			ENDL;

		}
	}
	ENDL;
	PAUSE;
	CLEAR;
}

void search_letter_lastName()
{
	int k = 1;
	CLEAR;
	char letter;
	cout << "Enter letter:";
	cin >> letter;
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		if (letter == sotrydniki[i].last_name[0]) {
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN);
			cout << "#" << k << endl;
			SetConsoleTextAttribute(color1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "First name:" << sotrydniki[i].first_name << endl;
			cout << "Last name:" << sotrydniki[i].last_name << endl;
			cout << "Age:" << sotrydniki[i].age << endl;
			k++;
			ENDL;
		}
	}
	ENDL;
	PAUSE;
	CLEAR;
}

void editing()
{
	CLEAR;
	int number = 0;
	cout << "Enter number:";
	cin >> number;
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		if ((number - 1) == i) {
			cout << "Was " << sotrydniki[i].first_name << " will become ";
			cin >> sotrydniki[i].first_name;
			cout << "Was " << sotrydniki[i].last_name << " will become ";
			cin >> sotrydniki[i].last_name;
			cout << "Was " << sotrydniki[i].age << " will become ";
			cin >> sotrydniki[i].age;
		}
	}
	ENDL;
	PAUSE;
	CLEAR;
}

void del()
{
	CLEAR;
	int number = 0;
	int k = 0;
	cout << "Enter number:";
	cin >> number;
	Sotrydniki* temp = new Sotrydniki[countSotrydnikiv - 1];
	for (int i = 0; i < countSotrydnikiv; i++)
	{
		if ((number - 1) == i) {

		}
		else
		{
			temp[k] = sotrydniki[i];
			k++;
		}
	}

	countSotrydnikiv--;
	delete sotrydniki;
	sotrydniki = temp;
	ENDL;
	PAUSE;
	CLEAR;
}

void saving()
{
	ofstream fout;
	fout.open("Sotrydniki.txt");
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file" << endl;
	}
	else {
		for (int i = 0; i < countSotrydnikiv; i++)
		{
			fout << sotrydniki[i].first_name << endl;
			fout << sotrydniki[i].last_name << endl;
			fout << sotrydniki[i].age << endl;

		}

	}
	fout.close();
	cout << "Changes applied" << endl;
	PAUSE;
	CLEAR;
}
