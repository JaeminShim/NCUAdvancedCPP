// 4. rvalue - 37 page

#include <iostream>
using namespace std;

int x = 10;
int foo() { return x; }
int& goo() { return x; }

int main()
{
	int a = 1, b = 2;

	//2 = a;		// ERROR - 2�� ���ʿ� �� �� ����. 2�� rvalue�̴�
	a = 2;			//
	b = a;			// a�� ���ʰ� �����ʿ�  ��� �� �� �ִ�. a�� lvalue�̴�.

	//foo() = 3;	// ERROR - ���� �����ϴ� �Լ��� rvalue, �ӽð�ü�� rvalue.
	goo() = 3;		// OK - ������ �����ϴ� �Լ��� lvalue.

	// 37page ����
	// lvalue = rvalue, lvalue
	// lvalue: �̸��� �ִ�...
}