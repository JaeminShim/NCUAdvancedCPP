// 4. rvalue - 38 page
// rvalue�� ���� �̾߱�

#include <iostream>
using namespace std;

struct Point {};

Point p;
Point foo() { return p; }
Point& goo() { return p; }

int main()
{
	int n = 10;

	// ��Ģ 1. C++�� ������ lvalue�� ����ų �� �ִ�.
	int&   r1 = n;				// OK - lvalue
	//int& r2 = 10;				// ERROR - 10�� rvalue
	Point& r3 = foo();			// ERROR (MSVC�� ����) - �ӽð�ü�� rvalue�̴�
	Point& r4 = goo();			// OK - lvalue

	// ��Ģ 2. C++�� const ������ lvalue�� rvalue ��θ� ����ų �� �ִ�.
	const int&   r5 = n;		// OK
	const int&   r6 = 10;		// OK
	const Point& r7 = foo();	// OK - �ӽð�ü�� lifecycle�� r7 ������ scope�� ����!
	const Point& r8 = goo();	// OK

	// ��Ģ 3. C++11/14�� rvalue reference�� rvalue�� ����ų �� �ִ�.
	//int&& r9 = n;				// ERROR - n�� lvalue
	int&&   r10 = 10;			// OK
	Point&& r11 = foo();		// OK - �ӽð�ü�� lifecycle�� r7 ������ scope�� ����!
	//Point&& r12 = goo();		// ERROR - ���ϰ��� lvalue

	// reference => lvalue reference �� rvalue reference �� �и�
}