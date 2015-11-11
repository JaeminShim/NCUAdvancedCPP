// 2. �Ϻ��� ������ - �ذ�å - 144page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

// �ذ�å 1. �Լ� �����ε� ��� (������ ��� ����(�Ǵ� ��))
// ������: ���� N���� perfect forwarding �Ϸ��� 2^N ���� logTime()�� �ʿ��ϴ�.
template <typename F, typename T> void logTime(F f, T& a)		// 1
{
	f(a);
}

template <typename F, typename T> void logTime(F f, const T& a)	// 2
{
	f(a);
}

int main()
{
	int x = 10;

	logTime(foo, 10);	// int&&�� ������ ȣ��, ������ 2�� ȣ��
	logTime(goo, x);	// int& ��, 1�� ȣ��, ������ 2�� ȣ��

	cout << x << endl;
}
