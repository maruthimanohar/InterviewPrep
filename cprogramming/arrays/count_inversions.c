#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int start, int end)
{
	int i=0;
	for (i = start; i <= end; i++)
		printf("%d,", arr[i]);
	printf("\n");
}

// @middle_index - is the start of the second array.

int merge(int *arr, int left_index, int middle_index, int right_index)
{
	int inv_count = 0;
	int *tmp = (int *)malloc(sizeof(int) * ((right_index - left_index) +1 ));
	int i=left_index, j=middle_index, k=0;
	while (i < middle_index &&  j <= right_index) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
			inv_count = inv_count + (middle_index - i);
		}
	}
	while (i < middle_index)
		tmp[k++] = arr[i++];
	while (j <= right_index)
		tmp[k++] = arr[j++];
	k = 0;
	for (i = left_index; i <= right_index; i++) {
		arr[i] = tmp[k++];
	}
	return inv_count;
}

int _merge_sort(int *arr, int left_index, int right_index)
{
	int inv_count = 0;
	if (left_index >= right_index) {
		return 0;
	}
	int middle_index = (left_index + right_index)/2;
	inv_count += _merge_sort(arr, left_index, middle_index);
	inv_count += _merge_sort(arr, middle_index+1, right_index);
	inv_count += merge(arr, left_index, middle_index+1, right_index);
	return inv_count;
}

void merge_sort(int *arr, int size)
{
	int start_index = 0;
	int inv_count = _merge_sort(arr, start_index, size-1);
	printf("Inversion Count : %d\n", inv_count);
}

int main()
{
	int arr[] = {1, 20 ,6, 4, 5};
	print_arr(arr, 0, 4);
	merge_sort(arr, 5);
	print_arr(arr, 0, 4);
}
