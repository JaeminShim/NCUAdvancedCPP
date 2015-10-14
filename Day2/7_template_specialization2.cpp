// 7. 템플릿 전문화 2 - 메타 프로그래밍

#include <iostream>
using namespace std;

// Template meta programming : 컴파일 시간 재귀를 사용하여 연산을 수행하는 것.
//	"메타 함수"를 만들기
//	재귀의 종료를 위해 전문화 사용
//	C++11에서는 최소공배수, 최대공약수 등의 메타 함수를 지원

// [참고] 도서 <Template meta programming>

// 템플릿 인자로 타입 뿐 아니라 정수를 보낼 수 있습니다.
template<int N> struct factorial
{
	enum { value = N * factorial<N-1>:: value };
};

template<> struct factorial<1>
{
	enum { value = 1 };
};

int main()
{
	int n = factorial<5>::value;	// 잘 생각해 보세요.
	// = 5 * factorial<4>::value
	// = 5 * 4 * factorial<3>::value
	// = 5 * 4 * 3 * factorial<2>::value
	// = 5 * 4 * 3 * 2 * factorial<1>::value
	// = 5 * 4 * 3 * 2 * 1

	cout << n << endl;
}