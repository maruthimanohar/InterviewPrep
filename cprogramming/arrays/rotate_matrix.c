#include <stdio.h>
#include <stdlib.h>

void print_array(int **arr, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void rotate_util(int **arr, int start, int end)
{
	int i = start;
	int j = end;
	while (i < end) {
		swap(&arr[start][i], &arr[i][end]);
		swap(&arr[start][i], &arr[end][j]);
		swap(&arr[start][i], &arr[j][start]);
		i++;
		j--;
	}

}
void rotate_array(int **arr, int n)
{
	int i = 0;
	int start = 0;
	int end = n -1;
	while (start < end) {
		rotate_util(arr, start, end);
		start++;
		end--;
	}
}

int main()
{
	int **arr;
	int i = 0, j = 0;
	int c = 1;
	int size = 4;
	arr = (int **)malloc(sizeof(int*) * size);
	for (i = 0; i < size; i++) {
		arr[i] = (int *)malloc(sizeof(int) * size);
	}

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			arr[i][j] = c++;
	print_array(arr, 4);
	rotate_array(arr, 4);
	printf("\n\n");
	print_array(arr, 4);
}
