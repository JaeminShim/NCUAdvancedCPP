// 2. �Ϻ��� ������ - �ذ�å 2-2 - 145page

#include <iostream>
using namespace std;

void foo(int  n) { cout << "foo : " << n << endl; }
void goo(int &n) { cout << "goo : " << n << endl; n = 20; }

template <typename F, typename T> void logTime(F f, T a)
{
	f(a);
}

// ������ ��ȯ ������ ������ ������ ��ü
template <typename T> class xreference_wrapper
{
	T* obj;
public:
	xreference_wrapper(T& a) : obj(&a) {}
	// T&�� �Ͻ��� ��ȯ�� �ǰ� ����.
	operator T&() { return *obj; }
};

int main()
{
	int x = 10;

	xreference_wrapper<int> r = x;	// x�޸𸮸� ����Ű�� ���ο� ������ ���� r
	logTime(goo, r);

	cout << x << endl;
}
