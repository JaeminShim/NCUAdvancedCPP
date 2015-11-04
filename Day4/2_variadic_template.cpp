// 2. Variadic template - C++11/14 �̾߱� - 108 page

#include <iostream>
using namespace std;

// ���� ���� ���ø��� �⺻ ���
template<typename ... Types>
class stack
{
};

// �������� �Լ� ���ø�
template<typename ... Types> void foo(Types ... args)
{
}

int main()
{
	stack<int>				s1;
	stack<int, double>		s2;
	stack<int, double, int>	s3;

	foo(1);
	foo(1, 2L);
	foo(1, 2L, 3.f);
}