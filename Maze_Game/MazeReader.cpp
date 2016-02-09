/**
File Name: MazeReader.cpp
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeReader functions
**/
#include <iostream>
#include "MazeReader.h"
#include <string>
using namespace std;


MazeReader::MazeReader(string file) throw (MazeCreationException)
{
    ifstream mread(file);
    if(mread.good())
    {
        
	mread >> rows1;
	mread >> cols1;
	mread >> srows;
	mread >> scols;
        char g=scols;
        char k=srows;

        if(cols1 < 1)
        {
            throw(MazeCreationException("Columns less than 1"));
        }
       
        if(rows1 < 1)
        {
            throw(MazeCreationException("Rows less than 1"));
        }
     

        if((g > (cols1-1) || g < 0) || (k > (rows1-1) || k < 0))
        {
            throw(MazeCreationException("Invalid starting position"));
        }
        

        char** a=new char*[rows1];
        
        for(int i=0; i<rows1; i++)
        {
            a[i]=new char[cols1];
        }
        
        for(int i=0; i< rows1; i++)
        {
            for(int j=0; j< cols1; j++)
            {
                mread >> a[i][j];
            }
        }
        mazetrans=a;

    }
    else
    {
        throw(MazeCreationException("File is not accessible"));
    }
}

MazeReader::~MazeReader()
{

    for(int i=0; i<rows1; i++)
    {
        delete mazetrans[i];
    }
    delete[] mazetrans;

}

const char* const* MazeReader::getMaze() const
{
    return mazetrans;
}

int MazeReader::getCols() const
{
    return cols1;
}

int MazeReader::getRows() const
{
    return rows1;
}

int MazeReader::getStartCol() const
{
    return scols;
}

int MazeReader::getStartRow() const
{
    return srows;
}



