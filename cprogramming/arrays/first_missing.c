// Given a sorted array of n integers where each integer is in the range
// from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

#include <stdio.h>

int smallest_missing(int *arr, int size)
{
	int left_index = 0;
	int right_index = size -1;
	while (left_index <= right_index) {
		int middle_index = (right_index + left_index)/2;
		if(arr[middle_index] > middle_index)
			right_index = middle_index-1;
		left_index = middle_index+1;
	}
	return right_index + 1;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("Smallest missing number : %d\n", smallest_missing(arr, 11));
}
