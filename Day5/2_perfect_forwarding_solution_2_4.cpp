// 2. 완벽한 전달자 - 해결책 2-4 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, const T& a)
{
	f(a);
}

// 완벽한 전달자 해결책 2.
// 1. 참조로 보내고 싶은 변수는 reference_wrapper<int>(x) 처럼 묶어서 보낸다.
// 2. reference_wrapper<int>()를 간단히 만들어 주는 ref()를 사용하면 편리하다.

int main()
{
	int x = 10;

	logTime(foo, 10);
	logTime(goo, ref(x));	// STL 표준

	cout << x << endl;
}
