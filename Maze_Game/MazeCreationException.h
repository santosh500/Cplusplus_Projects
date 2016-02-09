/**
File Name: MazeCreationException.h
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeCreationException prototypes
**/
#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
using namespace std;

class MazeCreationException:public runtime_error
{
    public:
    /**
     * @pre none
     * @post Creates an exception with the message
     * @return message
     */
     MazeCreationException(const char* message);
};
#endif
