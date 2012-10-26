#include <stdio.h>

unsigned int reversebits(unsigned int num)
{
	int count = sizeof(unsigned int) * 8;
	unsigned int result;
	while (num) {
		result = result | (num & 1);
		result = result << 1;
		num = num >> 1;
		count--;
	}
	result = result << (count - 1);
	return result;
}

int main()
{
	unsigned num = 1;
	printf("%u\n", reversebits(num));
}
