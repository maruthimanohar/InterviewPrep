#include <stdio.h>

int find_majority(int *arr, int size)
{
	if (size == 0) {
		printf("No majority element\n");
		return -1;
	}
	int candidate_index = -1;
	int count = 0;
	int i = 0;
	for (i=0; i < size; i++) {
		if (candidate_index < 0) {
			candidate_index = i;
			count = 1;
		} else if (arr[candidate_index] == arr[i]) {
			count++;
		} else {
			count--;
			if (count == 0)
				candidate_index = -1;
		}
	}
	// check if the number at candidate index occurs more than n/2 times.
	count = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] == arr[candidate_index])
			count++;
	}
	if (count > size/2) {
		printf("Majority Element: %d\n", arr[candidate_index]);
		return 1;
	} else {
		printf("This is not majority element : %d\n", arr[candidate_index]);
		return -1;
	}
	return -1;
}

// print an element that is occuring n/2 times
void print_elem_halftime(int *arr, int size)
{
	if (size%2 != 0) {
		printf("The array should have even number of elements\n");
		return;
	}
	if (find_majority(arr, size - 1) < 0) {
		printf("Element occuring n/2 number of times is :%d\n", arr[size-1]);
		return;
	} else {
		printf("Element occuring n/2 number of times was the maximum in the n-1 size array, that is already printed\n");
		return;
	}
}
int main()
{
	int arr[] = { 3, 1, 1, 1, 2, 2};
	print_elem_halftime(arr, 6);
}
