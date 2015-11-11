// 2. �Ϻ��� ������ - �ذ�å 2-4 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, const T& a)
{
	f(a);
}

// �Ϻ��� ������ �ذ�å 2.
// 1. ������ ������ ���� ������ reference_wrapper<int>(x) ó�� ��� ������.
// 2. reference_wrapper<int>()�� ������ ����� �ִ� ref()�� ����ϸ� ���ϴ�.

int main()
{
	int x = 10;

	logTime(foo, 10);
	logTime(goo, ref(x));	// STL ǥ��

	cout << x << endl;
}
