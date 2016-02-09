/**
File Name: MazeCreationException.cpp
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeCreationException functions
**/
#include "MazeCreationException.h"
using namespace std;

 MazeCreationException::MazeCreationException(const char* message):std::runtime_error(message)
 {

 }
