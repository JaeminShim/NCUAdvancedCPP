// 1. this call_8
// 다중 상속과 this

#include <iostream>
using namespace std;

class A
{
public:
	int a;
	void fa() { cout << this << endl; }
};

class B
{
public:
	int b;
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl;		// 100 번지라고 할 때

	ccc.fa();					// 100
	ccc.fb();					// 104
}