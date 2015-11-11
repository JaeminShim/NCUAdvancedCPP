// 2. 완벽한 전달자 - 해결책 2-3 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

template <typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& a) : obj(&a) {}
	operator T&() { return *obj; }
};

// C.
// 클래스 템플릿은 암시적 추론이 불가능해서 항상 어려어 보입니다.
// 암시적 추론이 가능한 함수 템플릿으로 헬퍼를 만들면 쉬워집니다.
template <typename T>
xreference_wrapper<T> xref(T& a)
{
	return xreference_wrapper<T>(a);
}

int main()
{
	int x = 10;

	//xreference_wrapper<int> r = x;
	//logTime(goo, r);

	// A.
	//// 함수 인자로만 사용할때는 임시 객체로 전달해도 된다.
	//logTime(goo, xreference_wrapper<int>(x));

	// C.
	// 아래 코드를 잘 생각해보세요.
	logTime(goo, xref(x));

	cout << x << endl;
}

// B.
/*
template<typename T> T square(T a) { return a * a; }

// 다음 중 쉬운 코드는?
square(3);			// 1. 컴파일러가 타입 추론 - 쉬워 보임
square<int>(3);		// 2. 사용자가 타입 전달 - 어려워 보임

// 그러면...

list<int> s(3, 0);	// OK: 3개를 0으로 초기화
list s(3, 0);		// ERROR: 클래스 템플릿은 암시적 타입 추론이 불가능!
*/