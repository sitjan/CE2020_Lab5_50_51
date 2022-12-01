#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
using namespace std;


//Function declaration for quick sort
void quickSort(vector<__int64> &array,int low , int high );
// For partition of arrat according to the pivot element
int partition(vector<__int64> &array ,int low, int high);
void swapElement (vector<__int64> &array , int firstPosi, int secondPosi);
 void  randomArrary (vector<__int64> &array,int size);
 void insertionsort(vector<__int64> &array);

#endif