// 4. rvalue - 38 page
// rvalue와 참조 이야기

#include <iostream>
using namespace std;

struct Point {};

Point p;
Point foo() { return p; }
Point& goo() { return p; }

int main()
{
	int n = 10;

	// 규칙 1. C++의 참조는 lvalue만 가리킬 수 있다.
	int&   r1 = n;				// OK - lvalue
	//int& r2 = 10;				// ERROR - 10은 rvalue
	Point& r3 = foo();			// ERROR (MSVC는 예외) - 임시객체는 rvalue이다
	Point& r4 = goo();			// OK - lvalue

	// 규칙 2. C++의 const 참조는 lvalue와 rvalue 모두를 가리킬 수 있다.
	const int&   r5 = n;		// OK
	const int&   r6 = 10;		// OK
	const Point& r7 = foo();	// OK - 임시객체의 lifecycle이 r7 변수의 scope로 연장!
	const Point& r8 = goo();	// OK

	// 규칙 3. C++11/14의 rvalue reference는 rvalue만 가리킬 수 있다.
	//int&& r9 = n;				// ERROR - n은 lvalue
	int&&   r10 = 10;			// OK
	Point&& r11 = foo();		// OK - 임시객체의 lifecycle이 r7 변수의 scope로 연장!
	//Point&& r12 = goo();		// ERROR - 리턴값은 lvalue

	// reference => lvalue reference 와 rvalue reference 로 분리
}