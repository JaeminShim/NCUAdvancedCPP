// 2. 완벽한 전달자 - 해결책 - 144page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

// 해결책 1. 함수 오버로딩 사용 (참조와 상수 참조(또는 값))
// 문제점: 인자 N개를 perfect forwarding 하려면 2^N 개의 logTime()이 필요하다.
template <typename F, typename T> void logTime(F f, T& a)		// 1
{
	f(a);
}

template <typename F, typename T> void logTime(F f, const T& a)	// 2
{
	f(a);
}

int main()
{
	int x = 10;

	logTime(foo, 10);	// int&&가 있으면 호출, 없으면 2번 호출
	logTime(goo, x);	// int& 즉, 1번 호출, 없으면 2번 호출

	cout << x << endl;
}
