#include <stdio.h>

#define MAX(a,b) a > b? a : b

int contiguous_sum(int *arr, int size)
{
	if (size <= 0) {
		printf("The size should be positive\n");
		return -1;
	}
	int cur_start_index = 0;
	int start_index = 0;
	int end_index = 0;
	int max_contiguous_sum = arr[0];
	int max_ending_here = arr[0];
	int i = 0;
	for (i = 1; i < size; i++) {
		if (arr[i] < max_ending_here + arr[i]) {
			max_ending_here = arr[i] + max_ending_here;
		} else {
			max_ending_here = arr[i];
			cur_start_index = i;
		}
		if (max_ending_here > max_contiguous_sum) {
			max_contiguous_sum = max_ending_here;
			start_index = cur_start_index;
			end_index = i;
		}
	}
	printf("%d:%d\n", start_index, end_index);
	return max_contiguous_sum;
}

int main()
{
	int arr[] = { 2, -3, 4, -1, -2, 1, 5, -3};
	int i = 0;
	for (i = 0; i < 8; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	printf("Max Contiguous Sum: %d\n", contiguous_sum(arr, 8));
}
