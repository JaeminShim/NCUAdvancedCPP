// 5. move
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cat
{
public:
	// C++11 부터는 생성자가 3개 입니다.
	// 1. 일반 생성자
	Cat()				{ }
	// 2. Copy constructor (깊은 복사, 참조 계수)
	Cat(const Cat& c)	{ cout << "copy" << endl; }
	// 3. Move constructor (소유권 이전 규칙 사용)
	Cat(Cat&&)			{ cout << "move" << endl; }

	~Cat() {}

	Cat& operator=(const Cat& c)	{ cout << "copy=" << endl; return *this; }

	Cat& operator=(Cat&& c)			{ cout << "move=" << endl; return *this; }
};

// Rule of five : 복사생성자, 복사대입연산자, move생성자, move대입연산자, 소멸자


// C++에는 다음과 같은 함수가 있습니다. (아래와 동일하지는 않습니다) - page 57
//template <typename T>
//T&& move(T& a)
//{
//	return static_cast<T&&>(a);
//}

template <typename T>
void Swap(T& a, T& b)
{
	T tmp = move(a);
	a = move(b);
	b = move(tmp);
}

int main()
{
	Cat c1, c2;
	Swap(c1, c2);
}