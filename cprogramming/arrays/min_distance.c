// Given an unsorted array arr[] and two numbers x and y,
// find the minimum distance between x and y in arr[].

#include <stdio.h>
#include <limits.h>

#define MIN(a,b) a > b? b:a
int min_distance(int *arr, int size, int elem1, int elem2)
{
	int distance = INT_MAX;
	int prev_index = -1;
	int prev_elem = 0;
	int i =0;
	while (i <= size -1) {
		if (arr[i] == elem1 || arr[i] == elem2) {
			if (prev_index == -1) {
				prev_elem = arr[i];
				prev_index = i;
			} else {
				if (prev_elem != arr[i]) {
					distance = MIN(distance, i - prev_index);
					prev_elem = arr[i];
				}
				prev_index = i;
			}
		}
		i++;
	}
	return distance;
}
int main()
{
	int arr[] = {2, 5, 3, 5, 4, 4, 2, 3};
	printf("Min Distance : %d\n", min_distance(arr, 8, 3, 2));
}
