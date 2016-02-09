/**
File Name: Sorts.h
Author: Paul Charles
Date: 10.27.15
Purpose: Contains the prototypes for Sorts class
**/
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <functional>
using namespace std;
template <typename T>
class Sorts
{
public:
    static void bubbleSort(T arr[], int size);
    /**
    *  @pre array(createTestArray) and it's size
    *  @post sorts array in bubble sort 
    *  @return none
    */
    static bool isSorted(T arr[], int size);
    /**
    *  @pre array(createTestArray) and it's size; also requires a sorting method to have occured
    *  @post checks to see if array is is sorted 
    *  @return boolean value
    */
    static void selectionSort(T arr[], int size);
    /**
    *  @pre array(createTestArray) and it's size
    *  @post sorts array in selection sort 
    *  @return none
    */
    static void insertionSort(T arr[], int size);
    /**
    *  @pre array(createTestArray) and it's size
    *  @post sorts array in insertion sort 
    *  @return none
    */
    static void shuffle(T arr[], int size, default_random_engine& generator);
    /**
    *  @pre array(createTestArray) for bogo sort and it's size; also requires a generator
    *  @post shuffles values in bogo sort
    *  @return none
    */
    static void bogoSort(T arr[], int size);
    /**
    *  @pre array(createTestArray) and it's size, also need shuffle function
    *  @post sorts array in bubblesort 
    *  @return none
    */
    static int* createTestArray(int size, int min, int max);
    /**
    *  @pre size, a lower bound, and an upper bound
    *  @post creates an array
    *  @return the array created
    */
    static double sortTimer(function<void(T[], int)> sort, T arr[], int size);
    /**
    *  @pre sorting method, array, and it's size
    *  @post calculates the time to execute the sort
    *  @return time in double
    */
};
#include "Sorts.hpp"
#endif
