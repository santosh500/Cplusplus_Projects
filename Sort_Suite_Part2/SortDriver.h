/**
File Name: SortDriver.h
Author: Paul Charles
Date: 11.03.2015
Purpose: File that contains the SortDriver prototypes
**/
#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <string>
#include <functional>
#include "NumberFileGenerator.h"
#include "Sorts.h"
using namespace std;

class SortDriver
{
public:
    static void run(int arc, char** argv);
    static void printHelpMenu();
    
  private: 
    static bool isFileAccessible(string fileName);
    static bool isSortValid(string sortParameter);
    static bool areParametersValid(string sortName, string inputFileName);
    static int getFileCount(ifstream& inputFile);
    static int* createArray(ifstream& inputFile, int size);
    static void copyArray(int original[], int copy[], int size);
    
};

#endif
