/**
File Name: Node.h
Author: Paul Charles
Date: 09.23.2015
Purpose: Header file that contains linked list functions
**/
#ifndef NODE_H
#define NODE_H

using namespace std;
class Node
{
    public:
        Node();
	/**
	*  @pre None
	*  @post Creates and initializes a Node instance
	*  @return Initialzed Node private values
	*/
        void setValue(int val);
	/**
	*  @pre Requires a integer value
	*  @post Sets the value to m_value
	*  @return none
	*/
        int getValue()const;
	/**
	*  @pre Value set by setValue(int)
	*  @post Obtains value of integer type
	*  @return Integer value
	*/
        void setNext(Node* prev);
	/**
	*  @pre Requires a node pointer
	*  @post Sets m_next to prev pointer
	*  @return none
	*/
        Node* getNext()const;
    protected:
    private:
        int m_value;//initialize to zero in constructor
        Node* m_next;//initialized to nullptr

};

#endif // NODE_H