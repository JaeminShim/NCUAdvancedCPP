// 2. Trivial - 156 page
// (����: Inside C++ object å - 1996�� �Ⱓ)

#include <iostream>
using namespace std;

// trivial (�ڸ���) ������ : �ƹ� �ϵ� ���� �ʴ� ������

// trivial�� �������� ����
// 1. ���� �Լ��� ����
// 2. �θ� ���ų� �θ��� �����ڰ� trivial �ϰ�
// 3. ��ä�� ����� ���ų� ��ü�� ����� �����ڰ� trivial�ϰ�
// 4. ����ڰ� ���� �����ڰ� ���� ��

class A 
{
};

// [D]
//class B

class B : public A
{
public:
	virtual void foo() {}

	// [B]
	//virtual void foo() {}

	// [C]
	//A a;
};

int main()
{
	// [A] B�� �����ڴ� trivial �ұ��?
	B* p = static_cast<B*>(malloc(sizeof(B)));
	//p->foo();	// ERROR

	new (p) B;	// ������ ȣ�� -> vtable ����
	p->foo();	// OK

	// [B] �θ� ������ ȣ�� �ʿ��ϸ� non-trivial
	// [C] ��� ������ ȣ�� �ʿ��ϸ� non-trivial
	// [D] ������ �ʿ��ڵ� ������ trivial
}