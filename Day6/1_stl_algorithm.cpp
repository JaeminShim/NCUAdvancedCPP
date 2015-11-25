// 1. STL 알고리즘 - 170page

#include <iostream>
using namespace std;

// 1. C의 strchr()함수

int main()
{
	char s[] = "abcdefg";

	char* p = strchr(s, 'c');

	if (p == 0)
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}