// <4> 람다 - 4 (22page)
// 람다와 함수 인자

#include <iostream>

//void foo([무슨 타입?] f)

// [1] void foo(int (*f)(int, int))		// OK: 하지만 inline 치환 안됨
// [2] void foo(auto f)					// ERROR: auto는 함수 인자가 될 수 없음

// 다양한 모양의 람다를 받으려면 템플릿 밖에 없다. 서로 람다는 서로 다른 타입이기 때문.
template<typename T>
void foo (T f)
{
	f(1, 2);
}

int main()
{
	foo([](int a, int b) { return a + b; });
}