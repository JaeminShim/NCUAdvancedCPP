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

	enum { N = 1 };	// ���� ����
};

// ���ڰ� 1���� tuple�� ���� �κ� ����ȭ
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
	//�θ�:         xtuple<char>			// char�� ����		// �κ� ����ȭ ���� (�θ� ����)
	//�θ�: xtuple<double, char>			// double�� ����
	xtuple<int, double, char> t3(1);	// int�� ����
}