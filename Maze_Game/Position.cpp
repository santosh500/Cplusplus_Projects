/**
File Name: Position.cpp
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the Position functions
**/
#include <iostream>
#include "MazeReader.h"
#include <string>
using namespace std;
Position::Position(int row, int col)
{
    m_row=row;
    m_col=col;
}

int Position::getRow() const
{
    return m_row;
}

int Position::getCol() const
{
    return m_col;
}
