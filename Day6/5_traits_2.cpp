// 5. traits - 99page

#include <iostream>
#include <type_traits>
using namespace std;

// int2type이 발전되어서 아래 템플릿이 C++11의 표준입니다.

template<typename T, T N> struct integral_constant
{
	static const T value = N;	// enum { value = N } 대신 static const 초기화 사용 (C++11)
};

/*
integral_constant<int,   0> n0;
integral_constant<short, 0> s0;

integral_constant<bool, true>  b1;
integral_constant<bool, false> b0;

// true, false: 참 거짓을 나타내는 값 (같은 타입)
// true_type, false_type: 참 거짓을 나타내는 타입 (다른 타입)
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// 이제는 is_pointer 만들 때 아래 처럼 합니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type  {};
*/


template<typename T> void printv_imp(T v, true_type)
{
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_imp(T v, false_type)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	printv_imp(v, is_pointer<T>());
}

int main()
{
	int n = 10;
	printv(&n);
}
