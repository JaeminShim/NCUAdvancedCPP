// <4> ���� - 4 (22page)
// ���ٿ� �Լ� ����

#include <iostream>

//void foo([���� Ÿ��?] f)

// [1] void foo(int (*f)(int, int))		// OK: ������ inline ġȯ �ȵ�
// [2] void foo(auto f)					// ERROR: auto�� �Լ� ���ڰ� �� �� ����

// �پ��� ����� ���ٸ� �������� ���ø� �ۿ� ����. ���� ���ٴ� ���� �ٸ� Ÿ���̱� ����.
template<typename T>
void foo (T f)
{
	f(1, 2);
}

int main()
{
	foo([](int a, int b) { return a + b; });
}