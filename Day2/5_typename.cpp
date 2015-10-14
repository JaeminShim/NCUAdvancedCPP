// 5. Typename

class AAA
{
public:
	//......
	//static int DWORD;	// 1)
	typedef int DWORD;	// 2)
};

int p = 0;

// 템플릿(T)에 의존적인 타입을 꺼낼 때에는 반드시 typename을 앞에 적어야 한다.

template <typename T>
typename T::DWORD foo(T a)
{
	// 아래 한 줄을 해석해 보세요
	// 1) DWORD는 static 멤버변수인데 p(전역변수)와 곱셈하고 있다. [!!!표준 C++의 기본 가정!!!]
	// 2) DWORD는 T안에 있는 typedef된 타입이다. 포인터 변수 p를 선언하고 있다.
	T::DWORD* p;			// ERROR - 표준 C++ (VC는 정상 컴파일)
	typename T::DWORD* p;	// OK - 2)번과 같이 가정하게 함	[!!!typename의 탄생 배경!!!]
	return 0;
}

int main()
{
	AAA aaa;
	foo(aaa);
}