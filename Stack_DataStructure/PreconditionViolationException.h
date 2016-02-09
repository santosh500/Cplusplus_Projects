/**
File Name: PreconditionViolationException.h
Author: Paul Charles
Date: 10.07.2015
Purpose: Derived class from runtime_error that contains the method prototypes 
**/
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H
#include <iostream>
#include <cstdlib>

#include <stdexcept>
using namespace std;
class PreconditionViolationException:public runtime_error
{
    public:
        PreconditionViolationException(const char* msg);
    
};
#endif 