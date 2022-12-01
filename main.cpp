#include <iostream>
#include <vector>
#include <random>
#include "sorting.h"
#include <chrono>
using namespace std;
void quickSort(vector<__int64> &array, __int64 low, __int64 high);
// For partition of arrat according to the pivot element


int main()
{
    __int64 size = 1000000;
    vector<__int64> timerLog;
    for (__int64 i = 1; i < size; i += 1000)
    {
        vector<__int64> array;
        randomArrary(array, i);
        cout << i << endl;
        __int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        quickSort(array, 0, array.size() - 1);
        timerLog.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - now);
        cout << i << "  " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - now << endl;
    }
    for (__int64 i = 0; i < timerLog.size(); i++)
    {
        static int j = 1;
        cout << j << "," << timerLog[i] << endl;
        j += 1000;
    }
    vector <__int64> array;
    randomArrary(array,100);
    quickSort(array,0,100-1);
    for (int i = 0; i < array.size(); i++)
    {
        cout<<"The element is: "<<array[i]<<endl;
    }
}