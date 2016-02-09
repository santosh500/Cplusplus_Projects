/**
File Name: DoubleLinkedList.h
Author: Paul Charles
Date: 09.29.2015
Purpose: .h file for DoubleLinkedList.hpp
**/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <cstdlib>
#include "Node.h"
#include <stdexcept>
using namespace std;
template <typename T>
class DoubleLinkedList
{
   public:
       DoubleLinkedList();
       /**
	*  @pre None
	*  @post Creates and initializes a DoubleLinkedList instance
	*  @return Initialzed DoubleLinkedList private variables
	*/
       ~DoubleLinkedList();
       /**
	*  @pre None
	*  @post Deconstructs DoubleLinkedList and nodes after program ends from main
	*  @return none
	*/
       bool isEmpty()const;
       /**
	*  @pre DoubleLinkedlist must contain no nodes or size=0
	*  @post Returns value if empty or not
	*  @return Returns true or false
	*/
       int size()const;
       /**
	*  @pre m_size value
	*  @post Deterimnes size of list and returns it
	*  @return m_size value
	*/
       void pushFront(T value);
       /**
	*  @pre Integer value
	*  @post Adds value to front of list
	*  @return none
	*/
       void pushBack(T value);
       /**
	*  @pre Integer value
	*  @post Adds value to back of list
	*  @return none
	*/
       void printList()const;
       /**
	*  @pre None
	*  @post Prints list of nodes in linkedlist.
	*  @return none
	*/
       bool removeBack();
      /**
	*  @pre At least one node in list
	*  @post Removes the last node in list
	*  @return true if removed and false if not removed
	*/
       bool removeFront();
       /**
	*  @pre At least one node in list
	*  @post Removes the first node in the list
	*  @return true if removed and false if not removed
	*/
       bool remove(T value);
      /**
	*  @pre At least one node in list and a changed node
	*  @post Removes the chosen node in the list
	*  @return true if removed and false if not removed
	*/
      void insertAhead(T listValue, T newvalue)throw (std::runtime_error);
      /**
	*  @pre Integer value to be searched in list and a changed value
	*  @post Searches list and returns boolean value
	*  @return true if value is in list and false if not in list or list is empty
	*/
       void insertBehind(T listValue, T newValue)throw(std::runtime_error);
       /**
	*  @pre Integer value to be searched in list and a changed value
	*  @post Searches list and returns boolean value
	*  @return true if value is in list and false if not in list or list is empty
	*/
       Node<T>* find(T value) const;
       /**
	*  @pre Integer value to be searched in list
	*  @post Searches list and returns node
	*  @return Returns if value is in list and doesnt if not in list or list is empty
	*/
   private:
      Node<T>* m_front;
      Node<T>* m_back;
      int m_size;
};
#include "DoubleLinkedList.hpp"
#endif 
