// 6. begin 2 - 199page

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>
using namespace std;

// 일반함수 begin(), end()
/*	// 이미 존재함
// 컨테이너 버전
template<typename T> auto begin(T& c) { return c.begin(); }
template<typename T> auto end(T& c)   { return c.end(); }

// 배열 버전
template<typename T, int N> T* begin(T(&arr)[N]) { return arr; }
template<typename T, int N> T* end(T(&arr)[N])   { return arr + N; }
*/

template<typename T> void show(T& c)
{
	auto p = begin(c);
	while (p != end(c))
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	vector<int> v(x, x + 10);

	show(v);	// v의 모든 요소를 출력
	show(x);
}
