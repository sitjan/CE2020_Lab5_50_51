#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "sorting.h"
#include <chrono>
#include <fstream>
using namespace std;

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

    // vector <__int64> array;
    // array ={1234,123,4123,51,2134,5,2345347,45,6855,5678,567857823,4525,6};
    // quickSort(array,0,array.size()-1);
    // for (int i = 0; i < array.size(); i++)
    // {
    //     cout<<"The element is: "<<array[i]<<endl;
    // }
    fstream fout;
    // creates a new file.
    fout.open("random.csv", ios::out | ios::app);
    fout << "Size of Array"
         << " ,"
         << "QuickSort"
         << " ,"
         << "InsertionSort " << endl;
    for (__int64 i = 0; i < timerLog.size(); i++)
    {
        static int j = 1;
        fout << j << "," << timerLog[i] << "," << 0 << endl;
        j += 1000;
    }
}