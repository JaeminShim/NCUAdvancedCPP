// 1. ��ȯ - 43page
// ��ȯ ������


// D.
// ��ȯ ������: Complex to int	����� ���� Ÿ�� => �⺻ Ÿ��
// ��ȯ ������: int to Complex	����� ���� Ÿ�� <= �⺻ Ÿ��

// 1980��� �� ����.
// �������� �������� �߰ߵ�.

#include <iostream>
using namespace std;

class Complex
{
	int re, im;
public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	operator int()
	{
		return re;
	}

	// C.
	// ���ڰ� �� ���� ������: �ٸ� Ÿ���� ��ü�� �Ͻ��� ��ȯ�� �ǵ��� �Ѵ�.
	//					   => ��ȯ ������
	Complex(int a) : re(a), im(0) {}
};

int main()
{
	Complex c(1, 2);
	int n;

	// A.
	n = c;	// Complex to int: c.operator int()�� �ʿ�
	c = n;	// int to Complex: n.operator Complex()�� �ʿ�
			//				   ������ n�� ����� ���� Ÿ���� �ƴ�

	// B.
	Complex c1;
	Complex c2(1, 2);
}