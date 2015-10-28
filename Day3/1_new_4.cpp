// 1. new - 28 page

// 왜 생성자를 명시적으로 호출하는가?
// 1. 편리하다
// 2. vector와 같은 효율적 메모리 관리
// 3. 고성능 generic 알고리즘 개발

#include <iostream>
#include <new> // placement new를 사용하기 위해
using namespace std;

class Point
{
	int x, y;

public:
	Point(int a, int b) {}
};

int main()
{
	// [A] Point를 힙에 하나 만들어 보세요
	auto p1 = new Point(1, 2);

	// [B] 힙에 Point를 10개를 만들어 보세요
	//Point* p2 = new Point[10];		// ERROR - 메모리 할당과 생성자 호출이 동시에 일어나기 때문
	//Point* p2 = new Point(1, 2)[10];	// ERROR - 생성자 지정 불가능
	Point* p2 = static_cast<Point*>(operator new (sizeof(Point) * 10));		// 메모리 할당
	// 할당된 메모리를 객체로 변경하기 위해 생성자 호출 - placement new 사용
	for (int i = 0; i < 10; ++i)
		new (&p2[i]) Point(1, 2);

	// [C] 스택에 Point를 10개를 만들어 보세요.
	char buf[sizeof(Point) * 10];
	Point* p3 = reinterpret_cast<Point*>(buf);
	for (int i = 0; i < 10; ++i)
		new (&p3[i]) Point(1, 2);
}