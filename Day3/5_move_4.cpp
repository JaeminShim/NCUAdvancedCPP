// 5. move
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cat
{
public:
	// C++11 ���ʹ� �����ڰ� 3�� �Դϴ�.
	// 1. �Ϲ� ������
	Cat()				{ }
	// 2. Copy constructor (���� ����, ���� ���)
	Cat(const Cat& c)	{ cout << "copy" << endl; }
	// 3. Move constructor (������ ���� ��Ģ ���)
	Cat(Cat&&)			{ cout << "move" << endl; }

	~Cat() {}

	Cat& operator=(const Cat& c)	{ cout << "copy=" << endl; return *this; }

	Cat& operator=(Cat&& c)			{ cout << "move=" << endl; return *this; }
};

// Rule of five : ���������, ������Կ�����, move������, move���Կ�����, �Ҹ���


// C++���� ������ ���� �Լ��� �ֽ��ϴ�. (�Ʒ��� ���������� �ʽ��ϴ�) - page 57
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