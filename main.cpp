//##################################################
// File: main.cpp
// Author: Nicholas Campos
// Description: This file contains main function for
//			 this project.
// Date: April 23rd, 2022
//#################################################

#include <iostream>
#include <vector>
#include <fstream>
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable phoneBook;
    ifstream file;
    file.open("Phonedata.txt");

    // READS FROM Phonedata.txt AND STORES DATA INTO HASHTABLE
    if (!file.is_open())
	   cout << "File did not open" << endl;
    else {
	   while (!file.eof()) {
		  string name{};
		  string number{};
		  getline(file, name, ';');
		  getline(file, number, ';');
		  phoneBook.add(name, number);
		  file >> ws;
	   }
	   file.close();
    }


    // DISPLAYS MENU FOR USER TO INTERACT
    char condition{};
    string name{};
    while (toupper(condition) != 'Q') {
	   cout << "==================================================" << endl;
	   cout << "A.	    Print Phone Book					  " << endl;
	   cout << "B.	    Lookup Person						  " << endl;
	   cout << "Q.	    Quit								  " << endl;
	   cout << "==================================================" << endl;
	   cout << "\nChoose an option from the menu above (A, B, or Q): ";
	   cin >> condition;
	   cout << endl;

	   switch (toupper(condition)) {
	   case 'A':
		  phoneBook.printTable();
		  system("PAUSE");
		  system("CLS");
		  break;
	   case 'B':
		  cout << "Enter Name: ";
		  cin >> name;
		  cout << phoneBook.lookup(name) << endl << endl;
		  system("PAUSE");
		  system("CLS");
		  break;
	   case 'Q':
		  cout << "Goodbye!" << endl;
		  break;
	   default:
		  cout << "Invalid input. Please enter 'A', 'B', or 'Q'" << endl;
		  system("PAUSE");
		  system("CLS");
		  break;
	   }
    }

    return 0;
}
