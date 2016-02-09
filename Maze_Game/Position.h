/**
File Name: Position.h
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the Position prototypes
**/
#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <string>
#include <functional>
#include <cassert>
#include <fstream>
using namespace std;

class Position
{
public:
   Position(int row=0, int col=0);
   int getRow() const;
   int getCol() const;
private:
    int m_row;
    int m_col;
};
#endif
