// 3. 완벽한 전달자 - 해결책 3-2 - 146page

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
	// int&& a가 되었을 때 int&&는 rvalue_reference지만, a는 lvalue이다.

	// * 이름 있는 rvalue reference는 lvalue이다 - 39page
	// lvalue 보내면 T&&: lvalue reference이고 a는 lvalue이다.
	// rvalue 보내면 T&&: rvalue refernece이고 a는 lvalue이다.

	//f(static_cast<T&&>(a));		// lvalue를 보내면 a를 lvalue로 캐스팅
	//								// rvalue를 보내면 a를 rvalue로 캐스팅

	// C.
	// 위 역할을 해주는 함수가 forward 입니다.
	f(forward<T>(a));				// T만 보내도 forward 함수 안에서 T&&로 캐스팅 해줍니다.
}

int main()
{
	int n = 0;

	//foo(n);		// ERROR: lvalue
	//foo(10);		// OK

	logTime(foo, 10);	// foo(10)이 되므로, 이 코드도 실행되어야 함.
}
