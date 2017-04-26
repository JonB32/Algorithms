// Sorting.h

#pragma once

#include <vector>

using namespace std;

namespace Sorting {

	/* An example of merge sort. First divide the list into the smallest unit (1 element),
		then compare each element with the adjacent list to sort and merge the two adjacent lists.
		Finally all the elements are sorted and merged.
	*/
	template <typename T, typename A> int MergeSort(vector<T, A>& dataStruct, int n)
	{
		if (dataStruct.begin() == dataStruct.end())
		{
			return -1;
		}
		
		MergeSort(dataStruct, 0, n - 1);

		return 0;
	}

	template <typename T, typename A> int MergeSort(vector<T, A>& dataStruct, int left, int right)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			MergeSort(dataStruct, left, mid);
			MergeSort(dataStruct, mid + 1, right);
			Merge(dataStruct, left, mid, right);
		}

		return 0;
	}

	template <typename T, typename A> int Merge(vector<T, A>& dataStruct, int left, int mid, int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int i, j, k;

		vector<T> leftList(n1);
		vector<T> rightList(n2);

		for (i = 0; i < n1; i++)
		{
			leftList[i] = dataStruct[left + i];
		}

		for (i = 0; i < n2; i++)
		{
			rightList[i] = dataStruct[mid + 1 + i];
		}

		i = 0;
		j = 0;
		k = left;

		while (i < n1 && j < n2)
		{
			if (leftList[i] <= rightList[j])
			{
				dataStruct[k] = leftList[i];
				i++;
			}
			else
			{
				dataStruct[k] = rightList[j];
				j++;
			}
			k++;
		}

		//remaining leftlist items if any
		while (i < n1)
		{
			dataStruct[k] = leftList[i];
			i++;
			k++;
		}

		//remaining rightlist items if any
		while (j < n2)
		{
			dataStruct[k] = rightList[j];
			j++;
			k++;
		}

		return 0;
	}
}
