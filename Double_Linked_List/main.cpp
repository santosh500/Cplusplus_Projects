/**
File Name: main.cpp
Author: Paul Charles
Date: 09.29.2015
Purpose: Main file
**/
#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "Test.h"
#include <string>
#include <stdexcept>

using namespace std;
void printMenu();
int main()
{

     DoubleLinkedList<int> q;
     int a=0;
     while(a!=9)
     {
        printMenu();
        cin >> a;
                        if(a==1)
                        {
                            int val;
                            cin >> val;
                            q.pushFront(val);

                        }
                        else if(a==2)
                        {
                            int val;
                            cin>>val;
                            q.pushBack(val);
                        }
                        else if(a==3)
                        {
                             try
                            {   
                                int lval;
                            cin>>lval;
                            int val;
                            cin>>val;
                            q.insertBehind(lval,val); 
                            }
                            catch (std::runtime_error& e)
                            {
                            
                            std::cout << e.what() << std::endl;
                            }
                            
                            
                        }
                        else if(a==4)
                        {
                            try
                           {
                                int lval;
                                cin>>lval;
                                int val;
                                cin>>val;
                                q.insertAhead(lval,val);
                           }
                           catch (std::runtime_error& e)
                           {

                           std::cout << e.what() << std::endl;
                           }


                        }
                        else if(a==5)
                        {
                            q.removeFront();
                        }
                        else if(a==6)
                        {
                            q.removeBack();
                        }
                        else if(a==7)
                        {
                            int val;
                            cin>>val;
                            q.remove(val);
                        }
                        else if(a==8)
                        {
                            q.printList();
                        }
                        else if(a==10)
                        {
                             Test myTester(std::cout); //declares a Test instance

                            myTester.runTests(); //runs a series of tests on your code
                                //attempt something risky
                            
                            
                        }
     }
}


void printMenu()
{
     std::cout <<    "\n\nMake choice\n"
                <<      "1) push value onto front\n"
                <<      "2) push value onto back\n"
                <<      "3) insert behind a value\n"
                <<      "4) insert ahead of a value\n"
                <<      "5) remove front value\n"
                <<      "6) remove back value\n"
                <<      "7) remove specific value\n"
                <<      "8) print list\n"
                <<      "9) Quit\n"
                <<      "10) Run Tests\n"
                <<      "Your choice: ";
                
                

}
