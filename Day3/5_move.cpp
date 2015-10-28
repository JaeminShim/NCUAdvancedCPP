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
	~Cat() { delete[] name; }

	// ���� ���縦 ����� ���� ������
	Cat(const Cat& c)
	{
		// �����Ͱ� �ƴ� ����� �׳� ����
		age = c.age;

		// �����ʹ� ���� ����
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// TODO - ���Կ����ڵ� �ʿ��ϴ�.
};

// Rule of three : �Ҹ���, ���������, ���Կ����ڸ� ��Ī
//				   �����ڿ��� �ڿ��� �Ҵ��ϸ� 3���� �Լ��� �߰��� ������ �Ѵ�.

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
}