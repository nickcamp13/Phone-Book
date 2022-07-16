//##################################################
// File: Pair.h
// Author: Nicholas Campos
// Description: This file contains the Pair
//			 template class
// Date: February 26th, 2022
//##################################################

#include <iostream>

#ifndef PAIR_H
#define PAIR_H

template <class T>
class Pair
{
private:
    T mF;
    T mS;

public:
    Pair();
    Pair(T f, T s);
    T getFirst() const;
    T getSecond() const;
    void setFirst(T f);
    void setSecond(T s);
    bool operator==(const Pair &p);
    bool operator!=(const Pair &p);
};

// #################################################
// @par Name
// Pair (default constructor)
// @purpose
// Creates an uninitialized Pair object
// @param [in] :
// None
// @return
// The instance of the class
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
Pair<T>::Pair()
{
}

// #################################################
// @par Name
// Pair (working constructor)
// @purpose
// Creates a Pair object
// @param [in] :
// f - the value used to set the first pair value
// s - the value used to set the second pair value
// @return
// The instance of the class
// @par References
// None
// @par Notes
// None
//##################################################

template <class T>
Pair<T>::Pair(T f, T s) : mF(f), mS(s)
{
}

// #################################################
// @par Name
// getFirst
// @purpose
// accesses the first pair value of a pair instance
// @param [in] :
// None
// @return
// Type T, The first pair value of a pair instance
// @par References
// None
// @par Notes
// const function
//##################################################

template <class T>
T Pair<T>::getFirst() const
{
    return this-> mF;
}

// #################################################
// @par Name
// getSecond
// @purpose
// accesses the second pair value of a pair instance
// @param [in] :
// None
// @return
// Type T, The second pair value of a pair instance
// @par References
// None
// @par Notes
// const function
//##################################################

template <class T>
T Pair<T>::getSecond() const
{
    return this->mS;
}

// #################################################
// @par Name
// setFirst
// @purpose
// sets the first pair value of a pair instance
// @param [in] :
// f - the value used to set a first pair value
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template <class T>
void Pair<T>::setFirst(T f)
{
    this->mF = f;
}

// #################################################
// @par Name
// setSecond
// @purpose
// sets the second pair value of a pair instance
// @param [in] :
// None
// @return
// None
// @par References
// None
// @par Notes
// None
//##################################################

template <class T>
void Pair<T>::setSecond(T s)
{
    this->mS = s;
}

// #################################################
// @par Name
// overloaded == operator
// @purpose
// checks to see if two pairs are equal based on 
// their pair values
// @param [in] :
// p - pair to be tested with passed by const refernce
// @return
// boolean value
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
bool Pair<T>::operator==(const Pair &p)
{
    if (this->mF == p.mF && this->mS == p.mS)
    {
	   return true;
    }
    else
    {
	   return false;
    }
}

// #################################################
// @par Name
// overloaded != operator
// @purpose
// checks to see if two pairs are not equal based on 
// their pair values
// @param [in] :
// p - pair to be tested with passed by const refernce
// @return
// boolean value
// @par References
// None
// @par Notes
// None
//##################################################

template<class T>
bool Pair<T>::operator!=(const Pair &p)
{
    if (this->mF != p.mF || this->mS != p.mS)
    {
	   return true;
    }
    else
    {
	   return false;
    }
}

#endif
