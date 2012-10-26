class a{
	public:
	       void f(int &a) {}
};

int main()
{
	void (a::*f)(int &);
}
