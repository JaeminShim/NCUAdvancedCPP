// 1. STL �˰��� 2 - 170page

// �Ϲ�ȭ ���α׷��� (Generic)
// : �ϳ��� �Լ�/Ŭ������ �ִ��� �پ��ϰ� Ȱ���� �� �ְ� �ϴ� ������ ���

#include <iostream>
using namespace std;

// 2. �κ� ���ڿ� �˻��� �����ϰ� ����. => �Ϲ�ȭ

char* xstrchr(char* first, char* last, char value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefg";

	char* p = xstrchr(s, s + 4, 'c');

	if (p == 0)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << *p << endl;
}