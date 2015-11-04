// 3. Tuple

#include <iostream>
using namespace std;

template<typename T, typename ... Types>
class xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> base;

public:
	T value;

	xtuple() {}
	xtuple(const T& a, const Types&... args) : base(args...), value(a) { }

	enum { N = base::N + 1 };	// 갯수 관리
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
	xtuple<int, double, char> t3(1, 2.2, 'a');

	cout << t3.N << endl;
}