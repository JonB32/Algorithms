// This is the main DLL file.

#include "stdafx.h"

#include "Sorting.h"
#include <string>
#include <iostream>

namespace Sorting{
	//-------------------Quick Sort----------------------------//
	DllExport void QuickSort(vector<int> &dataStruct)
	{
		if (dataStruct.begin() == dataStruct.end())
			return;

		QuickSort(dataStruct, 0, dataStruct.size() - 1);
	}

	//Quicksort finds a pivot and partitions data structures around
	//the pivot then sorting in the partitions in a divide and conquer approach.
	void QuickSort(vector<int> &dataStruct, int low, int high)
	{
		if (low < high)
		{
			//get the sorted pivot index and partition from index
			int pi = QuickSortPartition(dataStruct, low, high);

			QuickSort(dataStruct, low, pi - 1);
			QuickSort(dataStruct, pi + 1, high);
		}
	}

	int QuickSortPartition(vector<int> &dataStruct, int low, int high)
	{
		//indices used to traverse the elements
		int i = low;
		int j = low;
		//we will use last element as our pivot
		int pivot = dataStruct[high];

		while (j < high)
		{
			//swap elements if i element is less than pivot and greater than j element
			if (dataStruct[j] <= pivot && dataStruct[j] <= dataStruct[i])
			{
				//swap and increment i to next element
				int swap = dataStruct[i];
				dataStruct[i] = dataStruct[j];
				dataStruct[j] = swap;
				i++;
			}

			j++;
		}

		//finally swap i element and pivot to place pivot element in sorted position, and return pivot index
		int swap = dataStruct[i];
		dataStruct[i] = dataStruct[high];
		dataStruct[high] = swap;

		return i;
	}

	//----------------Insertion Sort--------------------------//
	DllExport void InsertionSort(vector<int> &dataStruct)
	{
		// 3 5 2 1 4
		for (vector<int>::size_type i = 1; i < dataStruct.size(); i++)
		{
			int value = dataStruct[i]; // 2
			int j = i - 1; // 1

			while (j >= 0 && value < dataStruct[j]) // 
			{
				dataStruct[j + 1] = dataStruct[j];
				j = j - 1;
			}

			dataStruct[j + 1] = value;
		}
	}

	//---------------Radix Sort------------------------------//
	DllExport void RadixSort(vector<int> &dataStruct)
	{
		int max = dataStruct[0];
		for (vector<int>::iterator it = dataStruct.begin(); it != dataStruct.end(); ++it)
		{
			if (*it > max)
			{
				max = *it;
			}
		}

		for (int i = 0; 0 < max / _Pow_int(10, i); i++)
		{
			CountSort(dataStruct, i);
		}
	}

#define RANGE 10
	//10^x to determine base
	void CountSort(vector<int> &dataStruct, int exp)
	{
		int size = (int)dataStruct.size();
		vector<int> output(size);

		//build count array with a range
		int count[RANGE];
		memset(count, 0, sizeof(count));

		//place element values into count array and increment count for same numbers
		for (int i = 0; i < size; i++)
		{
			int val = (dataStruct[i] / _Pow_int(10, exp)) % 10;
			count[val]++;
		}

		//position count array indexes to match element's indexes in dataStruct
		for (int i = 1; i < RANGE; i++)
		{
			count[i] += count[i - 1];
		}

		//copy values into output
		for (int i = size - 1; i >= 0; i--)
		{
			output[count[(dataStruct[i] / _Pow_int(10, exp)) % 10] - 1] = dataStruct[i];
			count[(dataStruct[i] / _Pow_int(10, exp)) % 10]--;
		}

		//copy sorted array into original

		dataStruct.clear();
		dataStruct.assign(output.begin(), output.end());

	}

	//--------------Selection Sort--------------------------//
	DllExport void SelectionSort(vector<int> &dataStruct)
	{
		if (dataStruct.begin() == dataStruct.end())
			return;

		for (vector<int>::size_type i = 0; i < dataStruct.size(); i++)
		{
			int orgMinIndex = i, newMinIndex = i;

			for (vector<int>::size_type j = i; j < dataStruct.size(); j++)
			{
				if (dataStruct[newMinIndex] > dataStruct[j])
				{
					newMinIndex = j;
				}
			}

			int swap = dataStruct[newMinIndex];
			dataStruct[newMinIndex] = dataStruct[orgMinIndex];
			dataStruct[orgMinIndex] = swap;
		}
	}
}
