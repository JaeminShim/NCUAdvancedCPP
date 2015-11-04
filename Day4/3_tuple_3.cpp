// 3. Tuple

#include <iostream>
using namespace std;

template<typename T, typename ... Types>
class xtuple : public xtuple<Types...>
{
public:
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) { }

	enum { N = 1 };	// 갯수 관리
};

// 인자가 1개인 tuple을 위한 부분 전문화
template<typename T>
class xtuple<T>
{
public:
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) { }

	enum { N = 1 };
};

int main()
{
	//부모:         xtuple<char>			// char만 보관		// 부분 전문화 버전 (부모 없음)
	//부모: xtuple<double, char>			// double만 보관
	xtuple<int, double, char> t3(1);	// int만 보관
}