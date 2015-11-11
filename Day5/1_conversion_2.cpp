// 1. 변환 - 43page
// 변환 생성자


// D.
// 변환 연산자: Complex to int	사용자 정의 타입 => 기본 타입
// 변환 생성자: int to Complex	사용자 정의 타입 <= 기본 타입

// 1980년대 말 등장.
// 편리하지만 문제점도 발견됨.

#include <iostream>
using namespace std;

class Complex
{
	int re, im;
public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	operator int()
	{
		return re;
	}

	// C.
	// 인자가 한 개인 생성자: 다른 타입이 객체로 암시적 변환이 되도록 한다.
	//					   => 변환 생성자
	Complex(int a) : re(a), im(0) {}
};

int main()
{
	Complex c(1, 2);
	int n;

	// A.
	n = c;	// Complex to int: c.operator int()가 필요
	c = n;	// int to Complex: n.operator Complex()가 필요
			//				   하지만 n은 사용자 정의 타입이 아님

	// B.
	Complex c1;
	Complex c2(1, 2);
}