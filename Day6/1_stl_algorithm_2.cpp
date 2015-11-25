// 1. STL 알고리즘 2 - 170page

// 일반화 프로그래밍 (Generic)
// : 하나의 함수/클래스를 최대한 다양하게 활용할 수 있게 하는 디자인 기법

#include <iostream>
using namespace std;

// 2. 부분 문자열 검색이 가능하게 하자. => 일반화

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
		cout << "찾을 수 없습니다." << endl;
	else
		cout << *p << endl;
}