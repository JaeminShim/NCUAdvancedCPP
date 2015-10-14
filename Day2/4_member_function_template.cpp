// 4. 멤버 함수 템플릿 - 81page

// 1. complex를 T로 만드는 이유 - double이면 될 것 같지만 double은 int 보다 느립니다.
// 2. T a = T() : zero initialize
//    T가 표준 타입이거나 포인터이면 0으로 초기화
//    T가 사용자 타입이면 티폴트 생성자로 초기화.
template<typename T>
class complex
{
	T re;
	T im;

public:
	complex(T a = T(), T b = T()) : re(a), im(b) {}	// zero initialize

	//// 복사 생성자
	//complex(const complex<T>& c);

	// 일반화 된 복사생성자 (82page)
	// "U가 T에 복사(대입)될 수 있다면 complex<U>는 complex<T>에 복사(대입)될 수 있어야 한다. (82page)"
	// - Effective C++ 3rd Ed.
	template<typename U>
	complex(const complex<U>& c);

	// 모든 complex 끼리는 private에 접근할 수 있어야 한다.
	template<typename>	// typename은 실제로 사용하지 않으므로 이름을 지정해 줄 필요는 없다.
	friend class complex;
};

// generic 복사 생성자의 외부 구현
template<typename T>
template<typename U>
complex<T>::complex(const complex<U>& c): re(c.re), im(c.im)	// 타 타입의 private 멤버에 접근!
{
}


int main()
{
	complex<int> c1(1, 3);		// OK

	complex<int> c2 = c1;		// ? => 복사 생성자(OK to create implicitly)

	complex<double> c3 = c1;	// ? => 복사 생성자(FAILED to create implicitly)
}