// 3_함수객체 (17page)

#include <iostream>

using namespace std;

// 함수 객체 (Function Object, Functor): operator()를 재정의하여 함수처럼 사용이 가능한 객체
struct Plus
{
	int operator() (int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(1, 2);	// p.operator()(1, 2)
	cout << n << endl;

	// a + b;			// a.operator+(b)
	// a - b;			// a.operator-(b)
	// a();				// a.operator()()
	// a(1, 2);			// a.operator()(1, 2)
}