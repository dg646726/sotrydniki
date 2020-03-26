#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Sotrydniki{

	string first_name;
	string last_name;
	int age;

};

void init();
void add();
void show();
void search_age();
void search_lastName();
void search_letter_lastName();
void editing();
void del();
void saving();
