// <4> ���� - 2 (21page)
// ���ٿ� Ÿ��

#include <iostream>

int main()
{
	// ���ٿ� Ÿ��
	// - ���ٴ� auto ������ ���� �� �ִ�.
	auto f1 = [](int a, int b) { return a + b; };	// ClosureObject f1;
	auto f2 = [](int a, int b) { return a + b; };

	// RTTI�� ����Ͽ� Ÿ�� �̸� ���
	std::cout << typeid(f1).name() << std::endl << typeid(f2).name() << std::endl;

	std::cout << f1(1, 2) << std::endl;
}