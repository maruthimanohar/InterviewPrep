#include <iostream>
int main()
{
	int i,j;
	std::string s;
	int a = 5;
	{ int a = 6;
		std::cout << a;
	}
	std::cin >> i >> j >> s >> s >> i;
	std::cout << i << " " << j << " " << s << " " << i;
}
