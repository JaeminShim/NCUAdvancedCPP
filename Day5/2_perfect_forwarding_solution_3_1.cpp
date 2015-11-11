// 3. 완벽한 전달자 - 해결책 3-1 - 146page
// 참고: [folly] An opensource C++ library developed and used at Facebook

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

//template <typename F, typename T> void logTime(F f, T a)
//{
//	f(a);
//}

// C++11에서는 완벽한 전달자를 위해 universal reference라는 새로운 개념이 등장합니다.
template <typename F, typename T> void logTime(F f, T&& a)
{
	f(a);
}

// int&  : lvalue reference. lvalue를 가리킨다. (변수)
// int&& : rvalue reference. rvalue를 가리킨다. (상수, 임시객체)
// T&&   : universal refernce (또는 forward reference)	(T는 템플릿)
//		   함수에 lvalue를 보내면 T는 lvalue reference (T가 int일 때, int&)
//		   함수에 rvalue를 보내면 T는 rvalue reference (T가 int일 때, int&&)

int main()
{
	int x = 10;

	logTime(foo, 10);	// rvalue	// T: int&&	=> int&& && a	=> int && a
	logTime(goo, x);	// lvalue	// T: int&	=> int&  && a	=> int &  a

	// reference confliction 규칙
	// & &		=> &
	// & &&		=> &
	// && &		=> &
	// && &&	=> &&

	cout << x << endl;
}
