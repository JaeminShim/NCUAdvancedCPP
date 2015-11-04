// 1. this call

#include <iostream>
using namespace std;

class Point
{
	int x, y;

public:
	// A. 멤버 함수의 호출 원리 - 1번째 인자로 this가 추가된다.
	void set(int a, int b)	//	void set (Point* const this, int a, int b)
	{						//	{
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}						//	}

	// B. static 멤버 함수는 this가 추가되지 않는다.
	static void foo(int n)	//	void foo(int n)
	{						//	{
		x = n;				//		this->x = n;	// ERROR: this 가 없음
	}						//	}
};

int main()
{
	// A
	Point p1, p2;
	p1.set(10, 20);	// 이 순간의 원리를 정확히 생각해 봅시다.
					// => set(&p1, 10, 20)
					// 정확히는
					//	push	20
					//	push	10			// 진짜 인자들은 스택에 넣고
					//	mov		ecx, &p1	// 객체주소는 레지스터에 담아서
					//	call	set			// 함수 호출

	// B
	// static 멤버 함수는 객체 없이 호출 가능
	Point::foo(10);	// 인자로 추가할 객체가 없다.
}