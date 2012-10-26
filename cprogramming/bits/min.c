#include<stdio.h>
#define CHAR_BIT 8

/*Function to find minimum of x and y*/
int min(int x, int y)
{
	printf("%d\n", -9 >> 31);
	return 15 + ( 100 & -1 );
//	return  y + ((x - y) & ((x - y) >>
//				(sizeof(int) * CHAR_BIT - 1)));
}

/*Function to find maximum of x and y*/
int max(int x, int y)
{
	return x - ((x - y) & ((x - y) >>
				(sizeof(int) * CHAR_BIT - 1)));
}

/* Driver program to test above functions */
int main()
{
	int x = 6;
	int y = 15;
	printf("Minimum of %d and %d is ", x, y);
	printf("%d", min(x, y));
	printf("\nMaximum of %d and %d is ", x, y);
	printf("%d", max(x, y));
	getchar();
}
