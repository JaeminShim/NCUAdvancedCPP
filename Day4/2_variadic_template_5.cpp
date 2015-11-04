// 2. Variadic template - C++11/14 이야기

#include <iostream>
using namespace std;

// C++ 표준 라이브러리에 tuple이 생겼습니다. (2008년 경 부터)
#include <tuple>

int main()
{
	tuple<int, int, int> t3(1, 2, 3);
	tuple<int, int> t2(1, 2);

	// tuple에 넣고 꺼내기
	get<0>(t3) = 10;
	cout << get<0>(t3) << endl;
}
