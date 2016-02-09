
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
/**
File Name: BinarySearchTree.h 
Author: Paul Charles
Date: 11.11.2015
Purpose: File contains the BinarySearchTree method prototypes
**/
#include <vector>
#include "Node.h"
#include "BSTI.h"
using namespace std;

template <typename T>
class BinarySearchTree:public BSTI<T>
{
private:
	Node<T>* m_root;
	bool add(T value, Node<T>* subtree);
        /**
        *  @pre value, subtree
        *  @post adds value to BinarySearchTree
        *  @return boolean
        */
	void deleteTree(Node<T>* subTree);
        /**
        *  @pre subtree
        *  @post deletes subtree
        *  @return none
        */
	bool search(T value, Node<T>* subtree)const;
        /**
        *  @pre value, subtree
        *  @post searches subtree and returns boolean value
        *  @return boolean value
        */
	void printTree(Node<T>* subtree, Order order)const;
        /**
        *  @pre subtree, order
        *  @post prints BinarySearchTree
        *  @return none
        */
        void treeToVector(Node<T>* subtree, Order order, vector<T>& vec) const; 
                /**
        *  @pre left pointer
        *  @post sets left pointer to object
        *  @return none
        */
public:
	BinarySearchTree();
        /**
        *  @pre object created
        *  @post sets left pointer to object
        *  @return none
        */
	BinarySearchTree(const BinarySearchTree<T>& other);
        /**
        *  @pre previous BinarySearchTree
        *  @post copy constructor of BinarySearchTree
        *  @return none
        */
	~BinarySearchTree();
        /**
        *  @pre BinarySearchTree
        *  @post deletes tree
        *  @return none
        */
        BSTI<T>* clone();
        /**
        *  @pre previous BinarySearchTree object
        *  @post creates new BinarySearchTree
        *  @return none
        */
	bool isEmpty()const;
        /**
        *  @pre tests if empty
        *  @post checks if empty
        *  @return boolean value
        */
	bool add(T value);
        /**
        *  @pre value
        *  @post adds value to tree
        *  @return boolean value
        */
	bool search(T value)const;
        /**
        *  @pre value
        *  @post searches for value
        *  @return boolean value
        */
	void printTree(Order order)const;
        /**
        *  @pre BinarySearchTree and order
        *  @post prints tree according ot order
        *  @return none
        */
	vector<T> treeToVector(Order order)const;
        /**
        *  @pre order and BinarySearchTree
        *  @post creates a vector according to order
        *  @return vector
        */

};
#include "BinarySearchTree.hpp"
#endif
