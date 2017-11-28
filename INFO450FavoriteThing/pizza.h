#pragma once
#include <string>
#include "stdafx.h"

using namespace std;

class Pizza
{
private:
	string name;
	string toppings;
	string size;
	int numofPizzas;
	string location;
public:
	Pizza();
	Pizza(string n, string t, string s, int num, string l);
	void GetUserInput();
	void Display();

	friend ofstream& operator<<(ofstream &fs, Pizza *item);
};

