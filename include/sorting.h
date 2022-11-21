#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
using namespace std;


//Function declaration for quick sort
void quickSort(int* array,int low , int high );
// For partition of arrat according to the pivot element
int partition(int * array ,int low, int high);
void swapElement (int * array , int firstPosi, int secondPosi);
 void  randomArrary (int * array,int size);

#endif