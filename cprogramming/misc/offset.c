#include <stdio.h>
#define OFFSETOF(type, field)    &(((type *) 0)->field)

struct s{
	int a;
	char b;
	char d;
	int c;
}__attribute__((__packed__));

int main()
{
	printf("%u\n",OFFSETOF(struct s, c));
}
