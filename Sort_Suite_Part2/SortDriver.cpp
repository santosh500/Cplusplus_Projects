/**
File Name: SortDriver.cpp
Author: Paul Charles
Date: 11.03.2015
Purpose: File that contains the SortDriver methods
**/
#include <iostream>
#include "SortDriver.h"
#include "NumberFileGenerator.h"
#include "Sorts.h"
using namespace std;    
    
void SortDriver::run(int argc, char** argv)
{
    int v;
    string a=argv[2];
    string b=argv[3];
    isFileAccessible(b);
    isSortValid(a);
    areParametersValid(a,b);
    ifstream myInputFile(b);
    v=getFileCount(myInputFile);
    
    
    int* oldArray=createArray(myInputFile,v);
    int newArray[v];
    copyArray(oldArray,newArray,v);
    string c=argv[4];
    ofstream myOutputFile(c);
    if(argc>3)
    {
    if(a=="-bubble")
    {
        
        double q=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, oldArray, v);
        myOutputFile << "bubble" << " " << v << " " << q;
    }
    else if(a=="-selection")
    {
        double q=Sorts<int>::sortTimer(Sorts<int>::selectionSort, oldArray, v);
        myOutputFile << "selection" << " " << v << " " << q;             
    }
    else if(a=="-insertion")
    {
        double q=Sorts<int>::sortTimer(Sorts<int>::insertionSort, oldArray, v);
        myOutputFile << "insertion" << " " << v << " " << q;          
    }
    else if(a=="-quick")
    {
        double q=Sorts<int>::sortTimer(Sorts<int>::quickSort, oldArray, v);
        myOutputFile << "quick" << " " << v << " " << q;            
    }
    else if(a=="-quick3")
    {
        double q=Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, oldArray, v);
        myOutputFile << "quick3" << " " << v << " " << q;       
    }
    else if(a=="-merge")
    {
        double q=Sorts<int>::sortTimer(Sorts<int>::mergeSort, oldArray, v);
        myOutputFile << "merge" << " " << v << " " << q;              
    }
    else if(a=="-all")
    {   
	double q=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, oldArray, v);
        myOutputFile << "bubblesort" << " " << v << " " << q;
	
	double r=Sorts<int>::sortTimer(Sorts<int>::mergeSort, oldArray, v);
        myOutputFile << "merge" << " " << v << " " << r;   
	
	double t=Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, oldArray, v);
        myOutputFile << "quick3" << " " << v << " " << t; 
	
	double w=Sorts<int>::sortTimer(Sorts<int>::quickSort, oldArray, v);
        myOutputFile << "quick" << " " << v << " " << w;  
	
	double j=Sorts<int>::sortTimer(Sorts<int>::insertionSort, oldArray, v);
        myOutputFile << "insertion" << " " << v << " " << j;  
	
	double c=Sorts<int>::sortTimer(Sorts<int>::selectionSort, oldArray, v);
        myOutputFile << "selection" << " " << v << " " << c;  

    }
    else
    {
        printHelpMenu();
    }
    }
    else
    {
        printHelpMenu();
    }
    
    delete[] oldArray;

  
}
void SortDriver::printHelpMenu()
{ 
    std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
                        << "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}
bool SortDriver::isFileAccessible(string fileName)
{
    ifstream file(fileName);
    bool boolvalue;
    if(file.good())
    {
        boolvalue=true;
    }
    else
    {
        boolvalue=false;
    }
    return boolvalue;
}
bool SortDriver::isSortValid(string sortParameter)
{
    bool boolValue;
    if(sortParameter=="-bubble")
    {
        boolValue=true;
    }
    else if(sortParameter=="-selection")
    {
        boolValue=true;        
    }
    else if(sortParameter=="-insertion")
    {
        boolValue=true; 
    }
    else if(sortParameter=="-quick")
    {
        boolValue=true;
    }
    else if(sortParameter=="-quick3")
    {
        boolValue=true; 
    }
    else if(sortParameter=="-merge")
    {
        boolValue=true;
    }
    else if(sortParameter=="-all")
    {
        boolValue=true;
    }

    return boolValue;
}    
bool SortDriver::areParametersValid(string sortName, string inputFileName)
{
    bool t=isSortValid(sortName);
    bool b=isFileAccessible(inputFileName);
    if(t==true && b==true)
    {
        return true;
    }
    else
    {   
        printHelpMenu();
        return false;
    }
}    
int SortDriver::getFileCount(ifstream& inputFile)
{
    
    int* someArray=new int[1];
    inputFile >>  someArray[0];
    return someArray[0];
    delete[] someArray;
}    
int* SortDriver::createArray(ifstream& inputFile, int size)
{
    int* someArray=new int[size];
    for(int i=0; i<=size; i++)
    {
        inputFile >> someArray[i];
    }
    return someArray;
}    
void SortDriver::copyArray(int original[], int copy[], int size)
{
    for(int i=0; i<size; i++)
    {
        copy[i]=original[i];
    }
}
