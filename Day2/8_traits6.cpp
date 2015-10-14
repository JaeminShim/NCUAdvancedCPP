// 8. Traits5 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

// 아래 템플릿을 잘 생각해 보세요. - 98page 위쪽 소스
// int를 타입처럼 사용하자! -> 컴파일 시간에 오버로딩하도록!
template <int N> struct int2type
{
	enum { value = N };
};

/*
int main()
{
	// 0, 1은 모두 int이기 때문에 둘 다 같은 함수를 호출
	foo(0);
	foo(1);

	int2type<0> t0;
	int2type<1> t1;

	// t0, t1은 서로 다른 타입이기 때문에 서로 다른 함수를 호출
	foo(t0);
	foo(t1);
}
*/

// 변수 이름을 사용하지 않으면 코드 생성하지 않음
template <typename T> void printv_imp(T v, int2type<1>)
{
	cout << "Is a pointer" << endl;
	cout << v << " : " << *v << endl;
}

template <typename T> void printv_imp(T v, int2type<0>)
{
	cout << "Is NOT a pointer" << endl;
	cout << v << endl;
}

// 사용자가 사용하는 버전
template<typename T> void printv(T v)
{
	// int2type<IsPointer<T>::value>는 타입!
	printv_imp(v, int2type<IsPointer<T>::value>());
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
