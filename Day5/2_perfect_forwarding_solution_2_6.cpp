// 2. �Ϻ��� ������ - �ذ�å 2-6 - 145page
// bind ����

#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;	// bind()�� _1, _2, ... �� ����ϱ� ���ؼ�

void foo(int a, int &b, int c, int &d)
{
	cout << "foo" << "(" << a << ", " << b << ", " << c << ", " << d << ")" << endl;
	b = 20;
	d = 40;
}


int main()
{
	int x = 1, y = 1, z = 1;

	function<void(int, int)> f;

	// ���� �����غ���
	f = bind(&foo, _2, ref(x), _1, ref(z));

	f(10, 20);	// foo(10, x, 20, z)�� ���޵ǰ� �غ�����.

	cout << x << endl;
	cout << z << endl;
}
