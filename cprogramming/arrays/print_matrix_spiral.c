#include <stdio.h>

void print_matrix_spiral(int arr[3][6], int max_row, int max_col)
{
	int row=0, col=0;
	int i;
	while(row <= max_row && col <= max_col) {
		for (i = col; i <= max_col; i++)
			printf("%d,",arr[row][i]);
		printf("\n");
		row++;
		for (i = row; i <= max_row; i++)
			printf("%d,",arr[i][max_col]);
		printf("\n");
		max_col--;
		if (row < max_row) {
			for (i = max_col; i >= col; i--)
				printf("%d,",arr[max_row][i]);
			printf("\n");
			max_row--;
		}
		if (col < max_col) {
			for (i = max_row; i >= row; i--)
				printf("%d,",arr[i][col]);
			printf("\n");
			col++;
		}
	}
}
int main()
{
	int arr[3][6] = { {1, 2, 3, 4, 5 , 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};
	print_matrix_spiral(arr, 2, 5);
}
