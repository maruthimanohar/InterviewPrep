#include <stdio.h>

int next_greatest_elem(int num)
{
	int arr[10];
	int i = 0;
	for (i = 0; i < 10; i++)
		arr[i] = 0;
	int found = 0;
	while (num > 0) {
		int lsd = num % 10;
		printf("lsd = %d\n",lsd);
		num = num / 10;
		arr[lsd]++;
		i =0;
		for (i = lsd+1; i <= 9; i++) {
			if (arr[i] > 0) {
				found = 1;
				num = (num * 10) + i;
				printf("num = %d\n",num);
				arr[i]--;
				break;
			}
		}
		if (found)
			break;
	}

	if (found) {
		i = 0;
		while (i <= 9) {
			if (arr[i] > 0) {
				num = (num * 10) + i;
				arr[i]--;
			}
			if ( arr[i] == 0) {
				i++;
			}
		}
	}
	return num;
}

int main()
{
	int num = 677;
	printf("Next Greatest number : %d\n", next_greatest_elem(num));
}
