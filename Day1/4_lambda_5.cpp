// <4> ���� - 5 (23page)
// ���ٿ� ����Ÿ��

#include <iostream>

int main()
{
	// ����: ()������ �Լ��� ���� Ŭ������ ����� ǥ����!

	// ������ ����Ÿ��
	// 1. ����
	auto f1 = [](int a, int b) { return a + b; };			// OK. ���� ����
	// 2. ����Ÿ���� ���� ǥ����: trailing return, suffix return type
	auto f2 = [](int a, int b) -> int { return a + b; };
	// 3. ���� - ����Ÿ�� �߷� ����
	auto f3 = [](int a, int b) { if (a == 1) return a; return b; };
	// 4. �����Ұ� - ����Ÿ�� �߷� �Ұ�
	auto f4 = [](int a, double b) -> double { if (a == 1) return a; return b; };
}