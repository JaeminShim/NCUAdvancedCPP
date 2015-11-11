// 1. 변환 - 43page
// 변환 연산자

#include <iostream>
using namespace std;

class Complex
{
	int re, im;
public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	// B.
	// 변환 연산자 함수: 객체가 다른 타입으로 암시적 형변환 되게 한다.
	//				   함수 이름에 리턴타입이 있으므로 리턴 타입은 표시하면 안된다.
	//int operator int()
	operator int()
	{
		return re;
	}
};

int main()
{
	double d = 3.4;
	int n = d;			// OK - 표준 타입은 암시적 형변환 가능

	// A.
	Complex c(1, 2);
	int n2 = c;			// ERROR - c.operator int() 함수가 있으면 가능
}