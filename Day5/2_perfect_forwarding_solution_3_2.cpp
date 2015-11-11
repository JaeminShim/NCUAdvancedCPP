// 3. �Ϻ��� ������ - �ذ�å 3-2 - 146page

#include <iostream>
using namespace std;

void foo(int&& a) { cout << "foo" << endl; }

template <typename F, typename T> void logTime(F f, T&& a)
{
	// A.
	//f(a);

	// B.
	// T		= int&&
	// T&& a	= int&& &&a = int&& a
	// int&& a�� �Ǿ��� �� int&&�� rvalue_reference����, a�� lvalue�̴�.

	// * �̸� �ִ� rvalue reference�� lvalue�̴� - 39page
	// lvalue ������ T&&: lvalue reference�̰� a�� lvalue�̴�.
	// rvalue ������ T&&: rvalue refernece�̰� a�� lvalue�̴�.

	//f(static_cast<T&&>(a));		// lvalue�� ������ a�� lvalue�� ĳ����
	//								// rvalue�� ������ a�� rvalue�� ĳ����

	// C.
	// �� ������ ���ִ� �Լ��� forward �Դϴ�.
	f(forward<T>(a));				// T�� ������ forward �Լ� �ȿ��� T&&�� ĳ���� ���ݴϴ�.
}

int main()
{
	int n = 0;

	//foo(n);		// ERROR: lvalue
	//foo(10);		// OK

	logTime(foo, 10);	// foo(10)�� �ǹǷ�, �� �ڵ嵵 ����Ǿ�� ��.
}
