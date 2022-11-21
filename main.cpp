#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include <chrono>
using namespace std;
void quickSort(int *array, int low, int high);
// For partition of arrat according to the pivot element
int partition(int *array, int low, int high);
void swapElement(int *array, int firstPosi, int secondPosi);
void randomArrary(int *array, int size);

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
    int i = low+1 ;
    int j = high;
    while (i < j)
    {
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
int main()
{
    int timer = 100000;
    int timerLog[timer];
    for (int i = 1; i < timer; i+=100)
    {
        int * array = new int[i];
        randomArrary(array,i);
        unsigned __int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        quickSort(array,0,i-1);
        timerLog[i-1] = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()-now;
        cout<<timerLog[i-1]<<endl;
         delete array;
    }
    for (int i = 0; i < timer; i+=1000)
    {
        cout<<i+1<<","<<timerLog[i]<<endl;
    }
    
}