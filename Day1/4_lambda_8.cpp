// <4> ���� - 8 (24page)
// 

#include <iostream>

class Test
{
	int data;

public:
	void foo()	// == void foo(Test* test)
	{
		//auto f = [this]() { std::cout << data << std::endl; };
		//auto f = [=]() { std::cout << data << std::endl; };

		// [����] - ���� ������ closure object�� �����غ���!
		// - ĸ���� ������ this.
		// - ���� ������ ���� ���ϰ� ��
		auto f = [=]() { data = 0; };
	}
};

int main()
{
	Test t;
	t.foo();
}