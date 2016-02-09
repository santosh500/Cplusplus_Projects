/**
File Name: LinkedList.h
Author: Paul Charles
Date: 09.23.2015
Purpose: Header file that contains linked list functions
**/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;
class LinkedList
{
    public:
        LinkedList();
	/**
	*  @pre None
	*  @post Creates and initializes a LinkedList instance
	*  @return Initialzed LinkedList private variables
	*/
        ~LinkedList();
	/**
	*  @pre None
	*  @post Deconstructs linkedlist and nodes after program ends from main
	*  @return none
	*/
        void addBack(int val);
	/**
	*  @pre Integer value
	*  @post Adds value to back of list
	*  @return none
	*/
        void addFront(int value);
	/**
	*  @pre Integer value
	*  @post Adds integer value to a created node in the front of the list
	*  @return none
	*/
        void printList();
	/**
	*  @pre None
	*  @post Prints list of nodes in linkedlist.
	*  @return none
	*/
        bool isEmpty()const;
	/**
	*  @pre Linkedlist must contain no nodes or size=0
	*  @post Returns value if empty or not
	*  @return Returns true or false
	*/
        int size()const;
	/**
	*  @pre m_size value
	*  @post Deterimnes size of list and returns it
	*  @return m_size value
	*/
        bool removeFront();
	/**
	*  @pre At least one node in list
	*  @post Removes the first node in the list
	*  @return true if removed and false if not removed
	*/
        bool removeBack();
	/**
	*  @pre At least one node in list
	*  @post Removes the last node in list
	*  @return true if removed and false if not removed
	*/
        bool search(int value) const;
	/**
	*  @pre Integer value to be searched in list
	*  @post Searches list and returns boolean value
	*  @return true if value is in list and false if not in list or list is empty
	*/

    protected:
    private:
        int m_size;
        Node* m_front;

};

#endif // LINKEDLIST_H
