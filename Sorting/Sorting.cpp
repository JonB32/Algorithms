// This is the main DLL file.

#include "stdafx.h"

#include "Sorting.h"

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
}
