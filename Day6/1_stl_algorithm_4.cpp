// 1. STL 알고리즘 4 - 170page

#include <iostream>
using namespace std;

// 4. 더욱 일반화 하자.
// 아래 처럼 만들면 2가지의 문제가 있습니다. - 173page
// template <typename T> T* xfind(T* first, T* last, T value) { ... }
// 1) 찾는 구간의 타입과 요소의 타입이 연관됩니다.
//    double 배열에서 int를 찾을 수 없습니다.
// 2) T* 라고 적으면 반드시 진짜 포인터만 사용 가능합니다.
//    스마트 포인터를 사용할 수 없습니다.

// 아래 처럼 만들어야 합니다.
template <typename T, typename U> T xfind(T first, T last, U value)
{
	while (first != last && *first != value)
		++first;
	// return first == last ? 0 : first;	// 0은 T의 값으로 사용하기 어려워 짐
	return first;
}

int main()
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 15);

	//if (p == 0)
	if (p == x + 10)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}