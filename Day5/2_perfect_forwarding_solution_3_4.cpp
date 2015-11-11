// 3. 완벽한 전달자 - 해결책 3-4 - 146page

#include <iostream>
using namespace std;

void f1() { cout << "f1" << endl; }
void f2(int a) { cout << "f2" << endl; }
void f3(int a, int& b, int&&) { cout << "f3" << endl; }

template <typename F, typename ... Types>
void logTime(F f, Types&& ... args)
{
	f(forward<Types>(args)...);	// forward<Types>(args...)이 아님에 유의
								// ...이 () 밖에 있어야 합니다.
								// * 마지막 날 설명
}

int main()
{
	int n = 10;

	logTime(f1);
	logTime(f2, 10);
	logTime(f3, 10, n, 10);
}
