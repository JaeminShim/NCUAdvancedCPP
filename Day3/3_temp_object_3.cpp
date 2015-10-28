// 3. 임시객체 - 35 page~
// 임시 객체와 함수 인자

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void foo(Point p)
{
}

int main()
{
	//{
	//	Point p;	// p는 단순히 아래 함수에 전달하기 위한 용도
	//	foo(p);
	//	// ...		// 아직 p 는 살아있음
	//}				// p 소멸

	foo(Point());	// 함수 인자로만 객체를 전달할때는 임시 객체를 많이 사용한다.
					// 2일차 소스 중 printv( a, int2type<>() );
}