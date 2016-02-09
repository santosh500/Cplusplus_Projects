/**
File Name: main.cpp
Author: Paul Charles
Date: 10.28.2015
Purpose: Main file
**/
#include <iostream>
using namespace std;
#include "Sorts.h"
#include "Test.h"
void printMenu();
int main()
{

    char b = 'n';
    while (b == 'n')
    {
    printMenu();
    int a;

    cin >> a;
    while(a!=1 && a!=2 && a!=3 && a!=4 && a!=5)
    {
    std::cout <<    "Please give a valid choice\n"
            << "1) Bubble Sort \n"
            << "2) Insertion Sort \n"
            << "3) Selection Sort \n"
            << "4) Bogo Sort (use only with very small arrays!) \n"
            << "5) Run Tests \n";
            cin >> a;
    }

    if (a == 1)
    {
        int size1;
        int min;
        int max;
        char b = 'y';
        cout << "Input a size for the random array: " << endl;
        cin >> size1;
        cout << "Input a lower bound on the range of random numbers: " << endl;
        cin >> min;
        cout << "Input an upper bound on the range of random numbers: " << endl;
        cin >> max;
        int* arr;
        arr = Sorts<int>::createTestArray(size1, min, max);
        cout << "Do you want to print the unsorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the unsorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {

        }
        cout << "Sorting with bubble sort..." << endl;
        Sorts<int>::bubbleSort(arr, size1);
        cout << "Do you want to print the sorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the sorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        cout << size1 << " numbers were sorted in " << Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size1) << " seconds." << endl;
        delete arr;

    }
    else if (a == 2)
    {
        int size1;
        int min;
        int max;
        char b = 'y';
        cout << "Input a size for the random array: " << endl;
        cin >> size1;
        cout << "Input a lower bound on the range of random numbers: " << endl;
        cin >> min;
        cout << "Input an upper bound on the range of random numbers: " << endl;
        cin >> max;
        int* arr;
        arr = Sorts<int>::createTestArray(size1, min, max);
        cout << "Do you want to print the unsorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the unsorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {

        }
        cout << "Sorting with insertion sort..." << endl;
        Sorts<int>::insertionSort(arr, size1);
        cout << "Do you want to print the sorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the sorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        cout << size1 << " numbers were sorted in " << Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size1) << " seconds." << endl;
        delete arr;
    }
    else if (a == 3)
    {
        int size1;
        int min;
        int max;
        char b = 'y';
        cout << "Input a size for the random array: " << endl;
        cin >> size1;
        cout << "Input a lower bound on the range of random numbers: " << endl;
        cin >> min;
        cout << "Input an upper bound on the range of random numbers: " << endl;
        cin >> max;
        int* arr;
        arr = Sorts<int>::createTestArray(size1, min, max);
        cout << "Do you want to print the unsorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the unsorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {

        }
        cout << "Sorting with selection sort..." << endl;
        Sorts<int>::selectionSort(arr, size1);
        cout << "Do you want to print the sorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the sorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        cout << size1 << " numbers were sorted in " << Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size1) << " seconds." << endl;
        delete arr;
    }
    else if (a == 4)
    {
        int size1;
        int min;
        int max;
        char b = 'y';
        cout << "Input a size for the random array: " << endl;
        cin >> size1;
        cout << "Input a lower bound on the range of random numbers: " << endl;
        cin >> min;
        cout << "Input an upper bound on the range of random numbers: " << endl;
        cin >> max;
        int* arr;
        arr = Sorts<int>::createTestArray(size1, min, max);
        cout << "Do you want to print the unsorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the unsorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {

        }
        cout << "Sorting with bogo sort..." << endl;
        Sorts<int>::bogoSort(arr, size1);
        cout << "Do you want to print the sorted array? (y/n)" << endl;
        cin >> b;

        if (b == 'y')
        {
            cout << "Here is the sorted array: " << endl;
            for (int i = 0; i<size1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        cout << size1 << " numbers were sorted in " << Sorts<int>::sortTimer(Sorts<int>::bogoSort, arr, size1) << " seconds." << endl;
        delete arr;
    }
    else if (a == 5)
    {
        Test myTester(std::cout);
        myTester.runTests();
    }

    cout << "Do you want to quit? (y/n): " << endl;
    cin >> b;
    while(b !='y' && b!='n')
    {
        cout << "Please type 'y' for yes or 'n' for no" << endl;
        cin >> b;
    }
    }


}

void printMenu()
{
        std::cout << " Select a sort: \n"
            << "1) Bubble Sort \n"
            << "2) Insertion Sort \n"
            << "3) Selection Sort \n"
            << "4) Bogo Sort (use only with very small arrays!) \n"
            << "5) Run Tests \n"
            << "Enter choice: \n";
}
