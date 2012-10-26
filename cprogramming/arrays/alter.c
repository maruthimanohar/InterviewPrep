#include <stdio.h>

void alter(char *arr, int mid, int len)
{
	if (!arr || mid == 0 || len == 0)
		return;
	int tmp = arr[mid];
	int k = mid;
	k = k-1;
	alter(arr, k, len);
	arr[mid+k] = arr[len/2+k];
	arr[mid + k +1] = tmp;
	return;
}

int main()
{
	char arr[10] = {'1','2','3','4','5','a','b','c','d','e'};
	int mid, len, i;
	len = 10;
	mid = len/2;
	alter(arr, mid-1, len);
	for (i=0; i<len; i++) {
		printf("%c,",arr[i]);
	}
	printf("\n");
}
