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

	// 소멸자
	~Cat() { delete[] name; }

	// 복사 생성자
	Cat(const Cat& c)
	{
		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// Cat(Cat& c) // 이렇게 만들면 Cat c2 = c1이 이 함수를 호출한다!
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
	Cat c2 = c1;	// 이 코드는 과거처럼 계속 복사 생성자를 호출해야 함
					// 하지만 Cat(Cat& c)이 존재한다면,
					// Cat(const Cat& c)보다는 Cat(Cat& c)이 우선해서 호출됨
					// 따라서 이동생성자를 Cat(Cat& c) 형태로 만들면 안됨
	Cat c3 = static_cast<Cat&&>(c1);	// move를 호출해 달라
}