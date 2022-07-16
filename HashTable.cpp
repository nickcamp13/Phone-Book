//##################################################
// File: HashTable.cpp
// Author: Nicholas Campos
// Description: This file contains the implementation
//			 of the HashTable class.
// Date: April 23rd, 2022
//#################################################

#include "HashTable.h"

// #################################################
// @par Name
// hashFunc
// @purpose
// determines the hash value of a key to be inserted
// into a HashTable
// @param [in] :
// string key - string used to calculate hash value
// @return
// int
// @par References
// None
// @par Notes
// None
//##################################################
int HashTable::hashFunc(string key)
{
    int hashVal{};
    for (int i{}; i < key.size(); i++) {
	   hashVal = 37 * hashVal + static_cast<int>(key[i]);
    }

    hashVal %= TABLESIZE;

    if (hashVal < 0) {
	   hashVal += TABLESIZE;
    }

    return hashVal;
}

// #################################################
// @par Name
// HashTable
// @purpose
// default constructor, resizes the table to size of 53
// @param [in] :
// None
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################
HashTable::HashTable()
{
    this->resize(TABLESIZE, nullptr);
}

// #################################################
// @par Name
// add
// @purpose
// adds a passed string and phone number into a HashTable
// @param [in] :
// string name - name of person to be added into a HashTable
// string number - number of person to be added into a Hashtable
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################
void HashTable::add(string name, string number)
{
    int h = hashFunc(name);

    if (this->at(h) == nullptr) {
	   this->at(h) = new PairList<string>;
	   this->at(h)->addPair(name, number, h);
    }
    else
	   this->at(h)->addPair(name, number, h);
}

// #################################################
// @par Name
// lookup
// @purpose
// allows the user to retrieve a phonenumber from the
// HashTable by searching for their name
// @param [in] :
// string name - name of the person whose being searched for
// @return
// string
// @par References
// None
// @par Notes
// None
//##################################################
string HashTable::lookup(string name)
{
    int h = hashFunc(name);
    PairList<string> *p = this->at(h);
    if (p->contains(name))
	   return name + " (" + to_string(h) + " - " + to_string(p->getOffset(name)) + ") " + p->getSecond(name);
    return "This person does not exist within the phone book";
}

// #################################################
// @par Name
// printTable
// @purpose
// displays the entire HashTable to the console
// @param [in] :
// None
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################
void HashTable::printTable() const
{
    for (int i = 0; i < this->size(); i++) {
	   this->at(i)->printList();
    }
}
