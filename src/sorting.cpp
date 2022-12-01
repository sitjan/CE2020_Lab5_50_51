#include <iostream>
#include <vector>
#include "sorting.h"
#include <random>
#include <algorithm>
#include <random>
using namespace std;

// choose a pivot element and place it in its exact position of a sorted array
// For example : Array = {1,15,3,4,7,8,9}
// if 3 were to be the pivot element its position in the array would be second place
// Repeat this until you find the position for all the elements in the array
void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

int partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high;
    while (i < j)
    {
        for (int i = 0; i < 1; i++)
        {

            cout << "The element is : " << array[i] << endl;
        }
        while (array[i] < pivot)
        {
            i = i + 1;
        }
        while (array[j] > pivot)
        {
            j = j - 1;
        }
        if (i < j)
        {
            swapElement(array, i, j);
        }
    }
    swapElement(array, j, low);
    return j;
}
// swapElement the element in the given positions
void swapElement(int *array, int firstPosi, int secondPosi)
{
    int temp = array[firstPosi];
    array[firstPosi] = array[secondPosi];
    array[secondPosi] = temp;
}

void randomArrary(int *array, int size)
{

    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }

    random_shuffle(array, array + size - 1);
}

void insertionsort(int* array){
    int length = sizeof(array);
    for(j=1; j<length-1; j++){
        int key = array [j];
        int i= j-1;
        while (i>=0 && array[i]>key){
            array[i+1]= array[i];
            i=i-1;
        }
        array[i+1] = key;
    }
}