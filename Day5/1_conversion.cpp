// 1. ��ȯ - 43page
// ��ȯ ������

#include <iostream>
using namespace std;

class Complex
{
	int re, im;
public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	// B.
	// ��ȯ ������ �Լ�: ��ü�� �ٸ� Ÿ������ �Ͻ��� ����ȯ �ǰ� �Ѵ�.
	//				   �Լ� �̸��� ����Ÿ���� �����Ƿ� ���� Ÿ���� ǥ���ϸ� �ȵȴ�.
	//int operator int()
	operator int()
	{
		return re;
	}
};

int main()
{
	double d = 3.4;
	int n = d;			// OK - ǥ�� Ÿ���� �Ͻ��� ����ȯ ����

	// A.
	Complex c(1, 2);
	int n2 = c;			// ERROR - c.operator int() �Լ��� ������ ����
}