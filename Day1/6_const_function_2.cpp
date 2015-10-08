// <6> 상수함수 - 2 (65 page)
// 상수 객체는 상수 함수만 호출할 수 있다.
// 멤버의 값을 변경하지 않은 모든 멤버 함수는 반드시 "상수 함수로 해야 한다".
// 함수 인자로 const T&로 객체를 받는 경우가 많다. 상수 함수만 호출할 수 있게 된다.

#include <iostream>

class Rect
{
	int x, y, w, h;
public:
	int GetArea() const
	{
		return w * h;
	}
};

// call by value 대신 const T& 가 좋다.
void foo(const Rect& r)
{
	int n = r.GetArea();
}

int main()
{
	Rect r;					// 초기화 했다고 가정하고

	int n = r.GetArea();	// OK: 아무 문제 없음

	foo(r);
}