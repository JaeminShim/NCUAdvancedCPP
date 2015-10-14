// 8. Traits4 - 97page

#include <iostream>
using namespace std;

template <typename T> struct IsPointer		{ enum { value = false }; };
template <typename T> struct IsPointer<T*>	{ enum { value = true }; };

// print variable
template<typename T> void printv(T v)
{
	if (IsPointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	printv(n);	// ERROR -  T가 포인터가 아니므로 if()문이 false라서 실행되지는 않지만 컴파일은 진행.
				//         따라서 if()문 안의 *v 에서 에러가 발생.
	printv(&n);	// OK
}