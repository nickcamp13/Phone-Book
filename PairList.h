//##################################################
// File: PairList.h
// Author: Nicholas Campos
// Description: This file contains the PairList
//			 template class
// Date: February 26th, 2022
//#################################################

#include "Pair.h"
#include "LinkedList.h"

using std::cout;
using std::endl;

#ifndef PAIRLIST_H
#define PAIRLIST_H

template <class T>
class PairList : public LinkedList<Pair<T>>
{
public:
    void addPair(T first, T second, int hashVal);
    T getFirst(T second);
    T getSecond(T first);
    T smallestFirst();
    T smallestSecond();
    T largestFirst();
    T largestSecond();
    void deletePair(T first, T second);
    bool contains(T search);
    void printList();
    int getOffset(T search) const;
};

#endif

  
// #################################################
// @par Name
// addPair
// @purpose
// adds a pair to the PairList
// @param [in] :
// T first - first member of pair to be added
// T second - second member of pair to be added
// int hashVal - hashVal of first member
// @return
// int
// @par References
// None
// @par Notes
// None
//##################################################
template<class T>
void PairList<T>::addPair(T first, T second, int hashVal)
{
    Pair<T> p(first, second);
    this->addToEnd(p, hashVal);
}

// #################################################
// @par Name
// getFirst
// @purpose
// searches the second pair value of all pairs in
// a pair list and returns its paired value
// @param [in] :
// second - second value of a pair that you want
//		  the first value of
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::getFirst(T second)
{
    Node<Pair<T>> *p = this->getHead();
    while (p != nullptr)
    {
	   if (p->data.getSecond() == second)
	   {
		  return p->data.getFirst();
	   }
	   p = p->next;
    }
    return NULL;
}

// #################################################
// @par Name
// getSecond
// @purpose
// searches the first pair value of all pairs in
// a pair list and returns its paired value
// @param [in] :
// first - first value of a pair that you want
//		 the first value of
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::getSecond(T first)
{
    Node<Pair<T>> *p = this->getHead();
    while (p != nullptr)
    {
	   if (p->data.getFirst() == first)
	   {
		  return p->data.getSecond();
	   }
	   p = p->next;
    }
    return "";
}

// #################################################
// @par Name
// smallestFirst
// @purpose
// iterates through the first value of each pair and
// determines the smallest value
// @param [in] :
// None
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::smallestFirst()
{
    Node<Pair<T>> *p = this->getHead();
    T smallest = p->data.getFirst();

    while (p != nullptr)
    {
	   if (p->data.getFirst() < smallest)
	   {
		  smallest = p->data.getFirst();
	   }
	   p = p->next;
    }
    return smallest;
}

// #################################################
// @par Name
// smallestSecond
// @purpose
// iterates through the second value of each pair and
// determines the smallest value
// @param [in] :
// None
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::smallestSecond()
{
    Node<Pair<T>> *p = this->getHead();
    T smallest = p->data.getSecond();

    while (p != nullptr)
    {
	   if (p->data.getSecond() < smallest)
	   {
		  smallest = p->data.getSecond();
	   }
	   p = p->next;
    }
    return smallest;
}

// #################################################
// @par Name
// largestFirst
// @purpose
// iterates through the first value of each pair and
// determines the largest value
// @param [in] :
// None
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::largestFirst()
{
    Node<Pair<T>> *p = this->getHead();
    T largest = p->data.getFirst();

    while (p != nullptr)
    {
	   if (p->data.getSecond() > largest)
	   {
		  largest = p->data.getFirst();
	   }
	   p = p->next;
    }
    return largest;
}

// #################################################
// @par Name
// largestSecond
// @purpose
// iterates through the second value of each pair and
// determines the largest value
// @param [in] :
// None
// @return
// data type T, dependent on the type that PairList holds
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
T PairList<T>::largestSecond()
{
    Node<Pair<T>> *p = this->getHead();
    T largest = p->data.getSecond();

    while (p != nullptr)
    {
	   if (p->data.getSecond() > largest)
	   {
		  largest = p->data.getSecond();
	   }
	   p = p->next;
    }
    return largest;
}

// #################################################
// @par Name
// deletePair
// @purpose
// removes a pair from the PairList
// @param [in] :
// first - first value in the pair to be deleted
// second - second value in the pair to be deleted
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void PairList<T>::deletePair(T first, T second)
{
    Pair<T> pair(first, second);
    Node<Pair<T>> *p = this->getHead();

    if (p->data == pair)
    {
	   this->setHead(p->next);
	   delete p;
    }
    else
    {
	   while (p->next->data != pair)
	   {
		  p = p->next;
		  if(p == nullptr)
		  {
			 break;
		  }
	   }
	   Node<Pair<T>> *delPtr = p->next;
	   p->next = p->next->next;
	   delete delPtr;
    }
}

// #################################################
// @par Name
// contains
// @purpose
// tests if a pair with a certain first member exists
// within the PairList
// @param [in] :
// T search - data to be searched for
// @return
// int
// @par References
// None
// @par Notes
// None
//##################################################
template<class T>
bool PairList<T>::contains(T search)
{
    Node<Pair<T>> *p = this->getHead();
    while (p != nullptr) {
	   if (p->data.getFirst() == search)
		  return true;
	   p = p->next;
    }
    return false;
}

// #################################################
// @par Name
// printList
// @purpose
// displays the PairList (each pair on a new line)
// @param [in] :
// None
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void PairList<T>::printList()
{
    Node<Pair<T>> *p = this->getHead();
    int offset{ 0 };

    while (p != nullptr)
    {
	   cout << p->data.getFirst() << " (" << p->hashVal << " - " << offset << ") " << p->data.getSecond() << endl;

	   p = p->next;
	   offset++;
    }
}

// #################################################
// @par Name
// getOffset
// @purpose
// determines the offset of a pair within a PairList
// into a HashTable
// @param [in] :
// T search - value of first member of pair of the offset we want
// @return
// int
// @par References
// None
// @par Notes
// None
//##################################################
template<class T>
int PairList<T>::getOffset(T search) const
{
    Node<Pair<T>> *p = this->getHead();
    int offset{};
    while (p != nullptr) {
	   if (p->data.getFirst() == search)
		  return offset;
	   p = p->next;
	   offset++;
    }
    return NULL;
}
