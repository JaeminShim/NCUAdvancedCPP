// 2. Variadic template - C++11/14 이야기 - 108 page

#include <iostream>
using namespace std;

// 가변 인자 템플릿의 기본 모양
template<typename ... Types>
class stack
{
};

// 가변인자 함수 템플릿
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