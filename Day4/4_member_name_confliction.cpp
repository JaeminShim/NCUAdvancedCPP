// 4. ��� �̸� �浹

#include <iostream>
using namespace std;

class Base1
{
public:
	int value;

	Base1() : value(1) {}
};

class Base2 : public Base1
{
public:
	int value;

	Base2() : value(2) {}
};

class CCC : public Base2
{
public:
	int value;
	CCC() : value(3) {}
};

int main()
{
	CCC c;
	cout << c.value << endl;			// �ڽ��� CCC�� value

	//cout << ((Base2)c).value << endl;	// Base2�κ��� ���� ���� value
	cout << ((Base2&)c).value << endl;	// Base2�κ��� ���� ���� value

	//cout << ((Base1)c).value << endl;	// Base1�κ��� ���� ���� value
	cout << ((Base1&)c).value << endl;	// Base1�κ��� ���� ���� value

	((Base1&)c).value = 10;				// ���� �������� (lvalue���� ��) ������ ĳ����


	//cout << c.Base2::value << endl;	// Base2�κ��� ���� ���� value
}

// �θ�� ������ �̸��� ������ ��� data�� ���� ��
// �θ� ����� �����Ϸ��� �θ�& Ÿ������ ��ü�� ĳ�����ؼ� ����ϸ� �ȴ�.
// �����Ϸ��� Ÿ���� ���� �˾Ƽ� �����ϰ� ���ش�.