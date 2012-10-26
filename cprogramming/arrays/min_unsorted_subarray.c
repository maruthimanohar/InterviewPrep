// Given an unsorted array arr[0..n-1] of size n, find the
// minimum length subarray arr[s..e] such that sorting this
// subarray makes the whole array sorted.

#include <stdio.h>

void print_array(int *arr, int start_index, int end_index)
{
	int i=0;
	for (i = start_index; i < end_index; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
}

void min_unsorted_subarray(int *arr, int size)
{
	int left_index = 0;
	int right_index = size -1;
	// find the pair from the start where there is an inversion.
	int start = 0;
	for (start = 0; start < size -1; start++) {
		if (arr[start] > arr[start+1])
			break;
	}
	if (start == size-1) // the array is sorted
		return;
	int end = 0;
	for (end = size -1; end > 0; end--) {
		if (arr[end] < arr[end-1])
			break;
	}

	// find the min and max in this start and end region.
	int min = arr[start];
	int max = arr[start];
	int i = 0;
	for (i = start+1; i <= end; i++) {
		if (arr[i] < min)
			min = arr[i];
		else if (arr[i] > max)
			max = arr[i];
	}
	// find the region from 0.. start, if there is an element greater than min,
	// if so we need to include from that element.
	for (i = 0; i < start; i++) {
		if (arr[i] > min) {
			start = i;
			break;
		}
	}

	// similarly find in the region from end .. size-1, if there is an element smaller than max,
	// if so we need to inclde up to that element.
	for (i = size -1; i > end; i--) {
		if (arr[i] < max) {
			end = i;
			break;
		}
	}
	printf("We need to sort range starting from %d to %d\n", start, end);
}

int main()
{
	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	print_array(arr, 0, 10);
	min_unsorted_subarray(arr, 11);
}
