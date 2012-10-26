#include <stdio.h>
// Equilibrium index of an array is an index such that the sum of elements
// at lower indexes is equal to the sum of elements at higher indexes.
// The equilibrium index should not be included in the left or right sum.

int equilibrium_index(int *arr, int size)
{
	int sum = 0;
	int equi_index = -1;
	int i =0;
	// find the total sum
	for (i = 0; i < size; i++)
		sum = sum + arr[i];
	// starting from the start, calculate the leftsum and,
	// subtracting the elem from sum to get right sum and compare.
	int left_sum = 0;
	for (i = 0; i < size ; i++) {
		sum = sum - arr[i];
		if (left_sum == sum) {
			equi_index = i;
			break;
		}
		left_sum = left_sum + arr[i];
	}
	return equi_index;
}
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0};
	printf("Equilibrium Index : %d\n", equilibrium_index(arr, 7));

}
