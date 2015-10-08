// <4> 람다 - 3 (21page)
// 람다를 담는 법

#include <iostream>

int main()
{
	auto f1 = [](int a, int b) { return a + b; };				// 1. auto
	int (*f2)(int, int) = [](int a, int b) { return a + b; };	// 2. 함수 포인터

	//f1 = &Add;	// ERROR: f1과 같은 타입은 만들 수 없음. f1에는 다른 것을 대입할 수 없다.
	//f2 = &Add;	// OK

	// 다음 코드의 인라인 치환 여부를 생각해 보세요.
	f1(1, 2);	// 치환 됨
	f2(1, 2);	// 치환 안됨. f2는 변경 가능
}