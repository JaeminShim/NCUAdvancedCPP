// 4. rvalue - 39 page
// reference와 함수 오버로딩

#include <iostream>
using namespace std;

void foo(int&)			{ cout << "int&" << endl; }			// 1
void foo(const int&)	{ cout << "const int&" << endl; }	// 2
void foo(int&&)			{ cout << "int&&" << endl; }		// 3

int main()
{
	int n = 10;

	// [A]
	foo(n);		// 1번 호출 (없으면 2번 호출)
	foo(10);	// 3번 호출 (없으면 2번 호출)

	// [B]
	int&& r = 10;
	foo(r);		// 1 or 2 or 3 ???

	// - 10: rvalue
	// - r:  rvalue rerference
	// (rvalue != rvalue reference)
	// 이름이 있는 rvalue reference는 lvalue이다!
	// "perfect forwarding" 배울 때 반드시 기억해야 합니다.

	// [C]
	foo(static_cast<int&&>(r));	// rvalue로 캐스팅? rvalue로 캐스팅한 rvalue reference?
}