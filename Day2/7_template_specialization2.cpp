// 7. ���ø� ����ȭ 2 - ��Ÿ ���α׷���

#include <iostream>
using namespace std;

// Template meta programming : ������ �ð� ��͸� ����Ͽ� ������ �����ϴ� ��.
//	"��Ÿ �Լ�"�� �����
//	����� ���Ḧ ���� ����ȭ ���
//	C++11������ �ּҰ����, �ִ����� ���� ��Ÿ �Լ��� ����

// [����] ���� <Template meta programming>

// ���ø� ���ڷ� Ÿ�� �� �ƴ϶� ������ ���� �� �ֽ��ϴ�.
template<int N> struct factorial
{
	enum { value = N * factorial<N-1>:: value };
};

template<> struct factorial<1>
{
	enum { value = 1 };
};

int main()
{
	int n = factorial<5>::value;	// �� ������ ������.
	// = 5 * factorial<4>::value
	// = 5 * 4 * factorial<3>::value
	// = 5 * 4 * 3 * factorial<2>::value
	// = 5 * 4 * 3 * 2 * factorial<1>::value
	// = 5 * 4 * 3 * 2 * 1

	cout << n << endl;
}