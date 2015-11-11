// 2. 완벽한 전달자 - 해결책 2-1 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

int main()
{
	int x = 10;

	//logTime(goo, x);	// x의 값이 전달된다. 변경하려면 메모리 정보가 전달되어야 함
	logTime(goo, &x);	// 주소를 보냈으므로 메모리 정보가 전달 됨
						// 포인터를 레퍼런스로 전달할 수 있기만 하면 됨

	cout << x << endl;
}
