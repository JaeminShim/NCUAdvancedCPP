// 1. this call_7
// ���� ��Ӱ� this

#include <iostream>
using namespace std;

class A { public: int a; };
class B { public: int b; };
class C : public A, public B
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl;		// 100 ������� �� ��

	A* pA = &ccc;
	B* pB = &ccc;

	// ��� ����
	cout << pA << endl;
	cout << pB << endl;
}