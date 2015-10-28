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

	// 아래 복사 생성자를 잘 생각해 보세요. (const가 없습니다.) - 55 page 그림
	// => 소유권 이전의 복사 생성자 - STL의 auto_ptr<> 만들 때 사용한 기법
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
	Cat c2 = c1;	// c1의 자원은 c2로 이동된다.
}