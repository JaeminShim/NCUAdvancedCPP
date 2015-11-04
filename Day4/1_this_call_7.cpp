// 1. this call_7
// 다중 상속과 this

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
	cout << &ccc << endl;		// 100 번지라고 할 때

	A* pA = &ccc;
	B* pB = &ccc;

	// 결과 예측
	cout << pA << endl;
	cout << pB << endl;
}