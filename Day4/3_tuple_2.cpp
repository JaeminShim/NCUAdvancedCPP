// 3. Tuple

#include <iostream>
using namespace std;

// 핵심: 1번째 인자는 가변인자가 아닌 개별 타입으로 받아야 한다.
template<typename T, typename ... Types> class xtuple
{
public:
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) {}

	enum { N = 1; };	// 갯수 관리
};

int main()
{
	xtuple<int, double, char> t3(1);	// (1, 2.2, 'A');
}