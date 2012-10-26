
class foo
{

	public:
	virtual ~foo() {}
};
class bar:public foo{};
class bar2:public foo{};
class foobar:public bar{};
class foobar2:public bar2{};
int main()
{
	foo &foo2 = dynamic_cast<foo&>(*(new foobar2));
	//foo &foo2 = new foobar;
	//foobar2 *foo2 = new foo;
	//foo &foo2 = static_cast<foo&>(new foobar2);
//	foobar2 &foo2 = dynamic_cast<foo&>(new foobar2);

}

