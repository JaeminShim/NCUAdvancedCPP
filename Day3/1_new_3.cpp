// 1. new - 28 page

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// [B]
// 아래 함수를 잘 생각해 보세요 - 어렵습니다.
void* operator new(size_t sz, Point* p)
{
	return p;
}

// [C] - [B]의 범용 함수
// placement new (위치지정 new)
// 이미 존재하는 메모리의 생성자를 호출하기 위해 만든 operator new() (C++ 표준으로 구현되어 있음)
//void* operator new(size_t sz, void* p)
//{
//	return p;
//}

// [D] 결론
// malloc		: 메모리를 할당하는 코드
// new Point	: 새로운 메모리에 객체를 생성하는 코드 (메모리 할당 + 생성자 호출)
// new(p) Point	: 기존 메모리 p에 객체를 생성하는 코드 (생성자 호출)

// new는 메모리 할당이 아닌 객체의 생성입니다. (객체 생성의 의미)

int main()
{
	Point p(1, 2);

	// [B]
	// p 객체에 대하여 생성자를 다시 호출하는 코드
	new(&p) Point;	// operator new(size_t sz, Point* p) 호출

	// [A]
	// calling constructor/destructor explicitly
	// p.Point(0, 0);	// ERROR - 생성자의 명시적 호출	// 이게 이상함 (정상 처리에 문제가 있었다고 함)
	p.~Point();			// OK - 소멸자의 명시적 호출?		// 이게 정상
}