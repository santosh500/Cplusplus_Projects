/**
File Name: main.cpp
Author: Paul Charles
Date: 11.11.2015
Purpose: File that contains the main.cpp
**/
#include <iostream>
#include <fstream>
#include <climits>
#include <random>
#include <ctime>
using namespace std;
#include "Node.h"
#include "BinarySearchTree.h"
#include "BSTI.h"
#include "Test.h"

void printMenu();
int main(int argc, char** argv)
{ 
    string mode="";
    BSTI<int>* a=new BinarySearchTree<int>();

    string number="";
    int i=0;
    if(argc>=2)
    {
        mode=argv[1];
        
        if(mode == "-test")
        {
              Test a;
              a.runTests();
        }
        else if(mode == "-nodes")
        {   
            number=argv[2];
            random_device randomDevice;
            default_random_engine generator(randomDevice());
            uniform_int_distribution<int> distribution(0,INT_MAX); 
            for(int f=0; f< stoi(number); f++);
            {
                int randomnumber;
                randomnumber=distribution(generator);
                a->add(randomnumber);
            }
            do
            {
                
                printMenu();
                cin >> i;
                if(i == 1)
                {
                    cout << "Please give a value: " << endl;
                    int g;
                    cin >> g;
                    
                }
                else if(i == 2)
                {
                    a->clone();
                }
                else if( i== 3)
                {
                    delete a;
                }
                else if(i == 4)
                {
                    int q;
                    cout << "Which order would you like to print" << endl;
                    cout << "1) PRE_ORDER" << endl;
                    cout << "2) IN_ORDER" << endl;
                    cout << "3) POST_ORDER" << endl;
                    cin >> q;
                    if(q==1)
                    {
                        a->printTree(PRE_ORDER);                        
                    }
                    else if(q==2)
                    {
                        a->printTree(IN_ORDER);
                    }
                    else
                    {
                        a->printTree(POST_ORDER);
                    }

                }
                else if(i==5)
                {

                }
                else if(i==6)
                {
                    cout << "What value would you like to search" << endl;
                    int o;
                    cin >> o;
                    
                    if(a->search(o)==true)
                    {
                        cout << "Value Found" << endl;
                    }
                    else
                    {
                        cout << "Value not Found" << endl;
                    }
                    
                }
                else if(i==9)
                {
                    Test b;
                    b.runTests();
                }
                }while(i!=8);
        }
    }
    else
    {
        printMenu();
    }
    delete a;
    
}

void printMenu()
{
     std::cout <<    "\n\nInput a selection\n"
                <<      "1) Add more values to original tree\n"
                <<      "2) Copy the original tree\n"
                <<      "3) Delete the original tree (one time only)\n"
                <<      "4) Print original tree\n"
                <<      "5) Print copy\n"
                <<      "6) Search original tree\n"
                <<      "7) Search copy\n"
                <<      "8) Exit\n"
                <<      "9) Run Tests\n"
                <<      "Your choice: ";



}

