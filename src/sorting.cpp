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
void quickSort(vector<__int64> &array, __int64 low, __int64 high)
{
    if (low < high)
    {
        __int64 pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

//  __int64 partition(vector< __int64> &array,  __int64 low,  __int64 high)
// {
//      __int64 pivot = array[low];
//      __int64 i = low+1 ;
//      __int64 j = high;
//     while (i < j)
//     {
//         while (array[i] < pivot)
//         {
//             i = i + 1;
//         }
//         while (array[j] > pivot)
//         {
//             j = j - 1;
//         }
//         if (i < j)
//         {
//             swapElement(array, i, j);
//         }
//     }
//     swapElement(array, j, low);
//     return j;
// }
__int64 partition(vector<__int64> &array, __int64 low, __int64 high)
{
    __int64 pivot = array[low];
    __int64 i = low + 1;
    __int64 j = high;
    while (i < j)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
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
void swapElement(vector<__int64> &array, __int64 firstPosi, __int64 secondPosi)
{
    __int64 temp = array[firstPosi];
    array[firstPosi] = array[secondPosi];
    array[secondPosi] = temp;
}

void randomArrary(vector<__int64> &array, __int64 size)
{
    for (__int64 i = 0; i < size; i++)
    {
        array.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(array.begin(), array.end(), g);
}