#include<stdio.h>
int main()
{
	int ia[] = { 1, 2, 3};
	int *pia = ia;
	const int *pci = pia;
	int x = *pci;
	//*pci = 5;
	int j = *(pci++);
}
