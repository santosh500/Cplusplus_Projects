/**
File Name: BSTI.h
Author: Paul Charles
Date: 11.11.2015
Purpose: File contains the BSTI prototypes
**/
#ifndef BSTI_H
#define BSTI_H
#include <iostream>
#include <vector>
using namespace std;
enum Order{PRE_ORDER, IN_ORDER,POST_ORDER};
template <typename T>
class BSTI
{
public:
	
	virtual void printTree(Order order)const = 0;
        /** 
         * @pre Order
         * @post the contents of the tree are printed to the console in the specified order
         * @return none
         */
	virtual vector<T> treeToVector(Order order)const = 0;    
        /**
         * @pre Order
         * @post returns vector with trees contents
         * @return a vector with the contents of the tree in the specified order is returned
         */
        virtual ~BSTI<T>() {};
        /**
        *  @pre A BSTI exists
        *  @post Deletes the entire tree
        *  @return none
        */
	virtual BSTI<T>* clone() = 0;
        /**
        *  @pre this is in a valid state
        *  @post creates a deep copy of this
        *  @return returns pointer to deep copy of this
        */
	virtual bool isEmpty() const = 0;
        /**
        *  @pre none
        *  @post none
        *  @return true if no nodes in the tree, otherwise returns false
        */
	virtual bool add(T value) = 0;
        /**
        *  @pre value is a valid T
        *  @post a new Node<T> is created an inserted into the tree base
        *  @return false if the value couldn't be added
        */
	virtual bool search(T value)const = 0;
        /**
        *  @pre They type T is comparable by the == operator
        *  @post searches T value
        *  @return true if the value is in the tree, false otherwise
        */

        
};
#endif

