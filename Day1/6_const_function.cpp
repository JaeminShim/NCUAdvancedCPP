// <6> 상수함수 (65 page)

#include <iostream>

using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	void print() const
	{
		//x = 0;	// ERROR: 상수 함수에서는 모든 멤버를 상수 취급.
		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 2);	// 상수 객체를 생각해 봅시다.
	p.x = 10;				// ERROR: const 객체의 member variable
	p.set(10, 20);			// ERROR: const 객체의 non-const member function
	p.print();
}