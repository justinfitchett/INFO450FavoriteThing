#include "stdafx.h"
#include "pizza.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

//default constructor
Pizza::Pizza()
{
	name = "";
	toppings = "";
	size = "";
	numofPizzas = 0;
	location = "";
}

Pizza::Pizza(string n, string t, string s, int num, string l)
{
	name = n;
	toppings = t;
	size = s;
	numofPizzas = num;
	location = l;
}

void Pizza::GetUserInput()
{
	cout << "What type of pizza do you want? " << endl;
	getline(cin, name);
	cout << "List any toppings that you wish add: " << endl;
	getline(cin, toppings);
	cout << "What size (Small, Medium, Large, or X-Large)? " << endl;
	getline(cin, size);
	cout << "How many? " << endl;
	cin >> numofPizzas;
	cin.ignore();
	cin.clear();
	cout << "Where do you want it delivered? " << endl;
	getline(cin, location);
}

void Pizza::Display()
{
	cout << "------------------------" << endl;
	cout << "Name of Pizza: " << name << endl;
	cout << "Additional Toppings: " << toppings << endl;
	cout << "Size: " << size << endl;
	cout << "Number of Pizza(s): " << numofPizzas << endl;
	cout << "Requested Location: " << location << endl;
	cout << "------------------------" << endl;
}

ofstream& operator<<(ofstream &fs, Pizza *item)
{
	fs << item->name << ',' << item->toppings << "," << item->size << "," << item->numofPizzas << "," << item->location << "," << endl;
	return fs;
}