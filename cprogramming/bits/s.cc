#include <iostream>
struct a{
	a(int val) : m_value(val) {}
	int m_value;
};
struct b : a{
	b(int val) : a(val) {}
};

int main()
{
	try {
		try {
			throw b(5);
		} catch (a A) {
			A.m_value *= 2;
			throw;
		} catch (b B) {
			B.m_value-= 2;
			throw B;
		}
	}
	catch (a A) {
		std::cout << A.m_value;
	}
	return 0;
}
