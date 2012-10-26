#include <stdio.h>

void merge(int *a, int *b, int count1, int count2)
{
	int end = count1 + count2 -1;
	int pos1 = count1 -1 ;
	int pos2 = count2 - 1;
	while (pos1 >= 0 && pos2 >= 0) {
		if (a[pos1] > b[pos2]) {
			b[end--] = a[pos1--];
		} else {
			b[end--] = b[pos2--];
		}
	}
	while (pos1 >= 0) {
		b[end--] = a[pos1--];
	}
	return;
}

int main()
{
	int a[5] = { 2, 4, 6, 8, 10};
	int b[10] = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0};
	merge(a, b, 5, 5);
	int i;
	for (i = 0; i< 10; i++) {
		printf("%d,", b[i]);
	}
	printf("\n");
}
