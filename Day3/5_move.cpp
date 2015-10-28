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

	// 깊은 복사를 사용한 복사 생성자
	Cat(const Cat& c)
	{
		// 포인터가 아닌 멤버는 그냥 복사
		age = c.age;

		// 포인터는 깊은 복사
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// TODO - 대입연산자도 필요하다.
};

// Rule of three : 소멸자, 복사생성자, 대입연산자를 통칭
//				   생성자에서 자원을 할당하면 3개의 함수를 추가로 만들어야 한다.

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
}