// 4. rvalue - 37 page

#include <iostream>
using namespace std;

int x = 10;
int foo() { return x; }
int& goo() { return x; }

int main()
{
	int a = 1, b = 2;

	//2 = a;		// ERROR - 2는 왼쪽에 올 수 없다. 2는 rvalue이다
	a = 2;			//
	b = a;			// a는 왼쪽과 오른쪽에  모두 올 수 있다. a는 lvalue이다.

	//foo() = 3;	// ERROR - 값을 리턴하는 함수는 rvalue, 임시객체도 rvalue.
	goo() = 3;		// OK - 참조를 리턴하는 함수는 lvalue.

	// 37page 참조
	// lvalue = rvalue, lvalue
	// lvalue: 이름이 있다...
}