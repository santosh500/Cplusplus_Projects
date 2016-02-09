/**
File Name: Stack.h
Author: Paul Charles
Date: 10.07.2015
Purpose: Derived class that contains the method prototypes
**/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
using namespace std;
template <typename T>
class Stack:public StackInterface<T>
{
    public:
        Stack();
        /**
	*  @pre Constructor
	*  @post Initializes private variables
	*  @return none
	*/
        bool isEmpty()const;
        /**
	*  @pre None
	*  @post Determines whether stack is empty or not
	*  @return Method used to return true or false if empty
	*/
        ~Stack();
        /**
	*  @pre None
	*  @post Deconstructor for base class
	*  @return none
	*/
        void push(const T newEntry);
        /**
	*  @pre newEntry value for defined type T
	*  @post Method for putting a value in the stack
	*  @return none
	*/
        void pop()throw(PreconditionViolationException);
        /**
	*  @pre none
	*  @post Method for removing a value from the stack
	*  @return none
	*/
        T peek() const throw(PreconditionViolationException);
         /**
	*  @pre none
	*  @post Virtual method for finding returning the top value
	*  @return Returns the top value in the stack of type T
	*/
        int size()const;
          /**
	*  @pre none
	*  @post Method for determining size of stack
	*  @return Size of stack
	*/
        void print()const;
        /**
	*  @pre none
	*  @post Method for printing values in the stack
	*  @return none
	*/
    private:
        Node<T>* m_front;
        int m_size;

};
#include "Stack.hpp"
#endif 