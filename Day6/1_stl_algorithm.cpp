// 1. STL �˰��� - 170page

#include <iostream>
using namespace std;

// 1. C�� strchr()�Լ�

int main()
{
	char s[] = "abcdefg";

	char* p = strchr(s, 'c');

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}