/**
File Name: main.cpp
Author: Paul Charles
Date: 10.07.2015
Purpose: Main file
**/
#include <iostream>
#include "Stack.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include "Test.h"
#include <string>
#include <stdexcept> 
void printMenu();
using namespace std;
int main()
{
     StackInterface<int>* q=new Stack<int>();
     int a=0;
     while(a!=5)
     {  
        printMenu();
        cin >> a;
        if(a==1)
        {
             int val;
             cin >> val;
             q->push(val);
        }
        else if(a==2)
        {
            cout << q->peek() << endl;
        }
        else if(a==3)
        {
            q->print();
        }
        else if(a==4)
        {
            q->pop();
        }
        else if(a==6)
        {
            Test myTester(std::cout); //declares a Test instance
            myTester.runTests(); //runs a series of tests on your code
                                //attempt something risky
        }
     }
    delete q;

}

void printMenu()
{
     std::cout <<    "\n\nMake choice\n"
                <<      "1) Add to stack 1\n"
                <<      "2) See what is at the top of the stack\n"
                <<      "3) Print all stack\n"
                <<      "4) Pop stack\n"
                <<      "5) Quit\n"
                <<      "6) Run Tests\n"
                <<      "Your choice: ";
                
                

}