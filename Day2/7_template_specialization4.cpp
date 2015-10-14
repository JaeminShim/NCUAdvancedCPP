// 7. 템플릿 전문화 4 - 91page

#include <iostream>
using namespace std;

template<typename T> void print(const T& a) { cout << T::N << endl; }

template <typename T, typename U> struct Duo
{
	T v1;
	U v2;
	enum { N = 2};
};

// 2번째 인자가 recursive Duo인 경우를 위한 부분 전문화
template <typename A, typename B, typename C> struct Duo<A, Duo<B, C>>
{
	A v1;
	Duo<B, C> v2;
	enum { N = 1 + Duo<B, C>::N };
};

// 1번째 인자가 recursive Duo인 경우를 위한 부분 전문화
template <typename A, typename B, typename C> struct Duo<Duo<A, B>, C>
{
	Duo<A, B> v1;
	C v2;
	enum { N = Duo<A, B>::N + 1 };
};

// 두 인자가 recursive Duo인 경우를 위한 부분 전문화
template <typename A, typename B, typename C, typename D> struct Duo<Duo<A, B>, Duo<C, D>>
{
	Duo<A, B> v1;
	Duo<C, D> v2;
	enum { N = Duo<A, B>::N + Duo<C, D>::N };
};

/*
int main()
{
	Duo<int, int> d2;
	Duo<int, Duo<int, int>> d3;
	Duo<int, Duo<int, Duo<int, int>>> d4;
	print(d2);
	print(d3);
	print(d4);
}
*/

/*
int main()
{
	Duo<Duo<int, int>, int> d3;
	Duo<Duo<Duo<int, int>, int>, int> d4;

	print(d3);
	print(d4);
}
*/

int main()
{
	Duo<Duo<int, int>, Duo<int, int>> d4;

	print(d4);
}
