#include <stdio.h>
// Given an array all of whose elements are positive numbers,
// find the maximum sum of a subsequence with the constraint that
// no 2 numbers in the sequence should be adjacent in the array.
// So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7
// should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

#define MAX(a,b) a > b? a : b
int max_sum_non_adj(int *arr, int size)
{
	int max_incl = 0;
	int max_excl = 0;
	int new_excl = 0;
	int i=0;
	for (i = 0; i < size; i++) {
		new_excl = MAX(max_incl, max_excl);
		max_incl = max_excl + arr[i];
		max_excl = new_excl;
	}
	return MAX(max_incl, max_excl);
}

int main()
{
	int arr[] = { 5, 5, 10, 100, 10, 5};
	printf("Max Non Adj Sum : %d\n", max_sum_non_adj(arr, 6));
}
