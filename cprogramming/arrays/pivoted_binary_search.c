#include <stdio.h>

int binary_search(int *arr, int elem, int left_index, int right_index)
{
	if (left_index > right_index)
		return -1;
	int middle_index = (left_index + right_index) / 2;
	if (elem == arr[middle_index])
		return middle_index;
	if (elem < arr[middle_index] && elem >= arr[left_index])
		return binary_search(arr, elem, left_index, middle_index -1);
	if (elem > arr[middle_index] && elem <= arr[right_index])
		return binary_search(arr, elem, middle_index +1, right_index);
	printf("In binary search : element not found. %d %d\n", arr[left_index], arr[right_index]);
	return -1;
}
int pivoted_binary_search(int *arr, int elem, int left_index, int right_index)
{
	if (left_index > right_index)
		return -1;
	int middle_index = (left_index + right_index)/2;
	if (arr[middle_index] == elem)
		return middle_index;
	if (elem < arr[middle_index] && elem >= arr[left_index]) {
		return binary_search(arr, elem, left_index, middle_index-1);
	}
	if (elem > arr[middle_index] && elem <= arr[right_index]) {
		return binary_search(arr, elem, middle_index+1, right_index);
	}

	if (arr[middle_index] > arr[left_index]) {
		return pivoted_binary_search(arr, elem, middle_index+1, right_index);
	}
	if (arr[middle_index] < arr[right_index]) {
		return pivoted_binary_search(arr, elem, left_index, middle_index-1);
	}
	printf("In pivoted binary search: element not found\n");
	return -1;
}

int main()
{
	int arr[] = {3, 4, 5, 6, 7, 1, 2};
	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("index of %d is : %d\n", 4, pivoted_binary_search(arr, 4, 0, 6));
}
