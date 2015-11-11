// 2. 완벽한 전달자 - 해결책 2-5 - 145page
// 사용 예제

#include <iostream>
using namespace std;

void foo(int a)			{ cout << "foo" << endl; }
void goo(int a, int &b)	{ cout << "goo : " << a << ", " << b << endl; b = 100; }

// C++ 표준에는 모든 함수의 주소를 담을 수 있는 범용 함수 포인터가 있습니다.
#include <functional>
using namespace std::placeholders;	// bind()의 _1, _2, ... 을 사용하기 위해서

int main()
{
	function<void(int)> f;	// 모든 함수의 주소를 담을 수 있습니다.
	f = &foo;
	f(10);

	int x = 10;
	f = bind(&goo, _1, ref(x));		// goo의 1번째 인자는 f(인자)를 전달하고
								//       2번째 인자는 x로 고정
	f(10);	// goo(10, x);

	cout << x << endl;
}
