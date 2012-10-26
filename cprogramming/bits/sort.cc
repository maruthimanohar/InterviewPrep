#include <iostream>
int main()
{
	int v[1000];
	std::sort((void *)v , (void *)&v + 1000, sizeof(int));
}
