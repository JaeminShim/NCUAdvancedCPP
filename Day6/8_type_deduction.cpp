// 8. type deduction - 129 page

#include <iostream>
using namespace std;

// 129 page
// 규칙 1. Parameter 타입이 참조나 포인터가 아닌 경우
//        인자의 const, volatile, reference는 모두 무시한다.
template<typename T> void foo(T a) { }

// 130 page
// 규칙 2. ParamType이 참조나 포인터인 경우
//        인자의 레퍼런스만 무시한다. const, volatile은 적용된다.
template<typename T> void goo(T& a) { }

// 130 page
// 규칙 3. universal reference에
//        인자로 lvalue가 오면 T&
//        인자로 rvalue가 오면 T
// - int&  : lvalue reference
// - int&& : rvalue reference
// - T&&   : universal reference (또는 forward reference)
template<typename T> void hoo(T&& a) { }

int main()
{
	int x = 10;
	const int cx = x;
	const int& rx = cx;

	// 규칙 1
	foo(x);		// T: int
	foo(cx);	// T: int
	foo(rx);	// T: int

	// 규칙 2
	goo(x);		// T: int			/ a: int&
	goo(cx);	// T: const int		/ a: const int&
	goo(rx);	// T: const int		/ a: const int&

	// 규칙 3 (universal reference)
	hoo(x);		// T: int&			/ T&&: int& &&	=> int&
	hoo(10);	// T: int			/ T&&: int  &&	=> int&&
}
