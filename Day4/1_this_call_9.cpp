// 1. this call_9
// ���� ��Ӱ� this, ���� ��� Ŭ������ ��� �Լ� ������ - 13page

#include <iostream>
using namespace std;

class A
{
public:
	int a;
	void fa() { cout << this << endl; }
};

class B
{
public:
	int b;
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl;		// 100 ������� �� ��

	//---------------------------------------------
	void (C::*f)();	// ���� ��� Ŭ������ ��� �Լ� ������
					/// struct { func_address, this_offset } ����

	f = &C::fa;		// ȣ���ϸ� ����� 100
					/// { &fa, 0 }
	f = &C::fb;		// ȣ���ϸ� ����� 104
					/// { &fb, sizeof(A) }

	(ccc.*f)();		// ������ Ÿ�ӿ��� �� �� ����!
					/// f.func_address ( &ccc + f.this_offset )


	cout << sizeof(f) << endl;	// ���п� ���� ��� Ŭ������ ��� �Լ� �����ʹ� 8����Ʈ(!)
	void (A::*fa)();
	cout << sizeof(fa) << endl;	// cf. ���� ��� Ŭ������ �ƴ� ��� �Լ� �����ʹ� 4����Ʈ
}