#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "sorting.h"
#include <chrono>
#include <fstream>
#include <fstream>
using namespace std;
// void quickSort(vector<__int64> &array, __int64 low, __int64 high);
// For partition of arrat according to the pivot element

int main()
{
    __int64 size = 100000;
    vector<__int64> timerLogInsertion;
    vector<__int64> timerLogQuick;
    fstream fout;
    fout.open("random2.csv", ios::out | ios::app);
    fout << "Size of Array"
         << "Insertion Sort"
         << "Quick Sort" << endl;
    for (__int64 i = 1; i < size; i += 1000)
    {
        vector<__int64> arrayForInsertion;
        randomArrary(arrayForInsertion, i);
        vector<__int64> arrayForQuick;
        arrayForQuick = arrayForInsertion;
        cout << i << endl;
        __int64 nowInsertion = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        insertionsort(arrayForInsertion);
        timerLogInsertion.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - nowInsertion);
        cout << i << "  " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - nowInsertion << endl;
        cout << i << endl;
        __int64 nowQuick = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        quickSort(arrayForQuick,0,arrayForQuick.size()-1);
        timerLogQuick.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - nowQuick);
        cout << i << "  " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - nowQuick << endl;
    }
    for (__int64 i = 0; i < timerLogInsertion.size(); i++)
    {
        static int j = 1;
        fout << j << "," << timerLogInsertion[i] << "," << timerLogQuick[i] << endl;
        j += 1000;
    }
    // vector<__int64> array;
    // randomArrary(array, 100);
    // insertionsort(array);
    // for (int i = 0; i < array.size(); i++)
    // {
    //     cout<<"The Element is;"<<array[i]<<endl;
    // }

}