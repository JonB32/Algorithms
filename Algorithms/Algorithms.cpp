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

	cout << "Data after Merge Sort: " << VectorToString(dataToSort).c_str();
	
	cin.get();

	return 0;
}

