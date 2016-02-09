 /**
File Name: Node.h
Author: Paul Charles
Date: 09.29.2015
Purpose: .h file for Node.hpp
**/
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
template <typename T>
class Node
{
   public:
       Node();
       /**
	*  @pre None
	*  @post Creates and initializes a Node instance
	*  @return Initialzed Node private values
	*/
       void setValue(T val);
       /**
	*  @pre Requires a integer value
	*  @post Sets the value to m_value
	*  @return none
	*/
       T getValue()const;
       /**
	*  @pre Value set by setValue(int)
	*  @post Obtains value of integer type
	*  @return Integer value
	*/
       void setNext(Node<T>* next);
       /**
	*  @pre Requires a node pointer
	*  @post Sets m_next to prev pointer
	*  @return none
	*/
       Node<T>* getNext()const;
       /**
	*  @pre none
	*  @post Gets m_next to prev pointer
	*  @return none
	*/
       void setPrev(Node<T>* prev);
       /**
	*  @pre Requires a node pointer
	*  @post Sets m_previous to prev pointer
	*  @return none
	*/
       Node<T>* getPrev()const;
       /**
	*  @pre none
	*  @post Gets m_previous to prev pointer
	*  @return none
	*/
   private:
       T m_value;
       Node<T>* m_previous;
       Node<T>* m_next;
};
#include "Node.hpp"
#endif 
