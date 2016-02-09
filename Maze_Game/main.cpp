/**
File Name: main.cpp
Author: Paul Charles
Date: 11.18.2015
Purpose: File that contains the main.cpp
**/
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>

#include "MazeReader.h"
#include "MazeWalker.h"
#include "Test.h"
#include "MazeCreationException.h"
#include "Position.h"


using namespace std;

int main(int argc, char** argv)
{
    string mode="";
    MazeReader* b;
    MazeWalker* g;
    if(argc>1)
    {
        mode=argv[1];
        string mode2="";
        if(mode == "-bfs")
        {
            mode2=argv[2];
            try
            {
                b=new MazeReader(mode2);
                const char* const* j=b->getMaze();
                int k=b->getCols();
                int l=b->getRows();
                int m=b->getStartCol();
                int n=b->getStartRow();
                Search o=Search::BFS;
                g=new MazeWalker(j, n, m, l, k, o);
                g->walkMaze();
                const int* const* visit=g->getVisited();
                cout << "Starting position: " << b->getStartRow() << "," << b->getStartCol() << endl;
                cout << "Size: " << b->getRows() << "," << b->getCols() << endl;
                for(int i=0; i< g->getVisitedRows(); i++)
                {
                    for(int j=0; j<g->getVisitedCols(); j++)
                    {
                        cout << visit[i][j] << " ";
                    }
                    cout << endl;
                }
                if(g->isGoalReached())
                {
                    cout << "We escaped!" << endl;
                }
                else
                {
                    cout << "No way out!" << endl;
                }
                delete b;
                delete g;

            }
            catch(exception& e)
            {
               cout << e.what() << endl;
            }




        }
        else if(mode=="-dfs")
        {
            mode2=argv[2];
            try
            {
                b=new MazeReader(mode2);

                const char* const* j=b->getMaze();
                int k=b->getCols();
                int l=b->getRows();
                int m=b->getStartCol();
                int n=b->getStartRow();
                Search o=Search::DFS;
                g=new MazeWalker(j, n, m, l, k, o);
                g->walkMaze();
                const int* const* visit=g->getVisited();
                cout << "Starting position: " << b->getStartRow() << "," << b->getStartCol() << endl;
                cout << "Size: " << b->getRows() << "," << b->getCols() << endl;
                for(int i=0; i< g->getVisitedRows(); i++)
                {
                    for(int j=0; j<g->getVisitedCols(); j++)
                    {
                        cout << visit[i][j] << " ";
                    }
                    cout << endl;
                }
                if(g->isGoalReached())
                {
                    cout << "We escaped!" << endl;
                }
                else
                {
                    cout << "No way out!" << endl;
                }
                delete b;
                delete g;
            }
            catch(exception& e)
            {
               cout << e.what() << endl;
            }

        }
        else if (mode == "-test")
        {
            Test a;
            a.runTests();
        }

    }
    else
    {
        cout << "Please give at least two command arguments." << endl;
    }


}
