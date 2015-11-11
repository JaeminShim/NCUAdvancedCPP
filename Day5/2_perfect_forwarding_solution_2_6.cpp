// 2. 완벽한 전달자 - 해결책 2-6 - 145page
// bind 예제

#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;	// bind()의 _1, _2, ... 을 사용하기 위해서

void foo(int a, int &b, int c, int &d)
{
	cout << "foo" << "(" << a << ", " << b << ", " << c << ", " << d << ")" << endl;
	b = 20;
	d = 40;
}


int main()
{
	int x = 1, y = 1, z = 1;

	function<void(int, int)> f;

	// 인자 고정해보기
	f = bind(&foo, _2, ref(x), _1, ref(z));

	f(10, 20);	// foo(10, x, 20, z)로 전달되게 해보세요.

	cout << x << endl;
	cout << z << endl;
}
