/**
File Name: NumberFileDriver.h
Author: Paul Charles
Date: 11.03.2015
Purpose: File that contains the NumberFileDriver prototypes
**/
#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H
#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <string>
#include <functional>
#include "SortDriver.h"
#include "NumberFileGenerator.h"
using namespace std;

class NumberFileDriver 
{
public:
    static void run(int argc, char** argv);
    /**
    *  @pre argc(number of arguments) and arguments
    *  @post runs the NumberFileDriver
    *  @return none
    */
    static void printHelpMenu();
            /**
    *  @pre none valid arguments
    *  @post prints a help menu
    *  @return none
    */
private:
    static bool isValidOption(string option);
    /**
    *  @pre string option
    *  @post determines if command is valid
    *  @return boolean value
    */
};
#endif
