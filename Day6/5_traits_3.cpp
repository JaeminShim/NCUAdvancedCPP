// 5. traits 3

#include <iostream>
#include <type_traits>
using namespace std;

// T의 특성에 따라 알고리즘을 바꾸고 싶을 때.

void goo(true_type) { cout << "포인터 by goo" << endl; }
void goo(false_type) { cout << "포인터 아님 by goo" << endl; }

template<typename T> void foo(T a)
{
	// T가 포인터인지에 따라 코드를 변경하는 2가지 방법
	// 1. value 조사
	if (is_pointer<T>::value)
		cout << "포인터" << endl;
	else
		cout << "포인터 아님" << endl;

	// 2. 함수 오버로딩 사용
	goo(is_pointer<T>());
}

int main()
{
	int n = 10;
	foo(&n);
}
