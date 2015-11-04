// 1. this call_2
// - ��� �Լ��� �Լ� ������

#include <iostream>
using namespace std;

// A. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
// B. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ���� �� �ִ�.
// C. ��� �Լ� �����͸� ����� ����ϴ� ��� - 6page
class Dialog
{
public:
	void Close() {}
};

void foo() {}

//int main()
//{
//	void(*f1)() = &foo;				// OK
//	void(*f2)() = &Dialog::Close;	// ERROR: this�� �߰��ȴ�! [A]
//}

int main()
{
	// [C] ��� �Լ� �����͸� ����� ����ϴ� ���

	// ��� �Լ��� �ּҸ� ��� ���
	void (Dialog::*f)() = &Dialog::Close;

	//f();			// ERROR: ���ڷ� �߰��� this�� ����!

	Dialog dlg;
	//dlg.f();		// �ᱹ dlg.Close();	// ERROR: ������ f�� Dialog�� �����Ƿ� ����.
	//dlg.*f();		// ".*" ������		// ERROR: ������ �켱���� ������ ����
	(dlg.*f)();		// OK
}
