#include <iostream>

struct foo {
	foo()  { std::cout << "d"; }
	foo(int i)  { std::cout << "i"; }
	foo(char c )  { std::cout << "c"; }
	foo(long l)  { std::cout << "l"; }
	foo(float f)  { std::cout << "f"; }
};
int main()
{
	foo f('a');
	foo f2('a' + 1);
	foo f3(1);
	foo f4(0x01);
	foo f5(0x0001L);
	foo f6(1.0f);
	return 0;
}

