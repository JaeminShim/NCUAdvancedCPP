// <4> 람다 - 5 (23page)
// 람다와 리턴타입

#include <iostream>

int main()
{
	// 람다: ()연산자 함수를 가진 클래스를 만드는 표현식!

	// 람다의 리턴타입
	// 1. 생략
	auto f1 = [](int a, int b) { return a + b; };			// OK. 생략 가능
	// 2. 리턴타입의 후위 표현식: trailing return, suffix return type
	auto f2 = [](int a, int b) -> int { return a + b; };
	// 3. 생략 - 리턴타입 추론 가능
	auto f3 = [](int a, int b) { if (a == 1) return a; return b; };
	// 4. 생략불가 - 리턴타입 추론 불가
	auto f4 = [](int a, double b) -> double { if (a == 1) return a; return b; };
}