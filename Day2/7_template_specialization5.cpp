// 7. ���ø� ����ȭ 5 - 92page (Variadic ����� C++ ���� 114page)

#include <iostream>
using namespace std;

template <typename T, typename U> struct Duo
{
	T v1;
	U v2;
	enum { N = 2 };
};

//----------------------------------------------
struct Null {};	// empty class - ����� ���� Ÿ��.

template<typename P1 = Null,
		 typename P2 = Null,
		 typename P3 = Null,
		 typename P4 = Null,
		 typename P5 = Null>
class xtuple : public Duo<P1, xtuple<P2, P3, P4, P5>>
{
};

// xtuple�� ��ȿ�� Ÿ�� 2���� ���� ��
template<typename T, typename U>
class xtuple<T, U, Null, Null, Null> : public Duo<T, U>
{
};

// Duo, tuple�� ������ �ڵ�:
// [����] ���� <C++ Template Complete Guide>, 21��
int main()
{
	xtuple<int, char, short, long, double> t5;
	// == Duo<int, xtuple<char, short, long, double>>
	// == Duo<int, Duo<char, xtuple<short, long, double>>>
	// == Duo<int, Duo<char, Duo<short, xtuple<long, double>>>>
	// == Duo<int, Duo<char, Duo<short, Duo<long, double>>>>

	xtuple<int, int> t2;
}
