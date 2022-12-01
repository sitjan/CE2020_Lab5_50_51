#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
using namespace std;


//Function declaration for quick sort
void quickSort(vector<__int64> &array,__int64 low , __int64 high );
// For partition of arrat according to the pivot element
__int64 partition(vector<__int64> &array ,__int64 low, __int64 high);
void swapElement (vector<__int64> &array , __int64 firstPosi, __int64 secondPosi);
void  randomArrary (vector<__int64> &array,__int64 size);
void insertionsort(vector<__int64> &array);

#endif