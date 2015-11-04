// 4. 멤버 이름 충돌

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
	cout << c.value << endl;			// 자신인 CCC의 value

	//cout << ((Base2)c).value << endl;	// Base2로부터 물려 받은 value
	cout << ((Base2&)c).value << endl;	// Base2로부터 물려 받은 value

	//cout << ((Base1)c).value << endl;	// Base1로부터 물려 받은 value
	cout << ((Base1&)c).value << endl;	// Base1로부터 물려 받은 value

	((Base1&)c).value = 10;				// 값을 넣으려면 (lvalue여야 함) 참조로 캐스팅


	//cout << c.Base2::value << endl;	// Base2로부터 물려 받은 value
}

// 부모와 동일한 이름을 가지는 멤버 data가 있을 때
// 부모 멤버를 접근하려면 부모& 타입으로 객체를 캐스팅해서 사용하면 된다.
// 컴파일러가 타입을 보고 알아서 접근하게 해준다.