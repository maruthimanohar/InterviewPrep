#include <stdio.h>

int binary_search(int elem, int *arr, int start, int end)
{
	if (start > end)
		return -1;
/*	if (arr[start] == elem)
		return start;
	if (arr[end] == elem)
		return end;*/
	int mid = start + ((end-start)/2);
	if (arr[mid] == elem)
		return mid;
	if (arr[mid] < arr[start])
	{
		if (elem > arr[mid] && elem <= arr[end]) {
			return binary_search(elem, arr, mid+1, end);
		}
		return binary_search(elem, arr, start, mid-1);

	} else {
		if (elem >= arr[start] && elem < arr[mid]) {
			return binary_search(elem, arr, start, mid-1);
		}
		return binary_search(elem, arr, mid+1, end);
	}
	return -1;
}
int main()
{
	int arr[10] = { 7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
	int i = 0;
	for (i=0; i< 10; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	for (i =1; i <= 10; i++)
		printf("%d:%d\n", i, binary_search(i, arr, 0, 9));
}
