/**
File Name: NumberFileGenerator.cpp
Author: Paul Charles
Date: 11.03.2015
Purpose: Contains functions for NumberFileGenerator class
**/
#include "NumberFileGenerator.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;

void NumberFileGenerator::ascending(string filename, int amount)
{
    ofstream myOutputFile(filename);
    myOutputFile << amount << endl;
    for(int i=1; i<amount; i++)
    {
        myOutputFile << i << endl;
    }
    myOutputFile << amount;


}
void NumberFileGenerator::descending(string filename, int amount)
{
    ofstream myOutputFile(filename);
    myOutputFile << amount << endl;
    for(int i=amount; i>1; i--)
    {
        myOutputFile << i << endl;
    }
    myOutputFile << 1;

}
void NumberFileGenerator::random(string filename, int amount, int min, int max)
{
    ofstream myOutputFile(filename);
    myOutputFile << amount << endl;
    default_random_engine generator(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);

    int randomNumber;
    for(int i=1; i<amount; i++)
    {
        randomNumber=distribution(generator);
        myOutputFile << randomNumber << endl;
    }
    randomNumber=distribution(generator);
    myOutputFile << randomNumber;
}
void NumberFileGenerator::singleValue(string filename, int amount, int value)
{
    ofstream myOutputFile(filename);
    myOutputFile << amount << endl;
    for(int i=1; i< amount; i++)
    {
        myOutputFile << value << endl;
    }
    myOutputFile << value;

}
