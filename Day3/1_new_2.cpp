// 1. new - 28 page

#include <iostream>
using namespace std;

// new가 내부적으로 메모리 할당할 때 사용하는 operator new()는 재정의 할 수 있습니다.
// (new keyword를 재정의 하는 것이 아님!!!)
// 즉, 메모리 할당 방식의 변경.

void* operator new(size_t sz)
{
	cout << "my new: " << sz << endl;
	void* p = malloc(sz);
	return p;
}

// operator new() overloading
void* operator new(size_t sz, char* s, int n)
{
	cout << "my new2: " << sz << endl;
	void* p = malloc(sz);
	return p;
}

void operator delete(void* p)
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	// calls new(sizeof(int))
	int* p = new int;
	delete p;

	// 인자가 2개 이상 있는 operator new()를 사용하는 법
	int* p2 = new("AA", 2) int;
	delete p2;
}