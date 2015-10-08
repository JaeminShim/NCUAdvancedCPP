// 2_인라인함수_2 (15page)

// 1. 인라인 함수는 컴파일 타임 문법
// 2. 함수 포인터에 담으면 인라인 치환이 안됨

#include <iostream>

		int Add1(int a, int b) { return a + b; }
inline	int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);	// 호출
	int n2 = Add2(1, 2);	// 치환

	int(*f)(int, int);
	f = &Add2;

	//-------------------------
	int n;
	std::cin >> n;
	if (n == 1)
		f = &Add1;

	// f가 가리키는 것을 컴파일러가 알 수 없음.
	// => f는 변수이기에 인라인 함수를 함수 포인터에 담으면 인라인 치환이 안 됨.
	//-------------------------

	f(1, 2);				// ??
}