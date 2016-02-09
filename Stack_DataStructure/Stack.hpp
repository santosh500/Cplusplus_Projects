/**
File Name: Stack.hpp
Author: Paul Charles
Date: 10.07.2015
Purpose: Derived class that contains the methods
**/
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Node.h"
using namespace std;
template <typename T>
Stack<T>::Stack()
{
    m_front=nullptr;

    m_size=0;
}
template <typename T>
bool Stack<T>::isEmpty()const
{
    bool returnValue=true;
    if(m_size>0)
    {
        returnValue=false;
    }
    else if(m_size==0)
    {
        returnValue=true;
    }
    return returnValue;
  
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
    Node<T>* temp;
      if(m_size==0)
      {
        m_front=new Node<T>();
        m_front->setValue(newEntry);
        m_size++;
      }
      else
      {
          temp=new Node<T>();
          temp->setValue(newEntry);
          temp->setNext(m_front);
          m_front=temp;
          m_size++;
      }
    
}

template <typename T>
void Stack<T>::pop()throw(PreconditionViolationException)
{
    if(!isEmpty())
    {
        Node<T>* temp;
        
        if(m_size==1)
        {   
            m_size--; 
            temp=m_front;
            delete temp;
            temp=nullptr;
            m_front=nullptr;           
        }
        else
        {   m_size--;
           temp=m_front;
           delete temp;
           temp=nullptr;
           m_front=m_front->getNext();
        }
    }
    else
    {
        throw(PreconditionViolationException("Pop attempted on an empty stack"));
    }
}


template <typename T>
T Stack<T>::peek()const throw(PreconditionViolationException)
{
    if (isEmpty()==true)
    {
        throw(PreconditionViolationException("Peek attempted on an empty stack"));
        
    }
    else
    {
        return(m_front->getValue());
    }  
}

template <typename T>
int Stack<T>::size()const
{
    return(m_size);
}


template <typename T>
void Stack<T>::print()const
{
    Node<T>* temp;
    temp=m_front;
    if(isEmpty()==true)
    {
        cout << "";
    }
    else if(isEmpty()==false)
    {
        while(temp!=nullptr)
        {
            cout << temp->getValue() << " " << endl;
            temp=temp->getNext();
        }
       
    }
}

template <typename T>
Stack<T>::~Stack()
{
    Node<T>* g=m_front;
    Node<T>* change;
    while(g != nullptr)
    {
        change=g->getNext();
        delete g;
        g=change;
    }
}
