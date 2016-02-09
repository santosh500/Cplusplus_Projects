/**
File Name: PreconditionViolationException.cpp
Author: Paul Charles
Date: 10.07.2015
Purpose: Derived class from runtime_error that contains the methods
**/
#include<iostream>
#include <stdexcept>
#include <cstdlib>
#include "PreconditionViolationException.h"
using namespace std;

PreconditionViolationException::PreconditionViolationException(const char* msg):std::runtime_error(msg)
{
    //Leave Empty
    //Calls constructor
}