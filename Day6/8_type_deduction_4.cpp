// 8. type deduction 4

#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

// 완벽한 전달자 함수의 리턴 타입을 생각해 봅시다.
// 아래처럼 하면 참조를 리턴하는 함수에서 문제가 됩니다.
//template<typename F> auto LogTime(F f)	// 문제 : auto의 type deduction은 완벽하지 못함.
//template<typename F> auto LogTime(F f) -> decltype(f())		// C++11
template<typename F> decltype(auto) LogTime(F f)				// C++14
{
	return f();
}

int main()
{
	int& n = LogTime(foo);

	cout << n << endl;
	n = 30;
	cout << x << endl;
}