/**
File Name: LinkedList.cpp
Author: Paul Charles
Date: 09.23.2015
Purpose: Source file that contains linked list functions
**/

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
LinkedList::LinkedList()
{
    m_size=0;
    m_front=nullptr;

}

LinkedList::~LinkedList()
{
/*
    while(!isEmpty())
    {
        remove();
    }
   */
    Node* g=m_front;
    Node* change;
    while(g != nullptr)
    {
        change=g->getNext();
        delete g;
        g=change;
    }

}

void LinkedList::addBack(int value)
{
    Node* temp=nullptr;//for new Node creation
    Node* tranverse=nullptr;
    if(m_size==0)
    {m_size=m_size+1;
        m_front=new Node();
        m_front->setValue(value);
        
    }
    else
    {

        tranverse=m_front;

        while(tranverse->getNext()!=nullptr)
        {
            tranverse=tranverse->getNext();
        }
        temp=new Node();
        temp->setValue(value);
        tranverse->setNext(temp);//links the Node
        m_size=m_size+1;
    }

}

void LinkedList::addFront(int value)
{
    
    Node* temp=nullptr;//for new Node creation

    m_size++;
    temp=new Node();
    temp->setValue(value);
    temp->setNext(m_front);
    m_front=temp;

    
}

void LinkedList::printList()
{
    Node* change=m_front;
    while(change != nullptr)
    {
        cout << change->getValue() << endl;
        change=change->getNext();
    }
}

int LinkedList::size()const
{
    return(m_size);
}

bool LinkedList::isEmpty()const
{
    bool returnValue=true;
    if(m_size>0)
    {
        returnValue=false;
    }
    else
    {
        returnValue=true;
    }
    return returnValue;
}

bool LinkedList::removeFront()
{
    Node* temp=nullptr;
    if(isEmpty())
    {
        return(false);
    }
    else
    {
        m_size--;
        temp=m_front;
        m_front=m_front->getNext();
        delete temp;
        temp=nullptr;
        return(true);
    }
}

bool LinkedList::removeBack()
{
    Node* temp=nullptr;
    Node* transverse=m_front;
    Node* trans2=m_front;
    if(isEmpty())
    {
        return(false);
    }
    else
    {
        m_size--;
        while(transverse->getNext()!=nullptr)
        {
            transverse=transverse->getNext();
        }
        while(trans2->getNext()!=transverse)
        {
            trans2=trans2->getNext();
        }
        temp=transverse;
         trans2->setNext(nullptr);
        delete temp;
        temp=nullptr;
       
        transverse=nullptr;
        
        return(true);
        
    }
    
    
    
    

}

bool LinkedList::search(int value) const
{
    Node* transverse=m_front;
    
    if(isEmpty())
    {
            return(false);
    }
    else
    {
        while(transverse!=nullptr)
        {
            if(value==transverse->getValue())
            {
                return(true);
            }
            else
            {
                transverse=transverse->getNext();
            }
        }
    }
    return(false);
    
}
