// 3. 임시객체 - 35 page~
// 전역 변수와 함수 리턴

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
};

Point p = { 1, 2 };

//// [A]
//Point foo()		// 값 리턴: 리턴용 임시객체를 생성
//{
//	return p;	// 전역객체 리턴 - 임시객체를 만들어서 리턴한다.
//}

// [B]
Point& foo()	// 참조 리턴: 리턴용 임시객체를 만들지 말라는 의미
{
	return p;
}

int main()
{
	foo().x = 10;	// [A] 가능??? - X (but OK in MSVC) - 임시객체의 값 변경 - primitive type을 생각해보자
					//				=> 임시 객체는 lvalue가 될 수 없다!
	cout << p.x << endl;
}