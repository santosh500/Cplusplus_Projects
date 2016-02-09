/**
File Name: MazeReader.h
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeReader prototypes
**/
#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <iostream>
#include <string>
#include <functional>
#include <cassert>
#include <fstream>
#include "MazeCreationException.h"
#include "MazeWalker.h"
#include "MazeReader.h"
#include "Position.h"
using namespace std;

class MazeReader
{
public:
    MazeReader(string file=" ") throw (MazeCreationException);
    /**
     * @pre valid file and MazeReader object
     * @post constructor
     * @return none
     */
    ~MazeReader();
    /**
     * @pre valid file and MazeReader object
     * @post destructs the heap allocated fields
     * @return none
     */
    const char* const* getMaze() const;
    /**
    *	@pre the file was formatting and read in correctly
    *	@return Returns pointer to the maze
    */
    int getCols() const;
    /**
     *	@pre the file was formatted and read in correctly
     *	@returns the number of columns listed in the file
     */
    int getRows() const;
    /**
      *	@pre the file was formatted and read in correctly
      *	@returns the number of rows listed in the file
      */
    int getStartCol() const;
    /**
      *	@pre the file was formatted and read in correctly
      *	@returns the starting column
      */
    int getStartRow() const;
    /**
      *	@pre the file was formatted and read in correctly
      *	@returns the starting row
      */
private:
    int rows1;
    int cols1;
    int srows;
    int scols;
    const char* const* mazetrans;
protected:
    void readMaze()throw (MazeCreationException);
    /**
      *	@pre the file is properly formatted
      *	@post the characters representing the maze are stores
      */
    
};
#endif
