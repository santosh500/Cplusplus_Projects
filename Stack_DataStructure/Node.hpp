/**
File Name: Node.hpp
Author: Paul Charles
Date: 09.29.2015
Purpose: Contains functions for Node.hpp
**/
#include <iostream>

//#include "LinkedList.h"

using namespace std;


template <typename T>
Node<T>::Node()
{
   m_next=nullptr;
   m_previous=nullptr;
   m_value=T();
}

template <typename T>
T Node<T>::getValue()const
{
   return(m_value);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
   m_next=next;
}

template <typename T>
void Node<T>::setValue(T val)
{
   m_value=val;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
   return(m_next);
}

template <typename T>
Node<T>* Node<T>::getPrev() const
{
   return(m_previous);
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{
   m_previous=prev;
}
