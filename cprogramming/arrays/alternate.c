#include <stdio.h>

/*Recursive solution*/
void Alter(char *arr, int mid, int len)
{
	if(!arr || (len == 0) || (mid == 0))
		return;
	int tmp = arr[mid];
	int k = mid;
	Alter(arr, --k, len);
	arr[mid + k] = arr[len/2 + k];
	arr[mid + k + 1] = tmp;
	return;
}

int main()
{
	char arr[10] = {'1', '2', '3', '4', '5', 'a', 'b', 'c', 'd', 'e'};
	int mid, len, i = 0;
	len = 10;
	mid = len/2;
	printf("\n Array before Alternation = ");
	for(i = 0; i < len; i++)
		printf("%c ", arr[i]);
	Alter(arr, mid-1, len);
	printf("\n Array after Alternation  = ");
	for(i = 0; i < len; i++)
		printf("%c ", arr[i]);
	printf("\n");
	return;
}
