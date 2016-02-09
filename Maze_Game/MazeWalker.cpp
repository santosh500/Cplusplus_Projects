/**
File Name: MazeWalker.cpp
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the MazeWalker functions
**/
#include <iostream>
#include "MazeWalker.h"
using namespace std;
/**/
 MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice) :m_startPos(startRow, startCol)
 {
    m_rows=rows;
    m_cols=cols;
    m_maze=mazePtr;
    m_searchType=searchChoice;

    m_visited=new int*[m_rows];
    for(int i=0; i< m_rows; i++)
    {
        m_visited[i]=new int[m_cols];
    }

    for(int i=0; i< m_rows; i++)
    {
        for(int j=0; j<m_cols; j++)
        {
            m_visited[i][j]=0;
        }

    }

    m_curPos=m_startPos;
    m_curStep=1;
    m_visited[startRow][startCol]=m_curStep;

 }

 MazeWalker::~MazeWalker()
 {

     for(int i=0; i<m_rows; i++)
     {
         delete m_visited[i];
     }
     delete[] m_visited;


 }

 bool MazeWalker::walkMaze()
 {
     if(m_searchType==Search::BFS)
     {
         storeValidMoves();

         if(isGoalReached() || m_moveQueue.empty())
         {
             return true;
         }

         move(m_moveQueue.front());


         walkMaze();
     }
     else
     {
         storeValidMoves();

         if(isGoalReached() || m_moveStack.empty())
         {
             return true;
         }

         move(m_moveStack.top());


         walkMaze();
     }

 }

 const int* const* MazeWalker::getVisited() const
 {
     return m_visited;
 }

int MazeWalker::getVisitedRows() const
{
    return m_rows;
}

int MazeWalker::getVisitedCols() const
{
    return m_cols;
}

const char* const* MazeWalker::getMaze() const
{
    return m_maze;
}

void MazeWalker::storeValidMoves()
{

    if(m_searchType==Search::DFS)
    {
        if(m_curPos.getRow()-1 >= 0)
        {
            if((m_visited[m_curPos.getRow()-1][m_curPos.getCol()]==0) && ((m_maze[m_curPos.getRow()-1][m_curPos.getCol()] == ('E')) || (m_maze[m_curPos.getRow()-1][m_curPos.getCol()] == ('P'))))
            {
                Position a(m_curPos.getRow()-1,m_curPos.getCol());
                m_moveStack.push(a);
            }
            else
            {

            }
        }

        if(m_curPos.getCol()+1 < m_cols)
        {
            if((m_visited[m_curPos.getRow()][m_curPos.getCol()+1]==0) && ((m_maze[m_curPos.getRow()][m_curPos.getCol()+1] == ('E')) || (m_maze[m_curPos.getRow()][m_curPos.getCol()+1] == ('P'))))
            {
                Position a(m_curPos.getRow(),m_curPos.getCol()+1);
                m_moveStack.push(a);
            }
            else
            {

            }
        }
        if(m_curPos.getRow() +1 < m_rows)
        {
            if((m_visited[m_curPos.getRow()+1][m_curPos.getCol()]==0) && ((m_maze[m_curPos.getRow()+1][m_curPos.getCol()] == ('E')) || (m_maze[m_curPos.getRow()+1][m_curPos.getCol()] == ('P'))))
            {
                Position a(m_curPos.getRow()+1,m_curPos.getCol());
                m_moveStack.push(a);
            }
            else
            {

            }
        }
        if(m_curPos.getCol()-1 >= 0)
        {
            if((m_visited[m_curPos.getRow()][m_curPos.getCol()-1]==0) && ((m_maze[m_curPos.getRow()][m_curPos.getCol()-1] == ('E')) || (m_maze[m_curPos.getRow()][m_curPos.getCol()-1] == ('P'))))
            {
                Position a(m_curPos.getRow(),m_curPos.getCol()-1);
                m_moveStack.push(a);
            }
            else
            {

            }
        }
    }
    else
    {
        if(m_curPos.getRow()-1 >= 0)
        {
            if((m_visited[m_curPos.getRow()-1][m_curPos.getCol()]==0) && ((m_maze[m_curPos.getRow()-1][m_curPos.getCol()] == ('E')) || (m_maze[m_curPos.getRow()-1][m_curPos.getCol()] == ('P'))))
            {
                Position a(m_curPos.getRow()-1,m_curPos.getCol());
                m_moveQueue.push(a);
            }
            else
            {

            }
        }

        if(m_curPos.getCol()+1 < m_cols)
        {
            if((m_visited[m_curPos.getRow()][m_curPos.getCol()+1]==0) && ((m_maze[m_curPos.getRow()][m_curPos.getCol()+1] == ('E')) || (m_maze[m_curPos.getRow()][m_curPos.getCol()+1] == ('P'))))
            {
                Position a(m_curPos.getRow(),m_curPos.getCol()+1);
                m_moveQueue.push(a);
            }
            else
            {

            }
        }
        if(m_curPos.getRow() +1 < m_rows)
        {
            if((m_visited[m_curPos.getRow()+1][m_curPos.getCol()]==0) && ((m_maze[m_curPos.getRow()+1][m_curPos.getCol()] == ('E')) || (m_maze[m_curPos.getRow()+1][m_curPos.getCol()] == ('P'))))
            {
                Position a(m_curPos.getRow()+1,m_curPos.getCol());
                m_moveQueue.push(a);
            }
            else
            {

            }
        }
        if(m_curPos.getCol()-1 >= 0)
        {
            if((m_visited[m_curPos.getRow()][m_curPos.getCol()-1]==0) && ((m_maze[m_curPos.getRow()][m_curPos.getCol()-1] == ('E')) || (m_maze[m_curPos.getRow()][m_curPos.getCol()-1] == ('P'))))
            {
                Position a(m_curPos.getRow(),m_curPos.getCol()-1);
                m_moveQueue.push(a);
            }
            else
            {

            }
        }
    }

}

void MazeWalker::move(Position& p)
{
    if(m_searchType==Search::DFS)
    {
        m_curPos=p;
        m_curStep++;
        m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;
        m_moveStack.pop();

    }
    else if(m_searchType==Search::BFS)
    {
        m_curPos=p;
        m_curStep++;
        m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;
        m_moveQueue.pop();
    }
}

bool MazeWalker::isGoalReached() const
{
    if((m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E'))
    {
        return true;
    }
    else
    {
        return false;
    }

}
