// 1. this call

#include <iostream>
using namespace std;

class Point
{
	int x, y;

public:
	// A. ��� �Լ��� ȣ�� ���� - 1��° ���ڷ� this�� �߰��ȴ�.
	void set(int a, int b)	//	void set (Point* const this, int a, int b)
	{						//	{
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}						//	}

	// B. static ��� �Լ��� this�� �߰����� �ʴ´�.
	static void foo(int n)	//	void foo(int n)
	{						//	{
		x = n;				//		this->x = n;	// ERROR: this �� ����
	}						//	}
};

int main()
{
	// A
	Point p1, p2;
	p1.set(10, 20);	// �� ������ ������ ��Ȯ�� ������ ���ô�.
					// => set(&p1, 10, 20)
					// ��Ȯ����
					//	push	20
					//	push	10			// ��¥ ���ڵ��� ���ÿ� �ְ�
					//	mov		ecx, &p1	// ��ü�ּҴ� �������Ϳ� ��Ƽ�
					//	call	set			// �Լ� ȣ��

	// B
	// static ��� �Լ��� ��ü ���� ȣ�� ����
	Point::foo(10);	// ���ڷ� �߰��� ��ü�� ����.
}