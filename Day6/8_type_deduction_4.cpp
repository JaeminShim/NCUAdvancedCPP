// 8. type deduction 4

#include <iostream>
using namespace std;

int x = 10;

int& foo() { return x; }

// �Ϻ��� ������ �Լ��� ���� Ÿ���� ������ ���ô�.
// �Ʒ�ó�� �ϸ� ������ �����ϴ� �Լ����� ������ �˴ϴ�.
//template<typename F> auto LogTime(F f)	// ���� : auto�� type deduction�� �Ϻ����� ����.
//template<typename F> auto LogTime(F f) -> decltype(f())		// C++11
template<typename F> decltype(auto) LogTime(F f)				// C++14
{
	return f();
}

int main()
{
	int& n = LogTime(foo);

	cout << n << endl;
	n = 30;
	cout << x << endl;
}