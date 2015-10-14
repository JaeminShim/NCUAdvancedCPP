// 7. 템플릿 전문화 3 - 90page

#include <iostream>
using namespace std;

template<typename T> void print(const T& a)
{
	cout << T::N << endl;
}

// 서로 다른 타입 2개를 보관하는 구조체
template <typename T, typename U> struct Duo
{
	T v1;
	U v2;
	enum { N = 2};
};


int main()
{
	Duo<int, int> d2;
	print(d2);
}

// usage>
//typedef Duo<int, int> Point;
