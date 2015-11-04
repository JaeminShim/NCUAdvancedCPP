// 2. Variadic template - C++11/14 �̾߱� - 110 page

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
	// Parameter Pack�� �ٸ� �Լ��� �����ϴ� ���
	// "Pack Expansion" : ...�� pack �̸� �ڿ� ���δ�. 
	goo(args...);	// = goo(1, 2.3, "aaa");
	hoo(&args...);	// = goo(&1, &2.3, &"aaa");
	//hoo2(++args...);	// = goo(++1, ++2.3, ++"aaa");
	// ��Ÿ ��� - 117page ����
}

int main()
{
	foo(1, 2.3, "aaa");
}