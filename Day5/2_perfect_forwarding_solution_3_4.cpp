// 3. �Ϻ��� ������ - �ذ�å 3-4 - 146page

#include <iostream>
using namespace std;

void f1() { cout << "f1" << endl; }
void f2(int a) { cout << "f2" << endl; }
void f3(int a, int& b, int&&) { cout << "f3" << endl; }

template <typename F, typename ... Types>
void logTime(F f, Types&& ... args)
{
	f(forward<Types>(args)...);	// forward<Types>(args...)�� �ƴԿ� ����
								// ...�� () �ۿ� �־�� �մϴ�.
								// * ������ �� ����
}

int main()
{
	int n = 10;

	logTime(f1);
	logTime(f2, 10);
	logTime(f3, 10, n, 10);
}
