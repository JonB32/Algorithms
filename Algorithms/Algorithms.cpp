// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> dataToSort {3,2,4,1,6,5};
	Sorting::MergeSort(dataToSort, dataToSort.size());
	cout << "Data after Merge Sort: " << VectorToString(dataToSort).c_str() << endl;

	vector<int> dataToSort2 { 3, 2, 8, 5, 1, 7, 6, 4 };
	Sorting::QuickSort(dataToSort2);
	cout << "Data after Quick Sort: " << VectorToString(dataToSort2).c_str() << endl;
	
	cin.get();

	return 0;
}

