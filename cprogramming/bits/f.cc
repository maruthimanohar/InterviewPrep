#include <iostream>
using namespace std;
class base {
	public: int a;
	protected : int b;
	private: int c;


};
class d:base {
	friend class Friend;
	int da;
};

class Friend {
	d D;
	int f()
	{
		cout << a << b << da;
	}
};
int main()
{
	Friend al;
	al.f();
}
