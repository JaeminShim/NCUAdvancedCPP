// 2. �Ϻ��� �������� �ʿ伺 - 142page

// [�Ϻ��� ������] Perfect forwarding
// : �Լ��� ���� ���� �Լ��� ���� �� �Ķ���͸� �Ϻ��ϰ� �����ϴ� ���
// ***�ſ� �߿�***

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

// Ư�� �Լ��� ������ ������ �� �ִ� �Լ��� ����� ���ô�.
template <typename F, typename T> void logTime(F f, T a)
{
	// �ð� ���
	f(a); // �Լ� ȣ��
	// �ٽ� �ð� ���� �� ���
}

int main()
{
	int x = 10;

	//foo(10);
	//goo(x);

	logTime(foo, 10);
	logTime(goo, x);

	cout << x << endl;
}
