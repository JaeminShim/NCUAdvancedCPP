// 2. 완벽한 전달자 - 예제 - 146page

#include <iostream>
#include <memory>
using namespace std;

/*
class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int main()
{
	// shared_ptr의 메모리 파편화 (객체 메모리 따로, ref_count 메모리 따로)

	shared_ptr<Point> p1(new Point(1, 1));	// 객체 메모리, 참조 계수용 메모리 따로 할당
	//shared_ptr<Point> p2 = p1;

	// 아래처럼 하면 sizeof(Point) + sizeof(참조계수) 변수 만큼 한 번에 메모리 할당 됩니다.
	shared_ptr<Point> p2 = make_shared<Point>(1, 2);
}
*/

#include <thread>		// C++11 스레드 

void foo(int a, int b, int c)
{
}

int main()
{
	thread t(&foo, 1, 2, 3);	// 이 순간 새로운 스레드가 생성되어 foo 실행

	t.join();					// 스레드 종료 대기
}
