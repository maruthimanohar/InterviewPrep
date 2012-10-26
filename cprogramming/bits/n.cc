#include <iostream>
int main()
{
	std::string s("Hello world");
	char * c = s.c_str();
	float f = strlen(c);
}
