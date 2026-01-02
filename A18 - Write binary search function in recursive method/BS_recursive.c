#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr,  data_t first, data_t last, data_t key)
{
	 if (last >= first)
	{
		int mid = first + (last - first)/2;

		// If the element is present at the middle itself
		if (arr[mid] == key) 
		{
			return mid;
		}

		// If element is smaller than mid, then it can only be present
		// in first subarray
		if (arr[mid] > key) 
		{
			return binarySearch_recursive(arr, first, mid-1, key);
		}

		// Else the element can only be present in last subarray
		return binarySearch_recursive(arr, mid+1, last, key);

    }
	return  DATA_NOT_FOUND;
    //return 0;
}
