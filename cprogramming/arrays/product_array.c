// Given an array arr[] of n integers, construct a Product Array prod[] (of same size)
// such that prod[i] is equal to the product of all the elements of arr[] except arr[i].
// Solve it without division operator and in O(n).

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int start_index, int end_index)
{
	int i=0;
	for (i = 0; i <= end_index; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
}

void product_array(int *arr, int size)
{
	int product = 1;
	int i = 0;
	int *prod = (int *)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		prod[i] = product;
		product = product * arr[i];
	}
	product = 1;
	for (i = size-1; i >= 0; i--) {
		prod[i] = prod[i] * product;
		product = product * arr[i];
	}

	print_array(prod, 0, size -1);
	free(prod);
}

int main()
{
	int arr[] = {10, 3, 5, 6, 2};
	print_array(arr, 0, 4);
	product_array(arr, 5);
}
