// 1. template_basic - 74page

/// original code
/*
int		square(int a)		{ return a * a; }
double	square(double a)	{ return a * a; }
*/

///--------------------------------------------
/// 유사한 코드가 반복된다면 코드 생성기를 사용하자
///--------------------------------------------

// 1. 매크로
//  => 코드 생성을 전처리기가 하게 된다.
//     전처리기는 타입을 알지 못하기 때문에 어떤 타입의 square()가 필요한지 사용자가 알려주어야 한다.
/*
#define MAKE_SQUARE(T) T square(T a) { return a * a; }

MAKE_SQUARE(int)
MAKE_SQUARE(double)
*/

// 2. 컴파일러에 의한 코드 생성기술 - 템플릿
//  => 컴파일러는 타입을 알고 있다. 소스를 분석해서
//     어떤 타입의 함수가 필요한지를 조사하고 자동으로 해당 타입의 함수를 생성한다.
//     MAKE_SQUARE(int) 가 필요없다.
// * Straustroup: "컴파일 타임에 전처리기의 코드 생성을 하고 싶었다."
template<typename T> T square(T a) { return a * a; }

///--------------------------------------------
/// 용어정리 (76page)
///--------------------------------------------
// 템플릿 인스턴스화: T의 타입이 결정되어서 진짜 함수를 만드는 과정
// 암시적 인스턴스화: 컴파일러가 T의 타입을 결정
// 명시적 인스턴스화: 사용자가 T의 타입을 결정
// Code Bloat: template이 너무 많은 타입으로 인스턴스화 되어서 코드 메모리가 증가하는 현상!
//             (임베디드 환경에서 주의)

int main()
{
	square(3);
	square(3.3);

	short s = 3;
	square(s);	// 1. square(short) 버전 생성 (O) - code bloat의 위험
				// 2. square(int) 버전 사용 (X)

	// 명시적 추론
	square<int>(s);	// square(int) 버전 사용
}
