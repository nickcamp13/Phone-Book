//##################################################
// File: HashTable.h
// Author: Nicholas Campos
// Description: This file contains the class definition
//			 for the HashTable class.
// Date: April 23rd, 2022
//#################################################

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <vector>
#include <string>
#include "PairList.h"

using std::vector;
using std::string;
using std::to_string;

const int TABLESIZE = 53;

class HashTable : public vector<PairList<string>*> {
 private:
	int hashFunc(string key);

 public:
	HashTable();
	void add(string name, string number);
	string lookup(string name);
	void printTable() const;
};

#endif  //  HASHTABLE_H_
