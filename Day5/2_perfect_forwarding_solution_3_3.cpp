// 3. 완벽한 전달자 - 해결책 3-3 - 146page

#include <iostream>
using namespace std;

void f1(int   a) { cout << "f1" << endl; }
void f2(int&  r) { cout << "f2" << endl; }
void f3(int&& r) { cout << "f3" << endl; }

template <typename F, typename T> void logTime(F f, T&& a)
{
	//f(a);		// 이렇게 하면 f1, f2는 모두 OK.
				// 하지만 a가 lvalue이므로 함수 인자가 rvalue reference인 f3은 전달될 수 없다.
				// 그래서 forward<>가 필요하다.

	f(forward<T>(a));	// f1, f2, f3 모두 OK

	// 결론: 원래 함수에 인자를 전달할 때는 반드시 forward<>()로 묶어야 한다.
}

int main()
{
	int n = 10;

	logTime(f1, 10);
	logTime(f2, n);
	logTime(f3, 10);
}
