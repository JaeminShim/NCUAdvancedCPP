// 8. Traits5 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

//-----------------------------------------------------------------------------
// 포인터인 경우와 그렇지 않은 경우로 함수 오버로딩 합니다.
template <typename T, typename U> void printv_imp(T v, U tf)
{
}

template <typename T> void printv_imp<>(T v, ? )
{
	cout << "Is a pointer" << endl;
	cout << v << " : " << *v << endl;
}

template <typename T> void printv_imp(T v, ? )
{
	cout << "Is NOT a pointer" << endl;
	cout << v << endl;
}

// 사용자가 사용하는 버전
template<typename T> void printv(T v)
{
	// 아래처럼 하면  if 문은 실행시간 동작하므로
	// 컴파일 시간에 int 버전에 대하여 위의 2개 함수를 모두 생성합니다.
	// 역시 컴파일 에러 발생
	/*
	if (IsPointer<T>::value)
		printv_imp(v, [포인터 버전]);
	else
		printv_imp(v, [포인터 아닌 버전]);
	*/

	// 아래처럼 어느 함수를 사용할지를 컴파일 시간에 결정해야 합니다. - 함수 오버로딩 필요
	printv_imp(v, [포인터인지 조사]);
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}