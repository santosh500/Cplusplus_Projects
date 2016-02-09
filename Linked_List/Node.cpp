/**
File Name: Node.cpp
Author: Paul Charles
Date: 09.23.2015
Purpose: Source file that contains Node functions
**/
#include "Node.h"
#include "LinkedList.h"

using namespace std;

Node::Node()
{
    Node::m_value=0;
    m_next=nullptr;
}

void Node::setValue(int val)
{
    Node::m_value=val;
}

int Node::getValue()const
{
    return m_value;
}

void Node::setNext(Node* prev)
{
    m_next=prev;
}

Node* Node::getNext()const
{
    return Node::m_next;
}


