// 6. �Ϻ��� ������

#include <iostream>
using namespace std;

void foo(int) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 20; }

// perfect forwarding�� �Ƿ��� rvalue, lvalue���� �� return�� ���޵� �����ؾ� ��
template <typename F, typename A>
void logTime(F f, A a)
{
	// �ð� ���
	f(a);
	// �ð� ������ ���
}

int main()
{
	int n = 10;
	logTime(foo, 10);
	logTime(goo, n);	// n�� goo�� ���� ���� ��ȭ�ؾ� ��

	cout << n << endl;
}