/**
File Name: PreconditionViolationException.h
Author: Paul Charles
Date: 10.07.2015
Purpose: Derived class from runtime_error that contains the method prototypes 
**/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include <cstdlib>
#include "PreconditionViolationException.h"
#include <stdexcept>
using namespace std;
template <typename T>

class StackInterface
{
    public:
    virtual bool isEmpty()const=0;
     /**
	*  @pre None
	*  @post Determines wheter empty or not
	*  @return Virtual method used to return true or false if empty
	*/
    virtual~StackInterface(){};
     /**
	*  @pre None
	*  @post Virtual deconstructor for base class
	*  @return none
	*/
    virtual void push(const T newEntry)=0;
     /**
	*  @pre newEntry value for defined type T
	*  @post Virtual method for putting a value in the stack
	*  @return none
	*/
    virtual void pop()throw(PreconditionViolationException)=0;
      /**
	*  @pre none
	*  @post Virtual method for removing a value from the stack
	*  @return none
	*/
    virtual T peek() const throw(PreconditionViolationException)=0;
      /**
	*  @pre none
	*  @post Virtual method for finding returning the top value
	*  @return Returns the top value in the stack of type T
	*/
    virtual int size()const=0;
      /**
	*  @pre none
	*  @post Virtual method for determining size of stack
	*  @return Size of stack
	*/
    virtual void print()const=0;
      /**
	*  @pre none
	*  @post Virtual method for printing values in the stack
	*  @return none
	*/
    
};

#endif 