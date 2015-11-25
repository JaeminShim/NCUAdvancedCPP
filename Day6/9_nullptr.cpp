// 9. nullptr

#include <iostream>
using namespace std;

void foo(void* p) { cout << "void*" << endl; }	// 1
void foo(int   n) { cout << "int"   << endl; }	// 2
void goo(char* p) { cout << "char*" << endl; }

int main()
{
	// A.
	foo(0);			// 2
	foo((void*)0);	// 1

	// 0은 정수(int)입니다. 포인터로 암시적 형변환 가능합니다. (컴파일러 특화된 특수 규칙)

	// B.
/*
#ifdef __cplusplus
	#define NULL 0
#else
	#define NULL (void*)0	// C++에서는 암시적 형변환(T*)이 불가능하여 문제
#endif
*/

	foo(NULL);		// int. 즉 버그
	goo(NULL);		// ERROR: 하지만 C에서는 OK (암시적 형변환 : char* => void*)

	foo(nullptr);	// 포인터 0을 나타낸다. 모든 타입의 포인터로 암시적 변환된다.
	goo(nullptr);
}