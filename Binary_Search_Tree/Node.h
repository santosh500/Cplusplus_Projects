/**
File Name: Node.h 
Author: Paul Charles
Date: 11.11.2015
Purpose: File contains the Node method prototypes
**/
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
	Node<T>* m_left;
	Node<T>* m_right;
	T m_value;
public:
	Node();
        /**
        *  @pre object created
        *  @post none 
        *  @return none
        */
	Node(const Node<T>& other);
        /**
        *  @pre copyable Node 
        *  @post transfer node 
        *  @return none
        */
	T getValue();
        /**
        *  @pre value needed
        *  @post obtains value 
        *  @return value
        */
	Node<T>* getLeft();
        /**
        *  @pre Node created 
        *  @post left pointer obtained
        *  @return left pointer
        */
	Node<T>* getRight();
        /**
        *  @pre Node created 
        *  @post right pointer obtained
        *  @return right pointer
        */
	void setValue(T value);
        /**
        *  @pre value
        *  @post value set
        *  @return none
        */
	void setLeft(Node<T>* left);
        /**
        *  @pre left pointer
        *  @post sets left pointer to object
        *  @return none
        */
	void setRight(Node<T>* right);
        /**
        *  @pre right pointer
        *  @post sets right pointer to object
        *  @return none
        */

};
#include "Node.hpp"
#endif