// 6. 완벽한 전달자

#include <iostream>
using namespace std;

void foo(int) { cout << "foo" << endl; }
void goo(int& a) { cout << "goo" << endl; a = 20; }

// perfect forwarding이 되려면 rvalue, lvalue전달 및 return값 전달도 가능해야 함
template <typename F, typename A>
void logTime(F f, A a)
{
	// 시간 기록
	f(a);
	// 시간 측정후 출력
}

int main()
{
	int n = 10;
	logTime(foo, 10);
	logTime(goo, n);	// n은 goo로 인해 값이 변화해야 함

	cout << n << endl;
}