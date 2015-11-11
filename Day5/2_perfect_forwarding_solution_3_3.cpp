// 3. �Ϻ��� ������ - �ذ�å 3-3 - 146page

#include <iostream>
using namespace std;

void f1(int   a) { cout << "f1" << endl; }
void f2(int&  r) { cout << "f2" << endl; }
void f3(int&& r) { cout << "f3" << endl; }

template <typename F, typename T> void logTime(F f, T&& a)
{
	//f(a);		// �̷��� �ϸ� f1, f2�� ��� OK.
				// ������ a�� lvalue�̹Ƿ� �Լ� ���ڰ� rvalue reference�� f3�� ���޵� �� ����.
				// �׷��� forward<>�� �ʿ��ϴ�.

	f(forward<T>(a));	// f1, f2, f3 ��� OK

	// ���: ���� �Լ��� ���ڸ� ������ ���� �ݵ�� forward<>()�� ����� �Ѵ�.
}

int main()
{
	int n = 10;

	logTime(f1, 10);
	logTime(f2, n);
	logTime(f3, 10);
}
