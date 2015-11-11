// 2. 완벽한 전달자의 필요성 - 142page

// [완벽한 전달자] Perfect forwarding
// : 함수에 대한 래퍼 함수를 만들 때 파라미터를 완벽하게 전달하는 기술
// ***매우 중요***

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

// 특정 함수의 성능을 측정할 수 있는 함수를 만들어 봅시다.
template <typename F, typename T> void logTime(F f, T a)
{
	// 시간 기록
	f(a); // 함수 호출
	// 다시 시간 측정 후 출력
}

int main()
{
	int x = 10;

	//foo(10);
	//goo(x);

	logTime(foo, 10);
	logTime(goo, x);

	cout << x << endl;
}
