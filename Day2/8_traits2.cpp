// 8. Traits2 - 96page

#include <iostream>
using namespace std;

//------------------------------------------------------
// Trait : T의 다양한 특성을 조사하는 메타함수
//------------------------------------------------------
// [만드는 법] (96page)
// - primary template: false 리턴 (value = false라는 의미)
// - 부분 전문화 버전: true 리턴
//------------------------------------------------------

// T가 포인터인지 조사하는 메타 함수
template <typename T> struct IsPointer
{
	enum { value = false };
};

template <typename T> struct IsPointer<T*>
{
	enum { value = true };
};

template <typename T> void foo(const T& a)
{
	if (IsPointer<T>::value)
		cout << "Is a pointer" << endl;
	else
		cout << "Is not a pointer" << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}