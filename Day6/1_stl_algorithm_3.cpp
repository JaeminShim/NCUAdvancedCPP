// 1. STL 알고리즘 3 - 170page

#include <iostream>
using namespace std;

// 3. 모든 타입의 배열을 검색 가능하게 하자. => template 도입

template <typename T>
T* xfind(T* first, T* last, T value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10 };
	double* p = xfind(x, x + 10, 5.0);

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}