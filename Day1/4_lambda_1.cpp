// 4_lambda_1 (20page)

#include <iostream>
#include <algorithm>	// sort()
#include <functional>	// STL이 제공하는 함수 객체들

int main()
{
	int x[10] = { -1,3,5,-7,-9,2,4,-6,8,-10 };

	// incremental sort
	std::sort(x, x + 10);

	// decremental sort
	// STL이 제공하는 함수 객체 사용 - C++98 (1998년에 표준화 된 새로운 C++ 문법)
	std::greater<int> f;
	std::sort(x, x + 10, f);

	// 절대값 오름차순으로 정렬 - C++11 (2011년에 표준화 된 새로운 C++ 문법)
	// 람다 표현식 (Lambda Expression): 함수 구현을 함수 인자로 전달하는 기술
	// - []: introducer
	std::sort(x, x + 10, [](int a, int b) { return abs(a) < abs(b); });

	// 위 코드에 대해서 컴파일러는 다음과 같은 코드를 생성함 (표준)
	//---------------------------------------------------------------
	// Closure Object: 람다 표현식으로 만들어진 객체 (C++에서의 의미)
	class Closure_Object
	{
	public:
		inline auto operator()(int a, int b) const	// 인라인, 상수 함수로 만들어짐
		{
			return abs(a) < abs(b);
		}
	};
	Closure_Object cmp;
	std::sort(x, x + 10, cmp);
	//---------------------------------------------------------------

	for (auto n : x)
		std::cout << n << std::endl;
}