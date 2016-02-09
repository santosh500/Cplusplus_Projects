/**
File Name: main.cpp
Author: Paul Charles
Date: 09.23.2015
Purpose: Main class of program that allows for it to run.
**/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Test.h"



using namespace std;

int main()
{
   // Node a;
    //int q;
    //Node* g;







        int a=0;
        LinkedList q;
        while(a!=7)
        {
            std::cout << "\n\nSelect from the following menu:\n"
                        << "1) Add to the front of the list\n"
                        << "2) Add to the end of the list\n"
                        << "3) Remove from front of the list\n"
                        << "4) Remove from back of the list\n"
                        << "5) Print the list\n"
                        << "6) Search for value\n"
                        << "7) Exit\n"
                        << "8) Run tests\n"
                        << "Enter your choice: ";


                        cin >> a;
                        if(a==1)
                        {
                            int val;
                            cin >> val;
                            q.addFront(val);

                        }
                        else if(a==2)
                        {
                            int val;
                            cin>>val;
                            q.addBack(val);
                        }
                        else if(a==3)
                        {

                            q.removeFront();
                        }
                        else if(a==4)
                        {
                            q.removeBack();
                        }
                        else if(a==5)
                        {
                            q.printList();
                        }
                        else if(a==6)
                        {
                            int val;
                            cin>>val;
                            if(q.search(val)==true)
                            {
                                cout << "value found" << endl;
                            }
                            else
                            {
                                cout << "No value found" << endl;
                            }
                        }


                        else if(a==8)
                        {
                            Test myTester(std::cout); //declares a Test instance
                            myTester.runTests(); //runs a series of tests on your code
                        }
        }




}
