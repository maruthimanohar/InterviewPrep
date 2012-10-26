#include <stdio.h>

void print_array(int *arr, int start_index, int end_index)
{
	int i = 0;
	for (i = start_index; i <= end_index; i++)
		printf("%d,",arr[i]);
	printf("\n");
}

void segregate_two(int *arr, int size) {
	int left_index = 0;
	int right_index = size -1;
	while (left_index < right_index) {
		while (arr[left_index] == 0)
			left_index++;
		while (arr[right_index] == 1)
			right_index--;
		if (left_index < right_index) {
			arr[left_index++] = 0;
			arr[right_index--] = 1;
		}
	}
}

int swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void segregate_three(int *arr, int size)
{
	int left_index = 0;
	int right_index = size -1;
	while (left_index < right_index) {
		if (arr[left_index] == 0)
			left_index++;
		else
			break;
	}
	if (left_index == right_index)
		return;
	while (right_index > left_index) {
		if (arr[right_index] == 2)
			right_index--;
		else
			break;
	}

	if (left_index == right_index)
		return;
	print_array(arr, 0, 11);
	int current = left_index;
	while (current <= right_index) {
		if(arr[current] == 0)
			swap(&arr[left_index++], &arr[current++]);
		else if (arr[current] == 1)
			current++;
		else
			swap(&arr[current], &arr[right_index--]); // donot increment current, the current right index might contain zero
	}
}

int main()
{
	int arr[] = {0, 0, 1, 1, 0, 0, 1};
	print_array(arr,0, 6);
	segregate_two(arr, 7);
	print_array(arr, 0, 6);

	int arr1[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	print_array(arr1, 0, 11);
	segregate_three(arr1, 12);
	print_array(arr1, 0, 11);
}
