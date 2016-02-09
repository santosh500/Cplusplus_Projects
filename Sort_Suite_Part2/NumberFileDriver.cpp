/**
File Name: NumberFileDriver.cpp
Author: Paul Charles
Date: 11.03.2015
Purpose: Contains functions for NumberFileDriver class
**/
#include <iostream>
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"
using namespace std;

void NumberFileDriver::run(int argc, char** argv)
{
    string a;
    a=argv[2];
    isValidOption(a);    
        if(a=="-a")
        {
        

            NumberFileGenerator a;
            string b=argv[3];
            string g=argv[4];
            int v=stoi(g);
            
            a.ascending(b,v);

        }
        else if(a=="-d")
        {
            
            NumberFileGenerator a;
            cout << "give a filename" << endl;
            string b=argv[3];
            cout << "give an amount" << endl;
            string g=argv[4];
            int v=stoi(g);
            a.descending(b,v);

        }
        else if(a=="-r")
        {
            NumberFileGenerator a;
            cout << "give a filename" << endl;
            string b=argv[3];
            cout << "give an amount" << endl;
            string g=argv[4];
            int y=stoi(g);
            cout << "give a minimum" << endl;
            string h=argv[5];
            int r=stoi(h);
            cout << "give a maximum" << endl;
            string i=argv[6];
            int j=stoi(i);
            a.random(b,y,r,j);
        

        }
        else if(a=="-s")
        {  
       
            NumberFileGenerator a;
            cout << "give a filename" << endl;
            string b=argv[3];
            cout << "give an amount" << endl;
            string g=argv[4];
            int w=stoi(g);
            cout << "give a single value" << endl;
            string n=argv[5];
            int u=stoi(n);
            a.singleValue(b,w,u);
        }
        else
        {
            printHelpMenu();
        }
    
    
    
}

void NumberFileDriver::printHelpMenu()
{
 std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";   
}
bool NumberFileDriver::isValidOption(string option)
{
    
    if(option=="-a")
    {
        return true;
    }
    else if(option=="-d")
    {

 
        return true;
    }
    else if(option=="-r")
    {

 
        return true;          

    }
    else if(option=="-s")
    {

        return true;
    }
    else
    {
        
        printHelpMenu();
        return false;
    }
    
}
