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

int main()
{
	// new 키워드의 정확한 동작 방식
	// A. operator new()라는 함수를 사용해서 메모리 할당
	// B. A가 성공하고 객체라면 생성자 호출
	// C. 메모리 주소를 해당 타입으로 캐스팅하여 리턴.
	//Point* p = new Point;
	//delete p;

	// 생성자 호출 없이 메모리만 할당하는 방법 (operator new() 사용)
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);	// 소멸자 호출 없음
}