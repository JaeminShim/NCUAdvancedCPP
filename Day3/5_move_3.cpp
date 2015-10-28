// 5. move
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

	// �Ҹ���
	~Cat() { delete[] name; }

	// ���� ������
	Cat(const Cat& c)
	{
		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// Cat(Cat& c) // �̷��� ����� Cat c2 = c1�� �� �Լ��� ȣ���Ѵ�!
	Cat(Cat&& c)
	{
		age = c.age;
		name = c.name;

		c.age = 0;
		c.name = 0;

		cout << "move" << endl;
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// �� �ڵ�� ����ó�� ��� ���� �����ڸ� ȣ���ؾ� ��
					// ������ Cat(Cat& c)�� �����Ѵٸ�,
					// Cat(const Cat& c)���ٴ� Cat(Cat& c)�� �켱�ؼ� ȣ���
					// ���� �̵������ڸ� Cat(Cat& c) ���·� ����� �ȵ�
	Cat c3 = static_cast<Cat&&>(c1);	// move�� ȣ���� �޶�
}