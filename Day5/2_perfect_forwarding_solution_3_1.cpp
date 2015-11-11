// 3. �Ϻ��� ������ - �ذ�å 3-1 - 146page
// ����: [folly] An opensource C++ library developed and used at Facebook

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

//template <typename F, typename T> void logTime(F f, T a)
//{
//	f(a);
//}

// C++11������ �Ϻ��� �����ڸ� ���� universal reference��� ���ο� ������ �����մϴ�.
template <typename F, typename T> void logTime(F f, T&& a)
{
	f(a);
}

// int&  : lvalue reference. lvalue�� ����Ų��. (����)
// int&& : rvalue reference. rvalue�� ����Ų��. (���, �ӽð�ü)
// T&&   : universal refernce (�Ǵ� forward reference)	(T�� ���ø�)
//		   �Լ��� lvalue�� ������ T�� lvalue reference (T�� int�� ��, int&)
//		   �Լ��� rvalue�� ������ T�� rvalue reference (T�� int�� ��, int&&)

int main()
{
	int x = 10;

	logTime(foo, 10);	// rvalue	// T: int&&	=> int&& && a	=> int && a
	logTime(goo, x);	// lvalue	// T: int&	=> int&  && a	=> int &  a

	// reference confliction ��Ģ
	// & &		=> &
	// & &&		=> &
	// && &		=> &
	// && &&	=> &&

	cout << x << endl;
}
