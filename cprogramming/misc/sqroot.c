#include <stdio.h>

int main()
{
	float num = 16;
	float x1=num,x2=0;
	x2=.5*(x1+num/x1);
	while((x1-x2)!=0)
	{
		printf("x1 : %f    x2 : %f\n",x1, x2);
		x1=x2;
		x2=.5*(x1+num/x1);
	}
	printf("%f\n",x2);
	printf("%f\n", x2 * x2);
}
