// <4> 람다 - 2 (21page)
// 람다와 타입

#include <iostream>

int main()
{
	// 람다와 타입
	// - 람다는 auto 변수에 담을 수 있다.
	auto f1 = [](int a, int b) { return a + b; };	// ClosureObject f1;
	auto f2 = [](int a, int b) { return a + b; };

	// RTTI를 사용하여 타입 이름 출력
	std::cout << typeid(f1).name() << std::endl << typeid(f2).name() << std::endl;

	std::cout << f1(1, 2) << std::endl;
}