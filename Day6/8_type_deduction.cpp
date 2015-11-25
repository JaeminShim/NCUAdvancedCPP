// 8. type deduction - 129 page

#include <iostream>
using namespace std;

// 129 page
// ��Ģ 1. Parameter Ÿ���� ������ �����Ͱ� �ƴ� ���
//        ������ const, volatile, reference�� ��� �����Ѵ�.
template<typename T> void foo(T a) { }

// 130 page
// ��Ģ 2. ParamType�� ������ �������� ���
//        ������ ���۷����� �����Ѵ�. const, volatile�� ����ȴ�.
template<typename T> void goo(T& a) { }

// 130 page
// ��Ģ 3. universal reference��
//        ���ڷ� lvalue�� ���� T&
//        ���ڷ� rvalue�� ���� T
// - int&  : lvalue reference
// - int&& : rvalue reference
// - T&&   : universal reference (�Ǵ� forward reference)
template<typename T> void hoo(T&& a) { }

int main()
{
	int x = 10;
	const int cx = x;
	const int& rx = cx;

	// ��Ģ 1
	foo(x);		// T: int
	foo(cx);	// T: int
	foo(rx);	// T: int

	// ��Ģ 2
	goo(x);		// T: int			/ a: int&
	goo(cx);	// T: const int		/ a: const int&
	goo(rx);	// T: const int		/ a: const int&

	// ��Ģ 3 (universal reference)
	hoo(x);		// T: int&			/ T&&: int& &&	=> int&
	hoo(10);	// T: int			/ T&&: int  &&	=> int&&
}
