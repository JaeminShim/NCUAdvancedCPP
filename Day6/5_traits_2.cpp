// 5. traits - 99page

#include <iostream>
#include <type_traits>
using namespace std;

// int2type�� �����Ǿ �Ʒ� ���ø��� C++11�� ǥ���Դϴ�.

template<typename T, T N> struct integral_constant
{
	static const T value = N;	// enum { value = N } ��� static const �ʱ�ȭ ��� (C++11)
};

/*
integral_constant<int,   0> n0;
integral_constant<short, 0> s0;

integral_constant<bool, true>  b1;
integral_constant<bool, false> b0;

// true, false: �� ������ ��Ÿ���� �� (���� Ÿ��)
// true_type, false_type: �� ������ ��Ÿ���� Ÿ�� (�ٸ� Ÿ��)
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// ������ is_pointer ���� �� �Ʒ� ó�� �մϴ�.
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