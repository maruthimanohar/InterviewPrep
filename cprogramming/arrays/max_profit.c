#include <stdio.h>

int main()
{
	int a[8] = {-2,4,30,-50,90,-60,100,120};
	int buy_price = a[0];
	int sell_price = a[0];
	int i=0;
	int max_profit = 0;
	int min = a[0];
	for (i=0; i<8; i++) {
		if (a[i] < min) {
			min = a[i];
			continue;
		}
		if ((a[i] - min ) > max_profit) {
			max_profit = a[i] - min;
			buy_price = min;
			sell_price = a[i];
		}
	}
	printf("profit:%d  buy:%d sell:%d\n", max_profit, buy_price, sell_price);
}
