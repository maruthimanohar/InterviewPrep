#include <iostream>
class a{};

void foo()
{
	throw new a;
}
int main()
{
	try {
		foo();
	} catch (a *e){
		std::cout << "caught\n";
	}
}
