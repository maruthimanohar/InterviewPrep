#include <stdio.h>
#include <stdlib.h>
main() {
	int a[10];
	int i = 0;
	for (i = 0; i < 10; i++)
		a[i] = i;
	int *ptr = (int *)malloc(sizeof(int) *10);
	for (i=0; i<10; i++) 
		ptr[i] = i+10;
	for (i = 0; i<10; i++) {
		printf("%d:%d\n",i,a[i]);	
	}
	for (i = 0; i<10; i++) {
		printf("%d:%d\n",i,(*ptr)+i);
	}
	int *t = ptr+5;
	printf("t:%d\n",*t);	
}
