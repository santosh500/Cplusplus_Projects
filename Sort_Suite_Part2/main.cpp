/**
File Name: main.cpp
Author: Paul Charles
Date: 11.03.2015
Purpose: Main file
**/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Sorts.h"
#include "SortDriver.h"
#include "Test.h"
#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"


int main(int argc, char** argv)
{
    string mode;
    if(argc>=2)
    {
        mode=argv[1];

        if(mode == "-create")
        {
            NumberFileDriver::run(argc, argv);		
        }

        else if (mode == "-sort")
        {
            SortDriver::run(argc, argv);
        }

        else if (mode == "-test")
        {       
            Test a(std::cout);
            a.runTests();
        }
        else
        {
            SortDriver a;
            a.printHelpMenu();

            NumberFileDriver b;
            b.printHelpMenu();
        }
    
    }
    else
    {
        SortDriver a;
        a.printHelpMenu();
        
        NumberFileDriver b;
        b.printHelpMenu();
    }    


}


