//#################################################
// File: LinkedList.h
// Author: Nicholas Campos
// Description: This file contains the struct to Node
//			 and the LinkedList template class
// Date: February 26th, 2022
//#################################################

#include <iostream>

using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node
{
    T data;
    int hashVal;
    Node *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList();
    void printList();
    void addToEnd(T data, int hashVal);
    void addToStart(T data, int hashVal);
    void insert(T search, T value, int hashVal);
    void deleteNode(T search);
    bool contains(T search) const;
    Node<T>* getHead() const;
    void setHead(Node<T> *nodePtr);
};

#endif

// #################################################
// @par Name
// LinkedList (default constructor)
// @purpose
// creates an empty linked list that points to a nullptr
// @param [in] :
// None
// @return
// empty LinkedList
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
}

// #################################################
// @par Name
// printList
// @purpose
// prints the entire list
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
void LinkedList<T>::printList()
{
    Node<T> *p = this->head;
    while (p != nullptr)
    {
	   cout << p->data.c_str() << endl;
	   p = p->next;
    }
}

// #################################################
// @par Name
// addToEnd
// @purpose
// adds an object to the end of the linked list
// @param [in] :
// T data - object to be added to the list
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void LinkedList<T>::addToEnd(T data, int hashVal)
{
    if (head == nullptr)
    {
	   head = new Node<T>;
	   head->data = data;
	   head->hashVal = hashVal;
	   head->next = nullptr;
    }
    else
    {
	   Node<T> *p = this->head;

	   while (p->next != nullptr)
	   {
		  p = p->next;
	   }

	   Node<T> *n = new Node<T>;
	   n->data = data;
	   n->hashVal = hashVal;
	   n->next = nullptr;

	   p->next = n;
    }
}

// #################################################
// @par Name
// addToStart
// @purpose
// adds an object to the start of the linked list
// @param [in] :
// T data - object to be added to the list
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void LinkedList<T>::addToStart(T data, int hashVal)
{
    Node<T> *n = new Node<T>;
    n->data = data;
    n->hashVal = hashVal;
    n->next = this->head;

    this->head = n;
}

// #################################################
// @par Name
// insert
// @purpose
// inserts an object after a certain object in the linked list
// @param [in] :
// T data - object to be inserted to the list
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void LinkedList<T>::insert(T search, T value, int hashVal)
{
    Node<T> *p = this->head;
    while (p->data != search)
    {
	   p = p->next;
    }
    Node<T> *n = new Node<T>;
    n->data = value;
    n->hashVal = hashVal;
    n->next = p->next;
    p->next = n;
}

// #################################################
// @par Name
// deleteNode
// @purpose
// deletes an object from the linked list
// @param [in] :
// T search - searches for search by parsing the list
//		    and removes the following node
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
void LinkedList<T>::deleteNode(T search)
{
    Node<T> *p = this->head;
    if (p->data == search)
    {
	   this->head = p->next;
	   delete p;
    }
    else
    {
	   while (p->next->data != search)
	   {
		  p = p->next;
	   }

	   Node<T> *delPtr = p->next;
	   p->next = p->next->next;
	   delete delPtr;
    }
}

// #################################################
// @par Name
// contains
// @purpose
// determines if a specific node exists within the
// linked list
// @param [in] :
// T search - object to be searched for
// @return
// boolean value
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
bool LinkedList<T>::contains(T search) const
{
    Node<T> *p = this->head;
    while (p != nullptr)
    {
	   if (p->data == search)
	   {
		  return true;
	   }
	   p = p->next;
    }
    return false;
}

// #################################################
// @par Name
// getHead
// @purpose
// returns the address of the head of the linked list
// @param [in] :
// None
// @return
// address value
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
Node<T> *LinkedList<T>::getHead() const
{
    return this->head;
}

// #################################################
// @par Name
// setHead
// @purpose
// changes the address of the head of the linked list
// @param [in] :
// T data - object to be added to the list
// @return
// None
// @par References
// None
// @par Notes
// user needs to delete memory of old head after calling
// this method
//##################################################

template<class T>
void LinkedList<T>::setHead(Node<T> *nodePtr)
{
    this->head = nodePtr;
}