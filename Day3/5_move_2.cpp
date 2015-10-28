// 5. move - 55 page
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cat
{
	char*	name;
	int		age;
public:
	Cat(char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~Cat() { delete[] name; }

	// �Ʒ� ���� �����ڸ� �� ������ ������. (const�� �����ϴ�.) - 55 page �׸�
	// => ������ ������ ���� ������ - STL�� auto_ptr<> ���� �� ����� ���
	Cat(Cat& c)
	{
		// shallow copy
		age = c.age;
		name = c.name;

		c.age = 0;
		c.name = 0;
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// c1�� �ڿ��� c2�� �̵��ȴ�.
}