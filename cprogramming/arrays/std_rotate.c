#include <stdio.h>

void print_array(int *arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void rotate_array(int *arr, int first, int middle, int last)
{
	int next = middle;
	while (first != next) {
		printf("f:%d n:%d l:%d m:%d\n", first, next, last, middle);
		printf("swapping elements at position %d and %d\n", first, next);
		swap(arr+first, arr+next);
		print_array(arr, 10);
		first++;
		next++;
		if (next == last)
			next = middle;
		else if (first == middle)
			middle = next;

	}
}

int main()
{
	int arr[10] = { 1, 2 , 3, 4, 5, 6, 7, 8, 9, 10};
	int i = 0;
	print_array(arr, 10);
	rotate_array(arr, 0, 7, 10);
	print_array(arr, 10);
}
