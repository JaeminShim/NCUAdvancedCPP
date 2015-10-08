// <4> ���� - 3 (21page)
// ���ٸ� ��� ��

#include <iostream>

int main()
{
	auto f1 = [](int a, int b) { return a + b; };				// 1. auto
	int (*f2)(int, int) = [](int a, int b) { return a + b; };	// 2. �Լ� ������

	//f1 = &Add;	// ERROR: f1�� ���� Ÿ���� ���� �� ����. f1���� �ٸ� ���� ������ �� ����.
	//f2 = &Add;	// OK

	// ���� �ڵ��� �ζ��� ġȯ ���θ� ������ ������.
	f1(1, 2);	// ġȯ ��
	f2(1, 2);	// ġȯ �ȵ�. f2�� ���� ����
}