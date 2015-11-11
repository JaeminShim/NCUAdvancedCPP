// 2. �Ϻ��� ������ - �ذ�å 2-5 - 145page
// ��� ����

#include <iostream>
using namespace std;

void foo(int a)			{ cout << "foo" << endl; }
void goo(int a, int &b)	{ cout << "goo : " << a << ", " << b << endl; b = 100; }

// C++ ǥ�ؿ��� ��� �Լ��� �ּҸ� ���� �� �ִ� ���� �Լ� �����Ͱ� �ֽ��ϴ�.
#include <functional>
using namespace std::placeholders;	// bind()�� _1, _2, ... �� ����ϱ� ���ؼ�

int main()
{
	function<void(int)> f;	// ��� �Լ��� �ּҸ� ���� �� �ֽ��ϴ�.
	f = &foo;
	f(10);

	int x = 10;
	f = bind(&goo, _1, ref(x));		// goo�� 1��° ���ڴ� f(����)�� �����ϰ�
								//       2��° ���ڴ� x�� ����
	f(10);	// goo(10, x);

	cout << x << endl;
}
