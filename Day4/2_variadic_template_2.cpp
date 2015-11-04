// 2. Variadic template - C++11/14 이야기 - 110 page

#include <iostream>
using namespace std;

template<typename ... Types> void foo(Types ... args)
{
	// sizeof...() : Parameter Pack의 크기를 구하는 연산자 - 110page 3번
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;
}

int main()
{
						//-------------------------------------------------
						// Types					|	args ("Parameter pack")
						//-------------------------------------------------
	foo(1);				// int						|	1
	foo(1, 2.3);		// int, double				|	1, 2.3
	foo(1, 2.3, "aaa");	// int, double, const char*	|	1, 2.3, "aaa"
						//-------------------------------------------------
}