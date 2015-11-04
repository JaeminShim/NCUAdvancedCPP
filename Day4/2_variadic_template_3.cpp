// 2. Variadic template - C++11/14 이야기 - 110 page

#include <iostream>
using namespace std;

void goo(int a, double b, const char* s)
{
	cout << "goo" << endl;
}

void hoo(int* a, double* b, const char** s)
{
	cout << "hoo" << endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// Parameter Pack을 다른 함수로 전달하는 방법
	// "Pack Expansion" : ...을 pack 이름 뒤에 붙인다. 
	goo(args...);	// = goo(1, 2.3, "aaa");
	hoo(&args...);	// = goo(&1, &2.3, &"aaa");
	//hoo2(++args...);	// = goo(++1, ++2.3, ++"aaa");
	// 기타 등등 - 117page 참고
}

int main()
{
	foo(1, 2.3, "aaa");
}