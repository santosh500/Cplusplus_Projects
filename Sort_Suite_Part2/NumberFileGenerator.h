/**
File Name: NumberFileGenerator.h
Author: Paul Charles
Date: 11.03.2015
Purpose: Contains prototypes for NumberFileGenerator class
**/
#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class NumberFileGenerator
{
  public:
    static void ascending(string filename, int amount);
    /**
    *  @pre filename and amount
    *  @post creates an input file in ascending form
    *  @return none
    */
    static void descending(string filename, int amount);
    /**
    *  @pre filename and amount
    *  @post creates an input file in descending form
    *  @return none
    */
    static void random(string fileName, int amount, int min, int max);
        /**
    *  @pre filename, amount, min, and max
    *  @post creates an input file with random values
    *  @return none
    */
    static void singleValue(string fileName, int amount, int value);
    /**
    *  @pre filename, amount, and a single value
    *  @post creates an input file with a single value a number of times
    *  @return none
    */
    
};

#endif

