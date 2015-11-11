// 2. �Ϻ��� ������ - �ذ�å 2-3 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

template <typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& a) : obj(&a) {}
	operator T&() { return *obj; }
};

// C.
// Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ����ؼ� �׻� ����� ���Դϴ�.
// �Ͻ��� �߷��� ������ �Լ� ���ø����� ���۸� ����� �������ϴ�.
template <typename T>
xreference_wrapper<T> xref(T& a)
{
	return xreference_wrapper<T>(a);
}

int main()
{
	int x = 10;

	//xreference_wrapper<int> r = x;
	//logTime(goo, r);

	// A.
	//// �Լ� ���ڷθ� ����Ҷ��� �ӽ� ��ü�� �����ص� �ȴ�.
	//logTime(goo, xreference_wrapper<int>(x));

	// C.
	// �Ʒ� �ڵ带 �� �����غ�����.
	logTime(goo, xref(x));

	cout << x << endl;
}

// B.
/*
template<typename T> T square(T a) { return a * a; }

// ���� �� ���� �ڵ��?
square(3);			// 1. �����Ϸ��� Ÿ�� �߷� - ���� ����
square<int>(3);		// 2. ����ڰ� Ÿ�� ���� - ����� ����

// �׷���...

list<int> s(3, 0);	// OK: 3���� 0���� �ʱ�ȭ
list s(3, 0);		// ERROR: Ŭ���� ���ø��� �Ͻ��� Ÿ�� �߷��� �Ұ���!
*/