/**
File Name: MazeWalker.h
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeWalker prototypes
**/
#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include "MazeCreationException.h"
#include "Position.h"
#include "MazeReader.h"
using namespace std;

enum class Search
{
    DFS,
    BFS
};

class MazeWalker
{
    
public: 
    MazeWalker(const char* const* mazePtr=nullptr, int startRow=0, int startCol=0, int rows=0, int cols=0, Search searchChoice=Search::DFS);
    /**
      *	@pre The mazePtr pointer is to a valid maze.
      *	@post A maze walker if created ready to traverse the maze from the start position is the specified order
      */
    ~MazeWalker();
    /**
      *
      *	@pre The visited array still exists and has the same dimensions (rows X cols)
      *	@post The visited array is deallocated
      */
    bool walkMaze();
    /**
      *	@pre The maze is a valid maze
      *	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted.
      *	@return true if an exit was reached, false otherwise
      */
    const int* const* getVisited() const;
    /**
      *	@return A const pointer to the visited array. (A pointer that cannot change the array)
      */
    int getVisitedRows() const;
    /**
      *	@return number of rows in maze
      */
    int getVisitedCols() const;
    /**
      *	@return number of cols in maze
      */
    const char* const* getMaze() const;
    /**
      *	@return A const pointer to the maze. (A pointer that cannot change the array)
      */
    
    void storeValidMoves();
    /**
      *	@pre The current position is valid.
      *	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position
      */
    void move(Position& p);
    /**
      *	@pre The position is valid.
      *	@post The current position is set to p and the position is updated as marked.
      */
    bool isGoalReached() const;
    /**
      *	@returns If the current position is the exit, true is returned. False is returned otherwise.
      */
    Search m_searchType;
    
    int** m_visited;
    protected:
    int m_rows;
    int m_cols;
    Position m_startPos;
    const char* const* m_maze;
    Position m_curPos;
    stack<Position> m_moveStack;
    queue<Position> m_moveQueue;
    int m_curStep;     
};
#endif
