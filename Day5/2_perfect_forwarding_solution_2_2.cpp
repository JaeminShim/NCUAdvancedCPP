// 2. 완벽한 전달자 - 해결책 2-2 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

// 참조로 변환 가능한 포인터 역할의 객체
template <typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& a) : obj(&a) {}
	// T&로 암시적 변환이 되게 하자.
	operator T&() { return *obj; }
};

int main()
{
	int x = 10;

	xreference_wrapper<int> r = x;	// x메모리를 가리키는 새로운 개념의 참조 r
	logTime(goo, r);

	cout << x << endl;
}
