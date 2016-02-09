/**
File Name: DoubleLinkedList.hpp
Author: Paul Charles
Date: 09.29.2015
Purpose: Contains the functions for DoubleLinkedList.hpp
**/
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_front=nullptr;
    m_back=nullptr;
    m_size=0;
}
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
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
template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
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
int DoubleLinkedList<T>::size() const
{
    return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
    Node<T>* temp=nullptr;
    if(isEmpty())
    {   
        m_front=new Node<T>();
        m_front->setValue(value);
        m_back=m_front;
        m_size++;
    }
    else
    {
        
        temp=new Node<T>;
        temp->setNext(m_front);
        temp->setValue(value);
        m_front->setPrev(temp);
        m_front=temp;
        m_front->setPrev(nullptr);
        m_size++;
    }
    
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
    Node<T>* temp;
    Node<T>* transverse;
    if(isEmpty())
    {   
        m_back=new Node<T>();
        m_back->setValue(value);
        m_front=m_back;
        m_size++;
    }
    else
    {
        transverse=m_front;

        while(transverse->getNext()!=nullptr)
        {
            transverse=transverse->getNext();
        }
        temp=new Node<T>();
        temp->setValue(value);
        transverse->setNext(temp);//links the Node
        temp->setPrev(transverse);
        m_back=temp;
        m_size=m_size+1;
    }
    
}

template <typename T>
void DoubleLinkedList<T>::printList()const
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
bool DoubleLinkedList<T>::removeBack()
{
    Node<T>* temp=nullptr;
    Node<T>* transverse=m_front;
    Node<T>* trans2=m_front;
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
        m_back=trans2;
        transverse=nullptr;
        
        return(true);
        
    }
    
}


template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
    Node<T>* temp=nullptr;
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


template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
    Node<T>* transverse;
    Node<T>* temp;
    Node<T>* temp2;
    if(m_size==1)
    {
        temp=m_front;
        if(value==temp->getValue())
        {   
            delete temp;
            temp=nullptr;
            m_front=nullptr;
            m_back=nullptr;
            m_size--;
            return(true);
        }
        else
        {
            return(false);
        }
        
    }
    else
    {
        transverse=m_front;
        while(transverse!=nullptr)
        {
            if(value==transverse->getValue())
            {
                delete transverse;
                temp=transverse->getNext();
                
                if(transverse==m_front)
                {
                    m_size--;
                    temp->setPrev(nullptr);
                    transverse=nullptr;
                    m_front=temp;
                    
                }
                else if(transverse==m_back)
                {
                    m_size--;
                    temp2=transverse->getPrev();
                    temp2->setNext(nullptr);
                    transverse=nullptr;
                    m_back=temp2;
                }
                else
                {
                    m_size--;
                    temp2=transverse->getPrev();
                    temp2->setNext(temp);
                    temp->setPrev(temp2);
                    transverse=nullptr;
                }
                
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
/*
 */ 
template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue)throw (std::runtime_error)
{
    
    Node<T>* temp3=find(listValue);
    Node<T>* temp=nullptr;
    Node<T>* temp4=nullptr;
    if(temp3)
    {
        if(m_front==temp3)
        {
            m_size++;
            temp4=new Node<T>();
            temp4->setValue(newValue);
            temp3->setPrev(nullptr);
            temp4->setNext(m_front);
            temp3->setPrev(temp4);
            temp4->setPrev(nullptr);
            m_front=temp4;
            
        }
        else
        {
            
            m_size++;
            temp=temp3->getPrev();
            temp3->setPrev(nullptr);
            temp->setNext(nullptr);
            temp4=new Node<T>();
            temp4->setValue(newValue);
            temp4->setPrev(temp);
            temp4->setNext(temp3);
            temp3->setPrev(temp4);
            temp->setNext(temp4);

        }
        
    }
    else if(!temp3)
    {
        throw(std::runtime_error("Not a list value"));
    }
     
}


template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue)throw (std::runtime_error)
{
    Node<T>* temp3=find(listValue);
    Node<T>* temp=nullptr;
    Node<T>* temp4=nullptr;
    if(temp3)
    {
        
        if(m_back==temp3)
        {
            m_size++;
            temp4=new Node<T>();
            temp4->setValue(newValue);
            temp3->setNext(nullptr);
            temp4->setPrev(m_back);
            temp3->setNext(temp4);
            temp4->setPrev(temp3);
            m_back=temp4;
            
        }
        else
        {
            m_size++;
            temp=temp3->getNext();
            temp3->setNext(nullptr);
            temp->setPrev(nullptr);
            temp4=new Node<T>();
            temp4->setValue(newValue);
            temp4->setPrev(temp3);
            temp4->setNext(temp);
            temp3->setNext(temp4);
            temp->setPrev(temp4);

        }
        
    }
    else
    {
        throw(std::runtime_error("Not a value in list"));
    }
     
}
 
template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
    Node<T>* temp;
    Node<T>* transverse;
    
    transverse=m_front;
    while(transverse!=nullptr)
    {
        if(value==transverse->getValue())
        {
            temp=transverse;
            return(temp);
        }
        {
           transverse=transverse->getNext(); 
        }
        
        
    }
    temp=nullptr;
    return(nullptr);
    
}
 
