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

	vector<int> dataToSort3{ 3, 2, 8, 5, 1, 7, 6, 4 };
	Sorting::InsertionSort(dataToSort3);
	cout << "Data after Insertion Sort: " << VectorToString(dataToSort3).c_str() << endl;

	vector<int> dataToSort4{ 10, 2, 32, 511, 342, 4, 6, 2, 34, 22, 510, 231 };
	Sorting::RadixSort(dataToSort4);
	cout << "Data after Radix Sort: " << VectorToString(dataToSort4).c_str() << endl;

	vector<int> dataToSort5{ 3, 6, 2, 1, 4, 10, 8 };
	Sorting::SelectionSort(dataToSort5);
	cout << "Data after Selection Sort: " << VectorToString(dataToSort5).c_str() << endl;
	
	cin.get();

	return 0;
}

