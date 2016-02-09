/**
File Name: Sorts.hpp
Author: Paul Charles
Date: 10.27.15
Purpose: Contains the function defintions for Sorts class
**/
using namespace std;

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{

    int min = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {

            if (arr[j] < arr[j - 1])
            {
                min = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = min;

            }
            else
            {
                min = arr[i];
            }

        }
        arr[i] = min;
    }

    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{/**/
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j >= 0; j--)
        {

            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }

        }
    }

    assert(Sorts<T>::isSorted(arr, size));
}


template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    int k;
    bool BooleanValue = true;;
    for (int i = 1; i < size; i++)
    {
        if(arr[i]<arr[i - 1])
        {
            BooleanValue = false;
        }
    }
    return(BooleanValue);
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
    default_random_engine generator(time(nullptr));

    while (!isSorted(arr, size))
    {
        shuffle(arr, size, generator);
    }

    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, default_random_engine& generator)
{
    int randomNumber;
    uniform_int_distribution<int> distribution(0, size - 1);
    int temp = 0;
    for (int j = 0; j < size - 1; j++)
    {
        randomNumber = distribution(generator);
        temp = arr[j];
        arr[j] = arr[randomNumber];
        arr[randomNumber] = temp;
    }
}

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
    int *ar1 = new int[size];
    default_random_engine generator(time(nullptr));
    uniform_int_distribution<int> distribution(min, max);
    int randomNumber;
    for (int i = 0; i < size; i++)
    {
        randomNumber = distribution(generator);
        ar1[i] = randomNumber;
    }
    return ar1;
}

template <typename T>
double Sorts<T>::sortTimer(function<void(T[], int)> sort, T arr[], int size)
{

    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;

    start = std::chrono::system_clock::now();


    end = std::chrono::system_clock::now();
    elapsed = (end - start);
    double a = elapsed.count();
    return a;

}
