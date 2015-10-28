// 3. 임시객체 - 35 page~
// 임시 객체와 함수 리턴

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
	Point(const Point& p) { cout << "Point() 복사생성자" << endl; }
};

// [A]
Point foo()
{
	// [C]
	// compile with "Release" configuration
	// NRVO (Named RVO)
	// 이름 있는 객체도 최적화 해 줄 수 있다는 기법
	// http://cafe.naver.com/cppmaster 의 <C++ Idioms>에서 NRVO 항목 참고. (원리 및 문제점에 대하여)
	// 모든 컴파일러가 NRVO를 지원하지는 않습니다.

	Point p;
	cout << "foo" << endl;
	return p;
}

//// [B]
//Point foo()
//{
//	cout << "foo" << endl;
//
//	// 임시객체를 사용한 리턴 - 리턴용 임시객체만 생성된다.
//	// RVO (Return Value Optimization)이라는 이름을 가진 기술
//	return Point();
//}

int main()
{
	Point p1;
	p1 = foo();
	cout << "end" << endl;

	// [A]
	// 결과예측
	// 1. Point() 생성자 - p1
	// 2. Point() 생성자 - p
	// 3. foo
	// 4. Point() 복사생성자 - foo 리턴
	// 5. 소멸자 - p
	// 6. 소멸자 - foo 리턴
	// 7. end
	// 8. 소멸자 - p1

	// [B]
	// 생성자와 소멸자 2회씩만 호출
}
