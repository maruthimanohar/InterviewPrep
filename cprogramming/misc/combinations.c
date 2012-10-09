#include <stdio.h>

void print_odd_paths(int x, int *arr, int pos, int min)
{
	int i=0;
	if (x == 0)
	{
		for (i=0; i<pos; i++)
			printf("%d,", arr[i]);
		printf("\n");
	}

	for (i = min; i <= x; i = i+2) {
		arr[pos] = i;
		print_odd_paths(x-i, arr, pos+1, i);
	}
}

void print_combinations(int x, int *arr, int pos, int *denoms, int min_index, int max_index)
{
	int i =0;
	if (x == 0) {
		for (i=0; i<pos; i++)
			printf("%d,", arr[i]);
		printf("\n");
		return;
	}
	for (i = min_index; i <= max_index; i++) {
		if (denoms[i] <= x) {
			arr[pos] = denoms[i];
			print_combinations(x-denoms[i], arr, pos+1, denoms, i, max_index);
		} else {
			break;
		}

	}
}

int main()
{
	int x;
	int arr[10] = {0};
	int denoms[6] = { 1, 2, 3, 4, 5, 6};
//	print_odd_paths(8, arr, 0, 1);
	print_combinations(10, arr, 0, denoms, 0, 5);
}
