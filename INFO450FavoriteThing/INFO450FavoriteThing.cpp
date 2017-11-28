// INFO450FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pizza.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int LISTSIZE = 50;

int main()
{
	Pizza **myEntry;
	int count = 0;
	int i;
	string answer = "Y";
	string filepath;

	myEntry = new Pizza*[LISTSIZE];

	cout << "Welcome to my favorite thing...PIZZA!!!" << endl;

	cout << "Please enter the location of your file that you wish to save: " << endl;
	getline(cin, filepath);

	//read from a file - saves inventory items
	ifstream infile("c:\\users\\jfitc\\Desktop\\FavPizza.txt");
	if (infile.good())
	{
		while (!infile.eof())
		{
			string name, toppings, size, numofPizzas, location;
			getline(infile, name, ',');
			if (name.length())
			{
				getline(infile, toppings, ',');
				getline(infile, size, ',');
				getline(infile, numofPizzas, ',');
				getline(infile, location, '\n');
				myEntry[count] = new Pizza(name, toppings, size, stoi(numofPizzas), location);
				count++;
			}
		}
	}

	//If user wants to add more things
	cout << "You have " << count << " of pizza entries. Do you want to add more (Y/N)? " << endl;
	cin >> answer;

	//Get inventory items of Pizza entries
	while (answer == "Y" || answer == "y")
	{
		myEntry[count] = new Pizza();
		if (myEntry[count]->GetUserInput() == 0)
		{
			count++;
		}

		cout << "Add another pizza entry? " << endl;
		cin >> answer;

	}

	//array populated, display them
	for (i = 0; i < count; i++)
	{
		myEntry[i]->Display();
	}

	//saves to a file
	ofstream outfile("c:\\users\\jfitc\\Desktop\\FavPizza.txt");
	if (!outfile.good())
	{
		cout << "ERROR - Cannot open file of pizza entry! " << endl;
		return -1;
	}

	//Print to console
	for (i = 0; i < count; i++)
	{
		outfile << myEntry[i];
	}

	//Cleaning / deleting stored pointers andclearing memory
	for (i = 0; i < count; i++)
	{
		delete myEntry[i];
	}
	delete myEntry;

	return 0;
}
