// 2. �Ϻ��� ������ - �ذ�å 2-1 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

int main()
{
	int x = 10;

	//logTime(goo, x);	// x�� ���� ���޵ȴ�. �����Ϸ��� �޸� ������ ���޵Ǿ�� ��
	logTime(goo, &x);	// �ּҸ� �������Ƿ� �޸� ������ ���� ��
						// �����͸� ���۷����� ������ �� �ֱ⸸ �ϸ� ��

	cout << x << endl;
}
