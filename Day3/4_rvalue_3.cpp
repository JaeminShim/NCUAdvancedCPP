// 4. rvalue - 39 page
// reference�� �Լ� �����ε�

#include <iostream>
using namespace std;

void foo(int&)			{ cout << "int&" << endl; }			// 1
void foo(const int&)	{ cout << "const int&" << endl; }	// 2
void foo(int&&)			{ cout << "int&&" << endl; }		// 3

int main()
{
	int n = 10;

	// [A]
	foo(n);		// 1�� ȣ�� (������ 2�� ȣ��)
	foo(10);	// 3�� ȣ�� (������ 2�� ȣ��)

	// [B]
	int&& r = 10;
	foo(r);		// 1 or 2 or 3 ???

	// - 10: rvalue
	// - r:  rvalue rerference
	// (rvalue != rvalue reference)
	// �̸��� �ִ� rvalue reference�� lvalue�̴�!
	// "perfect forwarding" ��� �� �ݵ�� ����ؾ� �մϴ�.

	// [C]
	foo(static_cast<int&&>(r));	// rvalue�� ĳ����? rvalue�� ĳ������ rvalue reference?
}