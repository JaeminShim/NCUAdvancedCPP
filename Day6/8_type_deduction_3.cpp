// 8. type deduction 3

int main()
{
	int n = 10;
	int* p = &n;

	// A.
	decltype(n)  n2;	// typeof(n2) == int
	//decltype(*p) n3;	// typeof(n3) == int&
						// <= *p = 10 등의 표현이 가능하다. 따라서 * 연산자는 참조리턴한다.

	// B.
	const int cx = n;
	const int& rx = cx;

	auto a1 = rx;			// typeof(a1) == int
	decltype(rx) a2 = rx;	// typeof(a2) == const int&			// C++11
	decltype(auto) a3 = rx;	// 우변의 타입으로 a3를 만드는데,
							// 추론 규칙은 decltype() 규칙으로...	// C++14

	// <= (decltype(rx) a2 = rx; => rx가 중복해서 등장. decltype의 param 대신 auto 사용)
}