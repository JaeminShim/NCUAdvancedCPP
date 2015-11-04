// 3. Tuple

#include <iostream>
using namespace std;

// �ٽ�: 1��° ���ڴ� �������ڰ� �ƴ� ���� Ÿ������ �޾ƾ� �Ѵ�.
template<typename T, typename ... Types> class xtuple
{
public:
	T value;

	xtuple() {}
	xtuple(const T& a) : value(a) {}

	enum { N = 1; };	// ���� ����
};

int main()
{
	xtuple<int, double, char> t3(1);	// (1, 2.2, 'A');
}