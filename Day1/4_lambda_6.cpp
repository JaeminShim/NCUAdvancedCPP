// <4> ���� - 6 (24page)
// 

#include <iostream>

int main()
{
	int v1 = 10, v2 = 20;

	// ���� ���� ���
	//auto f1 = [](int a) { return a + v1; };			// ERROR
	auto f2 = [v1](int a) { return a + v1; };			// OK (v1 ���� ���� ���)
	auto f3 = [v1, v2](int a) { return a + v1; };
	auto f4 = [=](int a) { return a + v1; };			// ��� ���� ���� ���
	auto f5 = [&v1](int a) { v1 = 20; return a + v1; };	// ���� ���� ����

	std::cout << f2(10) << std::endl;
	std::cout << f5(10) << std::endl;
	std::cout << v1 << std::endl;
}