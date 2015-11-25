// 5. traits - 99page

#include <iostream>
#include <type_traits>
using namespace std;

// 0, 1 등의 컴파일 시간 정수를 타입으로 만드는 도구
template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void printv_imp(T v, int2type<1>)
{
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_imp(T v, int2type<0>)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	printv_imp(v, int2type<is_pointer<T>::value>());
}

int main()
{
	int n = 10;
	printv(&n);
}
