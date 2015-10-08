// <4> 람다 - 8 (24page)
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

		// [과제] - 다음 람다의 closure object를 예상해보자!
		// - 캡쳐한 변수는 this.
		// - 따라서 원본의 값이 변하게 됨
		auto f = [=]() { data = 0; };
	}
};

int main()
{
	Test t;
	t.foo();
}